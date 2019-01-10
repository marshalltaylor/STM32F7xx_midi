#ifndef HAL_UART_H
#define HAL_UART_H

#include "hal_main.h"
#include "stm32f4xx_hal.h"

#define TX_BUFFER_SIZE 256
#define RX_BUFFER_SIZE 256

typedef struct UartInstance
{
	UART_HandleTypeDef* huart;
	DMA_HandleTypeDef* hdma_rx;
	DMA_HandleTypeDef* hdma_tx;

	bool UartTxInProgress;

	uint8_t txDataBuffer[TX_BUFFER_SIZE+10];
	int16_t txDataBuffer_head;
	int16_t txDataBuffer_next;
	int16_t txDataBuffer_tail;

	uint8_t rxCharBuffer;
	uint8_t rxDataBuffer[RX_BUFFER_SIZE+10];
	int16_t rxDataBuffer_first;
	int16_t rxDataBuffer_last;
} UartInstance_t;

#ifdef __cplusplus
 extern "C" {
#endif

void MX_USART6_UART_Init(void);
void halUartWrite(uint8_t data, UartInstance_t * UART);
uint8_t halUartPeek(UartInstance_t * UART);
uint8_t halUartRead(UartInstance_t * UART);
uint16_t halUartReadBytesAvailable(UartInstance_t * UART);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif