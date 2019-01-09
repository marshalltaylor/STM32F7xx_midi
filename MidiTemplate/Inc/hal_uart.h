#ifndef HAL_UART_H
#define HAL_UART_H

#ifdef __cplusplus
 extern "C" {
#endif

void MX_USART6_UART_Init(void);
void uartWrite(uint8_t data);
uint8_t uartPeek(void);
uint8_t uartRead(void);
uint16_t uartReadBytesAvailable(void);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif