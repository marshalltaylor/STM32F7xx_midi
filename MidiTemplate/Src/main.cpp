#include "hal_main.h"
#include "stm32f7xx_hal.h"
//#include "stm32f7xx.h"
#include "stm32f7xx_it.h"
#include "Arduino.h"

#define Serial Serial1

int main()
{
	hal_main();
	//HAL_GPIO_TogglePin(GPIOJ, GPIO_PIN_13);
	pinMode(D13, OUTPUT);
	
	/* Infinite loop */
	while(1)
	{
		digitalWrite(D13, 1);
		delay(1000);
		digitalWrite(D13, 0);
		delay(1000);
		Serial.print(millis(), DEC);
		//Serial.println(5398, DEC);
		Serial.println(": hello!");
		//Serial.println("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer a convallis nibh. Ut faucibus eu purus a viverra. Donec et dapibus ante. Proin laoreet malesuada mauris et dictum. Aliquam in ipsum nulla. Fusce consectetur enim enim, et bibendum elit congue sed. Morbi mi quam, efficitur a varius vel, suscipit eu augue. Curabitur ultricies erat at mi tincidunt tempus eget vitae mauris. Proin congue tincidunt justo, vitae mattis purus elementum eu. In non lacus ipsum. Proin euismod finibus magna, ut porttitor lacus hendrerit sed.");
		//Serial.println("0000111122223333444455556666777788889999AAAABBBBCCCCDDDDEEEEFFFF");
	}
}

