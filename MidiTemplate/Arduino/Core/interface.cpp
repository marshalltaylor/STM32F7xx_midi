#include <stdio.h>
//#include "stm32f7xx_hal.h"
#include "hal_main.h"
#include "HardwareSerial.h"
#include "interface.h"

/* Private variables ---------------------------------------------------------*/
extern UartInstance_t VCP_UART;
extern UartInstance_t D01_UART;

HardwareSerial Serial1;
HardwareSerial Serial6;

/* Private function prototypes -----------------------------------------------*/

/* Functions -----------------------------------------------------------------*/
void interface_init(void)
{
	Serial1.init(&VCP_UART);
	Serial6.init(&D01_UART);
}

void delay(uint32_t delayInput)
{
	uint32_t targetTicks = millis() + delayInput; //OK for this to roll
	while(millis() > targetTicks)
	{
		//if we rolled, wait until millis rolls
	}
	while(millis() < targetTicks)
	{
		//nop
	}
}