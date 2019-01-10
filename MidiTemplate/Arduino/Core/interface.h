#ifndef INTERFACE_H
#define INTERFACE_H

#include "stm32f4xx_hal.h"
#include "hal_main.h"
#include "hal_uart.h"
#include "HardwareSerial.h"

extern HardwareSerial Serial2;
extern HardwareSerial Serial6;

void interface_init(void);
void delay(uint32_t delayInput);

#endif