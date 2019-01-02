#include "STM_ArduinoPins.h"
#include <stdint.h>
#include "stm32f7xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif
//int  var[3] = {10, 100, 200};
// Pin number
//char * sdfsdfsdDToPort[4] = {
////	GPIOJ,
////	GPIOJ
//};

//usage: ex: GPIOD expansion:
//(GPIO_TypeDef *) (AHB1PERIPH_BASE + DxToPort[3])
const uint32_t DxToPort[] = {
	PORTC_OFFSET,
	PORTC_OFFSET,
	PORTJ_OFFSET,
	PORTF_OFFSET,
	PORTJ_OFFSET,
	PORTC_OFFSET,
	PORTF_OFFSET,
	PORTJ_OFFSET,
	PORTJ_OFFSET,
	PORTH_OFFSET,
	PORTA_OFFSET,
	PORTB_OFFSET,
	PORTB_OFFSET,
	PORTA_OFFSET,
	PORTB_OFFSET,
	PORTB_OFFSET,
	PORTA_OFFSET,
	PORTA_OFFSET,
	PORTC_OFFSET,
	PORTF_OFFSET,
	PORTF_OFFSET,
	PORTF_OFFSET,
	PORTI_OFFSET,
	PORTB_OFFSET,
	PORTA_OFFSET,
	PORTC_OFFSET,
	PORTJ_OFFSET,
	PORTJ_OFFSET,
	PORTA_OFFSET
};

const uint32_t DxToPin[] = {
	GPIO_PIN_7,  
	GPIO_PIN_6,  
	GPIO_PIN_1,  
	GPIO_PIN_6,  
	GPIO_PIN_0,  
	GPIO_PIN_8,  
	GPIO_PIN_7,  
	GPIO_PIN_3,  
	GPIO_PIN_4,  
	GPIO_PIN_6,  
	GPIO_PIN_11, 
	GPIO_PIN_15, 
	GPIO_PIN_14, 
	GPIO_PIN_12, 
	GPIO_PIN_9,  
	GPIO_PIN_8,  
	GPIO_PIN_6,  
	GPIO_PIN_4,  
	GPIO_PIN_2,  
	GPIO_PIN_10, 
	GPIO_PIN_8,  
	GPIO_PIN_9,  
	GPIO_PIN_11, 
	GPIO_PIN_7,  
	GPIO_PIN_9,  
	GPIO_PIN_13, 
	GPIO_PIN_13, 
	GPIO_PIN_5,  
	GPIO_PIN_0   
};
//  PC_7,  //D0
//  PC_6,  //D1
//  PJ_1,  //D2
//  PF_6,  //D3
//  PJ_0,  //D4
//  PC_8,  //D5
//  PF_7,  //D6
//  PJ_3,  //D7
//  PJ_4,  //D8
//  PH_6,  //D9
//  PA_11, //D10
//  PB_15, //D11
//  PB_14, //D12
//  PA_12, //D13
//  PB_9,  //D14
//  PB_8,  //D15
//  PA_6,  //D16/A0
//  PA_4,  //D17/A1
//  PC_2,  //D18/A2
//  PF_10, //D19/A3
//  PF_8,  //D20/A4
//  PF_9,  //D21/A5
//  PI_11, //D22 User btn
//  PB_7,  //D23 ST-Link Rx
//  PA_9,  //D24 ST-Link Tx
//  PC_13, //D25 SD detect
//  PJ_13, //D26 USER LED 1
//  PJ_5,  //D27 USER LED 2
//  PA_0   //D28 USER BTN 1
//};

#ifdef __cplusplus
}
#endif
