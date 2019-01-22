#ifndef MIDITIME_H
#define MIDITIME_H
#include <stdio.h>

class MidiClock
{
public:
	MidiClock(void);
	void incrementTick(void);
	void play(void);
	void resume(void);
	void stop(void);
	bool isTickSubDiv( uint32_t inputTicks, int8_t inputSubDiv );
	uint32_t ticksToQuarterNotes( uint32_t inputTicks );
	uint32_t ticksToMeasures( uint32_t inputTicks );
	void processCallbacks( void );	
	uint32_t ticks;
	bool isPlaying;
};
#endif
