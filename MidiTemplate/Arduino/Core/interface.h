#ifndef INTERFACE_H
#define INTERFACE_H

#include "stm32f7xx_hal.h"
#include "hal_main.h"
#include "hal_uart.h"
#include "HardwareSerial.h"

//#include "stm32f7xx.h"
//#include "stm32f7xx_it.h"
//#include "stm32f7xx_hal_uart.h"

extern HardwareSerial Serial1;
extern HardwareSerial Serial6;

void interface_init(void);
void delay(uint32_t delayInput);

#endif