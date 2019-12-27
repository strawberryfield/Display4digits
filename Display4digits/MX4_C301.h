/// @file 
/// Display manager class definition.
///
/// @author
/// copyright (c) 2019 Roberto Ceccarelli - Casasoft  
/// http://strawberryfield.altervista.org 
/// 
/// @copyright
/// This is free software: 
/// you can redistribute it and/or modify it
/// under the terms of the GNU General Public License as published by
/// the Free Software Foundation, either version 3 of the License, or
/// (at your option) any later version.
/// 
/// You should have received a copy of the GNU General Public License
/// along with these files.  
/// If not, see <http://www.gnu.org/licenses/>.
///
/// @remark
/// This software is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
/// See the GNU General Public License for more details.
/// 

#ifndef _MX4_C301_h
#define _MX4_C301_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

///@name Wiring
/// Display segments are arranged in a way that allow port write
/// Pin  2: Segment C
/// Pin  3: Segment D
/// Pin  4: Segment E
/// Pin  5: Segment F
/// Pin  6: Segment G
/// Pin  7:  *Free, future use*
/// Pin  8: Segment A
/// Pin  9: Segment B
///

#define DISPLAY_SIZE 4
#define DMASK B01111100
#define BMASK B00000011

#define SEGMENT_A	B00000001
#define SEGMENT_B	B00000010
#define SEGMENT_C	B00000100
#define SEGMENT_D	B00001000
#define SEGMENT_E	B00010000
#define SEGMENT_F	B00100000
#define SEGMENT_G	B01000000

#define LED_1	B00000001
#define LED_2	B00000010
#define LED_3	B00000100
#define LED_67	B00001000
#define LED_8	B00010000
#define LED_9	B00100000
#define LED_11	B01000000

#define BLANK	B10000000
#define MINUS	B11000000

/// 
/// 7 segments 4 digits common cathodes LED display manager
class MX4_C301Class
{
protected:
	uint8_t blink_status[DISPLAY_SIZE + 1];
	int blink_counter = 0;

	/// @name Low level write methods
	/// Methods to write data at low level
	/// @{
	void writeDigit(uint8_t picture);						//!< writes raw data to output ports
	void writeChar(char digit);								//!< writes built-incharacter to output ports
	void writeDigit(uint8_t picture, uint8_t blink_mask);	//!< writes raw data to output ports with blinking mask
	void writeChar(char digit, uint8_t blink_mask);			//!< writes built-incharacter to output ports with blinking mask
	/// @} 

	uint8_t charmap[16] = {
		B00111111,  //!<0
		B00000110,	//!<1
		B01011011,	//!<2
		B01001111,	//!<3
		B01100110,	//!<4
		B01101101,	//!<5
		B01111101,	//!<6
		B00000111,	//!<7
		B01111111,	//!<8
		B01101111,	//!<9
		B01110111,  //!<A
		B01111100,	//!<b
		B00111001,	//!<C
		B01011110,	//!<d
		B01111001,	//!<E
		B01110001	//!<F
	};

public:
	char display[DISPLAY_SIZE];			//!< Display storage area
	uint8_t dots;						//!< Dots storage area
	uint8_t blink[DISPLAY_SIZE + 1];	//!< Blink flags
	int blink_speed = 125;				//!< default(125): 2Hz
	uint8_t brightness = 255;			//!< default(255): Full light  (not yet implemented)

	
	/// @name Inits
	/// Methods to initialize display
	///@{
	void init();						//!< inits the display
	void reset_blinking();				//!< clears blinking flags
	void clear();						//!< clears the display
	void zero();						//!< set display to 0
	///@}

	/// @name Multiplexing
	/// Methods to multiplex digits
	/// @{
	void refresh(int active);			//!< performs the digits multiplexing	
	void blinking();					//!< make blinking
	///@}

	/// @name High level write region
	/// Methods to write data at high level
	///@{
	void write(int value);				//!< displays an integer value
	void set_all_digits(uint8_t picture);
	void set_all_digits(uint8_t picture, uint8_t blink_mask);
	void set_all_blink(uint8_t blink_mask);
	///@}
};

extern MX4_C301Class MX4_C301;

#endif

