#include <stdint.h>
#include <stdbool.h>
#include "hal_main.h"
#include "stm32f4xx_hal.h"
#include "hal_uart.h"

UART_HandleTypeDef huart6;
DMA_HandleTypeDef hdma_usart6_rx;
DMA_HandleTypeDef hdma_usart6_tx;

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;

UartInstance_t VCP_UART;
UartInstance_t D01_UART;

void MX_USART2_UART_Init(void)
{
  D01_UART.huart = &huart2;
  D01_UART.hdma_rx = &hdma_usart2_rx;
  D01_UART.hdma_tx = &hdma_usart2_tx;
  
  D01_UART.txDataBuffer_head = 0;
  D01_UART.txDataBuffer_next = 0;
  D01_UART.txDataBuffer_tail = 0;

  D01_UART.rxDataBuffer_first = 0;
  D01_UART.rxDataBuffer_last = 0;
  D01_UART.rxDataBuffer[0] = 0;
  
  D01_UART.UartTxInProgress = false;
  
  D01_UART.huart->Instance = USART2;
  D01_UART.huart->Init.BaudRate = 31250;
  D01_UART.huart->Init.WordLength = UART_WORDLENGTH_8B;
  D01_UART.huart->Init.StopBits = UART_STOPBITS_1;
  D01_UART.huart->Init.Parity = UART_PARITY_NONE;
  D01_UART.huart->Init.Mode = UART_MODE_TX_RX;
  D01_UART.huart->Init.HwFlowCtl = UART_HWCONTROL_NONE;
  D01_UART.huart->Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(D01_UART.huart) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
  HAL_UART_Receive_DMA(D01_UART.huart, &D01_UART.rxCharBuffer, 1);
}

void MX_USART6_UART_Init(void)
{
  VCP_UART.huart = &huart6;
  VCP_UART.hdma_rx = &hdma_usart6_rx;
  VCP_UART.hdma_tx = &hdma_usart6_tx;
  
  VCP_UART.txDataBuffer_head = 0;
  VCP_UART.txDataBuffer_next = 0;
  VCP_UART.txDataBuffer_tail = 0;

  VCP_UART.rxDataBuffer_first = 0;
  VCP_UART.rxDataBuffer_last = 0;
  VCP_UART.rxDataBuffer[0] = 0;
  
  VCP_UART.UartTxInProgress = false;
  
  VCP_UART.huart->Instance = USART6;
  VCP_UART.huart->Init.BaudRate = 115200;
  VCP_UART.huart->Init.WordLength = UART_WORDLENGTH_8B;
  VCP_UART.huart->Init.StopBits = UART_STOPBITS_1;
  VCP_UART.huart->Init.Parity = UART_PARITY_NONE;
  VCP_UART.huart->Init.Mode = UART_MODE_TX_RX;
  VCP_UART.huart->Init.HwFlowCtl = UART_HWCONTROL_NONE;
  VCP_UART.huart->Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(VCP_UART.huart) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
  HAL_UART_Receive_DMA(VCP_UART.huart, &VCP_UART.rxCharBuffer, 1);
}

static void uartQueueNextData(UartInstance_t * UART)
{
	int16_t length;
	if(UART->UartTxInProgress == false)
	{
		length = UART->txDataBuffer_tail - UART->txDataBuffer_head;
		if(length <= 0)
		{
			length = TX_BUFFER_SIZE - UART->txDataBuffer_head;
			UART->txDataBuffer_next = 0;
			UART->UartTxInProgress = true;
			HAL_UART_Transmit_DMA(UART->huart, UART->txDataBuffer + UART->txDataBuffer_head, length);
		}
		else if(length > 0)
		{
			UART->txDataBuffer_next = UART->txDataBuffer_tail;
			UART->UartTxInProgress = true;
			HAL_UART_Transmit_DMA(UART->huart, UART->txDataBuffer + UART->txDataBuffer_head, length);
		}			
	}
}

uint8_t halUartPeek(UartInstance_t * UART)
{
	return UART->rxDataBuffer[UART->rxDataBuffer_first];
}

