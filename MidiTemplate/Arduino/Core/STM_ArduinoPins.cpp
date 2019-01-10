#include "STM_ArduinoPins.h"
#include <stdint.h>
#include "stm32f4xx_hal.h"

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
	PORTA_OFFSET,   //D0
	PORTA_OFFSET,   //D1
	PORTA_OFFSET,   //D2
	PORTB_OFFSET,   //D3
	PORTB_OFFSET,   //D4
	PORTB_OFFSET,   //D5
	PORTB_OFFSET,   //D6
	PORTA_OFFSET,   //D7
	PORTA_OFFSET,   //D8
	PORTC_OFFSET,   //D9
	PORTB_OFFSET,   //D10
	PORTA_OFFSET,   //D11
	PORTA_OFFSET,   //D12
	PORTA_OFFSET,   //D13
	PORTB_OFFSET,   //D14 SDA
	PORTB_OFFSET,   //D15 SCL
	PORTA_OFFSET,   //D16/A0
	PORTA_OFFSET,   //D17/A1
	PORTA_OFFSET,   //D18/A2
	PORTB_OFFSET,   //D19/A3
	PORTC_OFFSET,   //D20/A4
	PORTC_OFFSET,   //D21/A5
	PORTC_OFFSET,   //D22 User btn
	PORTB_OFFSET,   //D23 ST-Link Rx
	PORTA_OFFSET,   //D24 ST-Link Tx
	PORTC_OFFSET,   //D25 SD detect
	PORTJ_OFFSET,   //D26
	PORTJ_OFFSET,   //D27
	PORTA_OFFSET    //D28
};

const uint32_t DxToPin[] = {
	GPIO_PIN_3,    //D0
	GPIO_PIN_2,    //D1
	GPIO_PIN_10,   //D2
	GPIO_PIN_3,    //D3
	GPIO_PIN_5,    //D4
	GPIO_PIN_4,    //D5
	GPIO_PIN_10,   //D6
	GPIO_PIN_8,    //D7
	GPIO_PIN_9,    //D8
	GPIO_PIN_7,    //D9
	GPIO_PIN_6,    //D10
	GPIO_PIN_7,    //D11
	GPIO_PIN_6,    //D12
	GPIO_PIN_5,    //D13
	GPIO_PIN_9,    //D14 SDA
	GPIO_PIN_8,    //D15 SCL
	GPIO_PIN_0,    //D16/A0
	GPIO_PIN_1,    //D17/A1
	GPIO_PIN_4,    //D18/A2
	GPIO_PIN_0,    //D19/A3
	GPIO_PIN_2,    //D20/A4
	GPIO_PIN_3,    //D21/A5
	GPIO_PIN_13,   //D22 User btn
	GPIO_PIN_7,    //D23 ST-Link Rx
	GPIO_PIN_9,    //D24 ST-Link Tx
	GPIO_PIN_13,   //D25 SD detect
	GPIO_PIN_13,   //D26
	GPIO_PIN_5,    //D27
	GPIO_PIN_0     //D28
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
//  PJ_13, //D26
//  PJ_5,  //D27
//  PA_0   //D28
//};

#ifdef __cplusplus
}
#endif
