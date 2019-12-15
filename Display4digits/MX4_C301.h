// copyright (c) 2019 Roberto Ceccarelli - Casasoft
// http://strawberryfield.altervista.org 
// 
// This is free software: 
// you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with these files.  
// If not, see <http://www.gnu.org/licenses/>.

#ifndef _MX4_C301_h
#define _MX4_C301_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

// Wiring
// Display segments are arranged in a way that allow port write
// Pin  2: Segment C
// Pin  3: Segment D
// Pin  4: Segment E
// Pin  5: Segment F
// Pin  6: Segment G
// Pin  7:  *Free, future use*
// Pin  8: Segment A
// Pin  9: Segment B

// Pin 10: Master brightness
// Pin 11: Enable dots (in pwm)
// Pin 12: Enable digit 1
// Pin A1: Enable digit 2
// Pin A2: Enable digit 3
// Pin A3: Enable digit 4

#define DISPLAY_SIZE 4
#define DMASK B01111100
#define BMASK B00000011

class MX4_C301Class
{
protected:
	uint8_t active;
	uint8_t cathodes[DISPLAY_SIZE + 1] = {
		12, PIN_A1, PIN_A2, PIN_A3, 11
	};
	uint8_t blink_status[DISPLAY_SIZE + 1];
	int blink_counter = 0;
	void blinking();

	uint8_t charmap[16] = {
		B00111111,  //0
		B00000110,	//1
		B01011011,	//2
		B01001111,	//3
		B01100110,	//4
		B01101101,	//5
		B01111101,	//6
		B00000111,	//7
		B01111111,	//8
		B01101111,	//9
		B01110111,  //A
		B01111100,	//b
		B00111001,	//C
		B01011110,	//d
		B01111001,	//E
		B01110001	//F
	};

public:
	char display[DISPLAY_SIZE];			// Display storage area
	uint8_t dots;						// Dots storage area
	uint8_t blink[DISPLAY_SIZE + 1];	// Blink flags
	int blink_speed = 125;				// default(125): 2Hz
	uint8_t brightness = 255;			// default(255): Full light  (not yet implemented)

	void init();
	void init_timer();
	void refresh();
	void writeDigit(uint8_t picture);
	void writeChar(char digit);
	void writeDigit(uint8_t picture, uint8_t blink_mask);
	void writeChar(char digit, uint8_t blink_mask);
};

extern MX4_C301Class MX4_C301;

#endif

