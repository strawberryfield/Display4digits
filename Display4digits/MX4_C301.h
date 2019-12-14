// MX4_C301.h

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
	char display[DISPLAY_SIZE];
	uint8_t dots;
	uint8_t brightness;

	void init();
	void init_timer();
	void refresh();
	void writeDigit(uint8_t picture);
	void writeChar(char digit);
};

extern MX4_C301Class MX4_C301;

#endif

