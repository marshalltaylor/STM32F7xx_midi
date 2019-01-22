#include "hal_main.h"
#include "stm32f4xx_hal.h"
//#include "stm32f7xx.h"
//#include "stm32f7xx_it.h"
#include "Arduino.h"
#include "sketch.h"

int main()
{
	// STM-like init
	hal_main();

	// Arduino (serial objects) init
	interface_init();
	
	// sketch.ino
	setup();

	while(1)
	{
		loop();
	}
}
