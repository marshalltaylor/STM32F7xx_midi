#include "hal_main.h"
#include "stm32f7xx_hal.h"
//#include "stm32f7xx.h"
#include "stm32f7xx_it.h"
#include "Arduino.h"
#include "sketch.h"

int main()
{
	hal_main();
	
	setup();

	while(1)
	{
		loop();
	}
}
