//Header
#ifndef SYSTEMPANEL_H_INCLUDED
#define SYSTEMPANEL_H_INCLUDED

#include "Panel.h"
#include "PanelComponents.h"
#include "HardwareInterfaces.h"
#include <Arduino.h>

enum PStates
{
	PInit,
	POn,
	PFlash,
	PFastFlash
};

class BlinkerPanel : public Panel
{
public:
	BlinkerPanel( void );
	void reset( void );
	void tickStateMachine( int msTicksDelta );
	uint8_t getState( void ){
		return (uint8_t)state;
	}
	
private:
	//Internal Panel Components
	Button button1;
	Button button2;
	Button button3;
	Button button4;
	Button buttonSelect;
	Button play;
	Button stop;
	Led led1;
	Led led2;
	Led led3;
	Led led4;
	Led ledPlay;
	
	Windowed10BitKnob knob1;
	Windowed10BitKnob knob3;
	Windowed10BitKnob knobTempo;

	//  ..and data
	uint8_t held;
	
	//State machine stuff  
	PStates state;

};

#endif