#ifndef DISPLAY_CLOCK_H
#define DISPLAY_CLOCK_H

#ifdef __cplusplus
 extern "C" {
#endif
	void displayDrawClockNums( const char * input );
	void displayDrawValue( const char * input );
	void toggleClockColon(void);
	void displayTransmitFrame(void);
	void setPlayIndicator(void);
	void clearPlayIndicator(void);
#ifdef __cplusplus
 }
#endif

#endif