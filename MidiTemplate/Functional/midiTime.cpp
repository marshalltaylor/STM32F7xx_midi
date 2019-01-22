#include <stdio.h>
#include "display_clock.h"
#include "midiTime.h"
#include "interface.h"

MidiClock::MidiClock(void)
{
	ticks = 0;
	isPlaying = false;
}

void MidiClock::incrementTick(void)
{
	ticks++;
	processCallbacks();
}

void MidiClock::play(void)
{
	ticks = 0;
	isPlaying = true;
	setPlayIndicator();
	processCallbacks();
}

void MidiClock::resume(void)
{
	ticks = 0; //TODO: This should be optional
	isPlaying = true;
	setPlayIndicator();
	displayTransmitFrame();
}

void MidiClock::stop(void)
{
	clearPlayIndicator();
	displayTransmitFrame();
	isPlaying = false;
}

bool MidiClock::isTickSubDiv( uint32_t inputTicks, int8_t inputSubDiv )
{
	bool retVar;
	int16_t ticksPerBeat;
	switch (inputSubDiv)
	{
		case -2: // 4 bar
		ticksPerBeat = 384;
		break;
		case -1: // measure/whole
		ticksPerBeat = 96;
		break;
		case 0: // quarter
		ticksPerBeat = 24;
		break;
		case 1: // 8th
		ticksPerBeat = 12;
		break;
		case 2: // 16th
		ticksPerBeat = 6;
		break;
		case 3: // 32nd
		ticksPerBeat = 3;
		break;
		default:
		break;
	}
	retVar = !(inputTicks % ticksPerBeat);
	return retVar;
}

uint32_t MidiClock::ticksToQuarterNotes( uint32_t inputTicks )
{
	uint32_t retVar = 0;
	retVar = ((inputTicks / 24) % 4) + 1;
	return retVar;
}

uint32_t MidiClock::ticksToMeasures( uint32_t inputTicks )
{
	uint32_t retVar = 0;
	retVar = ((inputTicks / 96) % 4) + 1;
	return retVar;
}

void MidiClock::processCallbacks( void )
{
	if( isTickSubDiv(ticks, -2) )
	{
		//Callbacks
		Serial6.print("|     ");
		Serial6.print("  Playing: ");
		Serial6.print(isPlaying);
		Serial6.print("  Ticks: ");
		Serial6.println(ticks);

	}
	if( isTickSubDiv(ticks, -1) )
	{
		//Callbacks
		Serial6.println(" O");
	}
	if( isTickSubDiv(ticks, 0) )
	{
		//Callbacks
		char buffer[4];
		sprintf( buffer, "%2d%2d", ticksToMeasures(ticks), ticksToQuarterNotes(ticks) );
		displayDrawClockNums(buffer);
		toggleClockColon();
		displayTransmitFrame();
		Serial6.println("  *");

	}
	if( isTickSubDiv(ticks, 1) )
	{
		//Callbacks
		
	}
	if( isTickSubDiv(ticks, 2) )
	{
		//Callbacks
	}
	if( isTickSubDiv(ticks, 3) )
	{
		//Callbacks
	}
	
}