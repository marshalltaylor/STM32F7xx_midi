#include "Arduino.h"
#include "BlinkerPanel.h"
#include "sketch.h"
#include <MIDI.h>

MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI);

BlinkerPanel myCustomPanel;

uint16_t debugCounter = 0;

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
	digitalWrite(D6, 0);
	Serial6.print("pitch: ");
	Serial6.println(pitch);
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
	digitalWrite(D6, 1);
}

extern void setup()
{
	pinMode(D6, OUTPUT);
	Serial2.begin(9600, 6);
	Serial6.begin(12345, 1);
	delay(2000);
	//Serial2.println("ok");
	Serial6.println("OK");
	//Go to fresh state
	myCustomPanel.reset();
	
	MIDI.setHandleNoteOn(handleNoteOn);  // Put only the name of the function
    MIDI.setHandleNoteOff(handleNoteOff);
    MIDI.begin(MIDI_CHANNEL_OMNI);
	
}

//Set LOOP_DELAY to length of time between ticks of everything (in ms)
#define LOOP_DELAY 10

extern void loop()
{
	MIDI.read();
	
	//Tick the machine
	myCustomPanel.tickStateMachine(LOOP_DELAY);
	
	//Delay the loop
	delay(LOOP_DELAY);
	
	//Increment a counter for debug stuff
	debugCounter = debugCounter + LOOP_DELAY;
	if( debugCounter > 1000 )
	{
		//Do debug stuff
		//Serial2.print("sta: ");
		//Serial2.println(myCustomPanel.getState()); 
		Serial6.print("State: ");
		Serial6.println(myCustomPanel.getState());
		
		debugCounter = 0;
	}
	
}

