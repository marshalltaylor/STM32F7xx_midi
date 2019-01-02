/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ARDUINO_STM32_
#define _VARIANT_ARDUINO_STM32_
#include <stdint.h>
/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus
//class bobert{
//	bobert() { return 5;};
//	uint8_t somedumbbyte = 4;
//	const uint32_t * asdfasdfasdf[] = {
//		(uint32_t *)0
//	};
//};
//extern const uint32_t DToPort;
//extern const uint32_t DToPin;
/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
//extern const PinName digitalPin[];

#define PORTA_OFFSET 0x0000U
#define PORTB_OFFSET 0x0400U
#define PORTC_OFFSET 0x0800U
#define PORTD_OFFSET 0x0C00U
#define PORTE_OFFSET 0x1000U
#define PORTF_OFFSET 0x1400U
#define PORTG_OFFSET 0x1800U
#define PORTH_OFFSET 0x1C00U
#define PORTI_OFFSET 0x2000U
#define PORTJ_OFFSET 0x2400U
#define PORTK_OFFSET 0x2800U







//#define PC7  0
//#define PC6  1
//#define PJ1  2
//#define PF6  3
//#define PJ0  4
//#define PC8  5
//#define PF7  6
//#define PJ3  7
//#define PJ4  8
//#define PH6  9
//#define PA11 10
//#define PB15 11
//#define PB14 12
//#define PA12 13
//#define PB9  14
//#define PB8  15
//#define PA6  16 // A0
//#define PF4  17 // A1
//#define PC2  18 // A2
//#define PF10 19 // A3
//#define PF8  20 // A4
//#define PF9  21 // A5
//#define PI11 22 // User btn
//#define PB7  23 // ST-Link Rx
//#define PA9  24 // ST-Link Tx
//#define PC13 25 // SD detect
//#define PJ13 26
//#define PJ5  27
//#define PA0  28

#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define D8 8
#define D9 9
#define D10 10
#define D11 11
#define D12 12
#define D13 13
#define D14 14
#define D15 15
#define D16 16 // A0
#define D17 17 // A1
#define D18 18 // A2
#define D19 19 // A3
#define D20 20 // A4
#define D21 21 // A5
#define D22 22 // User btn
#define D23 23 // ST-Link Rx
#define D24 24 // ST-Link Tx
#define D25 25 // SD detect
#define D26 26
#define D27 27
#define D28 28

#ifdef __cplusplus
}
#endif

#endif /* _VARIANT_ARDUINO_STM32_ */
