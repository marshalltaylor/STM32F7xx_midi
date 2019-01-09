#include "Arduino.h"
#include "BlinkerPanel.h"
#include "sketch.h"

BlinkerPanel myCustomPanel;

uint16_t debugCounter = 0;

extern void setup()
{
	Serial.begin(9600);
	delay(2000);
	Serial.println("OK");
	//Go to fresh state
	myCustomPanel.reset();
	
}

//Set LOOP_DELAY to length of time between ticks of everything (in ms)
#define LOOP_DELAY 10

extern void loop()
{
	//Tick the machine
	myCustomPanel.tickStateMachine(LOOP_DELAY);
	
	//Delay the loop
	delay(LOOP_DELAY);
	
	//Increment a counter for debug stuff
	debugCounter = debugCounter + LOOP_DELAY;
	if( debugCounter > 1000 )
	{
		//Do debug stuff
		Serial.print("State: ");
		Serial.println(myCustomPanel.getState()); 
		//Serial.print("Free ram: ");
		debugCounter = 0;
	}
	
}

