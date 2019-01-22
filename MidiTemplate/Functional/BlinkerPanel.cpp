//********************************************//
#include "BlinkerPanel.h"
#include "panelComponents.h"
#include "HardwareInterfaces.h"
#include <Arduino.h>
#include "midiTime.h"
#include "display_clock.h"

extern MidiClock myMidiClock;

BlinkerPanel::BlinkerPanel( void )
{
	buttonSelect.setHardware(new ArduinoDigitalIn( D24 ), 1);
	add( &buttonSelect );
	button4.setHardware(new ArduinoDigitalIn( D25 ), 1);
	add( &button4 );
	button3.setHardware(new ArduinoDigitalIn( D26 ), 1);
	add( &button3 );
	button2.setHardware(new ArduinoDigitalIn( D27 ), 1);
	add( &button2 );
	button1.setHardware(new ArduinoDigitalIn( D28 ), 1);
	add( &button1 );
	stop.setHardware(new ArduinoDigitalIn( D29 ), 1);
	add( &stop );
	play.setHardware(new ArduinoDigitalIn( D30 ), 1);
	add( &play );

	led1.setHardware(new ArduinoDigitalOut( D32 ), 1);
	add( &led1 );
	led2.setHardware(new ArduinoDigitalOut( D31 ), 1);
	add( &led2 );
	led3.setHardware(new ArduinoDigitalOut( D33 ), 1);
	add( &led3 );
	led4.setHardware(new ArduinoDigitalOut( D10 ), 1);
	add( &led4 );
	ledPlay.setHardware(new ArduinoDigitalOut( D34 ), 1);
	add( &ledPlay );
	
	state = PInit;
	held = 0;
}

void BlinkerPanel::reset( void )
{
	//Set explicit states
	//Set all LED off
	led1.setState(LEDOFF);
	led2.setState(LEDOFF);
	led3.setState(LEDOFF);
	led4.setState(LEDOFF);
	state = PInit;
	held = 0;
	
}

void BlinkerPanel::tickStateMachine( int msTicksDelta )
{
	freshenComponents( msTicksDelta );
	
	//***** PROCESS THE LOGIC *****//
	//Now do the states.
	PStates nextState = state;
	switch( state )
	{
	case PInit:
		//Can't be running, if button pressed move on
		break;
	default:
		nextState = PInit;
		break;
	}
	state = nextState;

	if( button1.serviceRisingEdge() )
	{
		Serial6.println("Button1");
		led1.toggle();
		
		char buffer[3];
		sprintf( buffer, "%3d", 1 );
		displayDrawValue(buffer);
		displayTransmitFrame();
	}
	if( button2.serviceRisingEdge() )
	{
		Serial6.println("Button2");
		led2.toggle();

		char buffer[3];
		sprintf( buffer, "%3d", 20 );
		displayDrawValue(buffer);
		displayTransmitFrame();
	}
	if( button3.serviceRisingEdge() )
	{
		Serial6.println("Button3");
		led3.toggle();
		
		char buffer[3];
		sprintf( buffer, "%3d", 300 );
		displayDrawValue(buffer);
		displayTransmitFrame();

	}
	if( button4.serviceRisingEdge() )
	{
		Serial6.println("Button4");
		led4.toggle();
	}
	if( buttonSelect.serviceRisingEdge() )
	{
		Serial6.println("Select");
	}
	if( play.serviceRisingEdge() )
	{
		Serial6.println("play");
	}
	if( stop.serviceRisingEdge() )
	{
		Serial6.println("stop");
	}
	
	if( myMidiClock.isPlaying )
	{
		ledPlay.setState(LEDON);
	}
	else
	{
		ledPlay.setState(LEDOFF);
	}
	char buffer[3];
	sprintf( buffer, "%3d", 666 );
	//displayDrawValue(buffer);
	//displayTransmitFrame();
}
