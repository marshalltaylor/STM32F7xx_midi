#include <stdio.h>
//#include "stm32f7xx_hal.h"
#include "hal_main.h"
#include "interface.h"

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Functions -----------------------------------------------------------------*/
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