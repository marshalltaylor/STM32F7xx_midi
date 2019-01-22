#include <stdint.h>
#include <stdbool.h>
#include "hal_main.h"
#include "stm32f4xx_hal.h"

#include "display_clock.h"

extern DMA_HandleTypeDef hdma_spi1_tx;
extern SPI_HandleTypeDef hspi1;

static uint8_t serialBuffer[11] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

// 0 - 9, ?, ?
static uint8_t segmentMap[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x98, 0xFF, 0xFF};

void displayDrawClockNums( const char * input )
{
	for( int i = 0; i < 4; i++ )
	{
		serialBuffer[i + 7] = 0xFF;
		if((*(input + i) >= 0x30)&&(*(input + i) < 0x3A))
		{
			serialBuffer[i + 7] = segmentMap[*(input + i) - 0x30];
		}
	}
}

void displayDrawValue( const char * input )
{
	for( int i = 0; i < 3; i++ )
	{
		serialBuffer[i + 2] = 0xFF;
		if((*(input + i) >= 0x30)&&(*(input + i) < 0x3A))
		{
			serialBuffer[i + 2] = segmentMap[*(input + i) - 0x30];
		}
	}
}

void setPlayIndicator( void )
{
	serialBuffer[0] |= 0x80;
}

void clearPlayIndicator( void )
{
	serialBuffer[0] &= ~0x80;
}

void toggleClockColon(void)
{
	serialBuffer[0] ^= 0x08;
}

void displayTransmitFrame(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
	int time = millis();
	while(millis() < time + 1){};

	HAL_SPI_Transmit(&hspi1, serialBuffer, 11, 5000);

	time = millis();
	while(millis() < time + 1){};
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
	time = millis();
	while(millis() < time + 1){};
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
}