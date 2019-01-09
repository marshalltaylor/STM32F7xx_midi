#ifndef __UART_H
#define __UART_H

/* Includes ------------------------------------------------------------------*/

#ifdef __cplusplus
 extern "C" {
#endif

/* Exported types ------------------------------------------------------------*/
typedef struct serial_s serial_t;
#define PinName int
#define SERIAL_8N1 8

struct serial_s {
  //USART_TypeDef *uart;
  //UART_HandleTypeDef handle;
  uint8_t index;
  uint8_t recv;
  uint32_t baudrate;
  uint32_t databits;
  uint32_t stopbits;
  uint32_t parity;
  PinName pin_tx;
  PinName pin_rx;
  //IRQn_Type irq;
  uint8_t *rx_buff;
  volatile uint16_t rx_head;
  uint16_t rx_tail;
  uint8_t *tx_buff;
  uint16_t tx_head;
  volatile uint16_t tx_tail;
};

#ifdef __cplusplus
}
#endif

#endif /* __UART_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
