#include "Arduino.h"
#include "BlinkerPanel.h"
#include "sketch.h"

BlinkerPanel myCustomPanel;

uint16_t debugCounter = 0;

extern void setup()
{
	Serial2.begin(9600, 6);
	Serial6.begin(12345, 1);
	delay(2000);
	Serial2.println("OK");
	Serial6.println("OK");
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
		Serial2.print("State: ");
		Serial2.println(myCustomPanel.getState()); 
		Serial6.print("State: ");
		Serial6.println(myCustomPanel.getState()); 
		
		debugCounter = 0;
	}
	
}