void halUartWrite(uint8_t data, UartInstance_t * UART)
{
	while(UART->UartTxInProgress == true);
	UART->txDataBuffer[UART->txDataBuffer_tail] = data;
	UART->txDataBuffer_tail++;
	if( UART->txDataBuffer_tail >= TX_BUFFER_SIZE )
	{
		UART->txDataBuffer_tail = 0;
	}
	if( UART->txDataBuffer_tail == UART->txDataBuffer_head )
	{
		UART->txDataBuffer_tail--;
		if( UART->txDataBuffer_tail < 0 )
		{
			UART->txDataBuffer_tail = TX_BUFFER_SIZE - 1;
		}
	}
	uartQueueNextData(UART);
}

uint8_t halUartRead(UartInstance_t * UART)
{
	uint8_t c = halUartPeek(UART);
	if(UART->rxDataBuffer_first != UART->rxDataBuffer_last)
	{
		UART->rxDataBuffer_first++;
		if( UART->rxDataBuffer_first >= RX_BUFFER_SIZE )
		{
			UART->rxDataBuffer_first = 0;
		}
	}
	return c;
}

uint16_t halUartReadBytesAvailable(UartInstance_t * UART)
{
	uint16_t var = UART->rxDataBuffer_last - UART->rxDataBuffer_first;
	if( var < 0 )
	{
		var += RX_BUFFER_SIZE;
	}
	return var;
}
/**
  * @brief  Tx Transfer completed callback
  * @param  UartHandle: UART handle. 
  * @note   This example shows a simple way to report end of DMA Tx transfer, and 
  *         you can add your own implementation. 
  * @retval None
  */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle)
{
  if(UartHandle->Instance==USART2)
  {
    /* Set transmission flag: trasfer complete*/
    D01_UART.UartTxInProgress = false;
    D01_UART.txDataBuffer_head = D01_UART.txDataBuffer_next;
    if(D01_UART.txDataBuffer_next != D01_UART.txDataBuffer_tail)
    {
	    uartQueueNextData(&D01_UART);
    }
  }
  else if(UartHandle->Instance==USART6)
  {
    /* Set transmission flag: trasfer complete*/
    VCP_UART.UartTxInProgress = false;
    VCP_UART.txDataBuffer_head = VCP_UART.txDataBuffer_next;
    if(VCP_UART.txDataBuffer_next != VCP_UART.txDataBuffer_tail)
    {
	    uartQueueNextData(&VCP_UART);
    }
  }
 
}

/**
  * @brief  Rx Transfer completed callback
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report end of DMA Rx transfer, and 
  *         you can add your own implementation.
  * @retval None
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
  if(UartHandle->Instance==USART2)
  {
	D01_UART.rxDataBuffer[D01_UART.rxDataBuffer_last] = D01_UART.rxCharBuffer;
	D01_UART.rxDataBuffer_last++;
	if( D01_UART.rxDataBuffer_last >= RX_BUFFER_SIZE )
	{
		D01_UART.rxDataBuffer_last = 0;
	}
	//Queue another rx transfer
	HAL_UART_Receive_DMA(&huart2, &D01_UART.rxCharBuffer, 1);
  }
  else if(UartHandle->Instance==USART6)
  {
	VCP_UART.rxDataBuffer[VCP_UART.rxDataBuffer_last] = VCP_UART.rxCharBuffer;
	halUartWrite(VCP_UART.rxCharBuffer,&VCP_UART); //echo
	VCP_UART.rxDataBuffer_last++;
	if( VCP_UART.rxDataBuffer_last >= RX_BUFFER_SIZE )
	{
		VCP_UART.rxDataBuffer_last = 0;
	}
	//Queue another rx transfer
	HAL_UART_Receive_DMA(&huart6, &VCP_UART.rxCharBuffer, 1);
  }  
}

/**
  * @brief  UART error callbacks
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report transfer error, and you can
  *         add your own implementation.
  * @retval None
  */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *UartHandle)
{
    //Error_Handler();
	if(UartHandle->ErrorCode == HAL_UART_ERROR_DMA)
	{
		//Whatev's, kick it with a fresh buffer
		if(UartHandle->Instance==USART2)
		{
			while(1);
			//Queue another rx transfer
			HAL_UART_Receive_DMA(&huart2, &D01_UART.rxCharBuffer, 1);
		}
		else if(UartHandle->Instance==USART6)
		{
			while(1);
			//Queue another rx transfer
			HAL_UART_Receive_DMA(&huart6, &VCP_UART.rxCharBuffer, 1);
		}
		UartHandle->ErrorCode &= ~HAL_UART_ERROR_DMA;
	}
}
