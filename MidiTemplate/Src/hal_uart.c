#include <stdint.h>
#include <stdbool.h>
#include "hal_main.h"
#include "stm32f7xx_hal.h"
#include "usb_device.h"


UART_HandleTypeDef huart6;
DMA_HandleTypeDef hdma_usart6_rx;
DMA_HandleTypeDef hdma_usart6_tx;

bool UartTxInProgress = false;

#define TX_BUFFER_SIZE 256
#define RX_BUFFER_SIZE 256

uint8_t txDataBuffer[TX_BUFFER_SIZE+10];
int16_t txDataBuffer_head;
int16_t txDataBuffer_next;
int16_t txDataBuffer_tail;

uint8_t rxCharBuffer;
uint8_t rxDataBuffer[RX_BUFFER_SIZE+10];
int16_t rxDataBuffer_first;
int16_t rxDataBuffer_last;

void MX_USART6_UART_Init(void)
{
  txDataBuffer_head = 0;
  txDataBuffer_next = 0;
  txDataBuffer_tail = 0;

  rxDataBuffer_first = 0;
  rxDataBuffer_last = 0;
  rxDataBuffer[0] = 0;
  
  UartTxInProgress = false;
  
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 115200;
  huart6.Init.WordLength = UART_WORDLENGTH_8B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_NONE;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  huart6.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart6.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
  //if(HAL_UART_Transmit_DMA(&huart6, myData, sizeof(myData))!= HAL_OK)
  //{
  //////  BlinkErrorCode(250);
  //}
  //UartTxInProgress = false;
  HAL_UART_Receive_DMA(&huart6, &rxCharBuffer, 1);
}

static void uartQueueNextData(void)
{
	int16_t length;
	if(UartTxInProgress == false)
	{
		length = txDataBuffer_tail - txDataBuffer_head;
		if(length <= 0)
		{
			length = TX_BUFFER_SIZE - txDataBuffer_head;
			txDataBuffer_next = 0;
			UartTxInProgress = true;
			HAL_UART_Transmit_DMA(&huart6, txDataBuffer + txDataBuffer_head, length);
		}
		else if(length > 0)
		{
			txDataBuffer_next = txDataBuffer_tail;
			UartTxInProgress = true;
			HAL_UART_Transmit_DMA(&huart6, txDataBuffer + txDataBuffer_head, length);
		}			
	}
}

uint8_t uartPeek(void)
{
	return rxDataBuffer[rxDataBuffer_first];
}

void uartWrite(uint8_t data)
{
	txDataBuffer[txDataBuffer_tail] = data;
	txDataBuffer_tail++;
	if( txDataBuffer_tail >= TX_BUFFER_SIZE )
	{
		txDataBuffer_tail = 0;
	}
	if( txDataBuffer_tail == txDataBuffer_head )
	{
		txDataBuffer_tail--;
		if( txDataBuffer_tail < 0 )
		{
			txDataBuffer_tail = TX_BUFFER_SIZE - 1;
		}
	}
	uartQueueNextData();
}

uint8_t uartRead(void)
{
	uint8_t c = uartPeek();
	if(rxDataBuffer_first != rxDataBuffer_last)
	{
		rxDataBuffer_first++;
		if( rxDataBuffer_first >= RX_BUFFER_SIZE )
		{
			rxDataBuffer_first = 0;
		}
	}
	return c;
}

uint16_t uartReadBytesAvailable(void)
{
	uint16_t var = rxDataBuffer_last - rxDataBuffer_first;
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
  /* Set transmission flag: trasfer complete*/
  UartTxInProgress = false;
  txDataBuffer_head = txDataBuffer_next;
  if(txDataBuffer_next != txDataBuffer_tail)
  {
	  uartQueueNextData();
  }
  //BlinkErrorCode(500);
  
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
	rxDataBuffer[rxDataBuffer_last] = rxCharBuffer;
	rxDataBuffer_last++;
	if( rxDataBuffer_last >= RX_BUFFER_SIZE )
	{
		rxDataBuffer_last = 0;
	}
	//Queue another rx transfer
	HAL_UART_Receive_DMA(&huart6, &rxCharBuffer, 1);
  
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
    Error_Handler();
	//BlinkErrorCode(10);
}
