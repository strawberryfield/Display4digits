/// @file 
/// Display test class definition.
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

#ifndef _DISPLAY_TEST_h
#define _DISPLAY_TEST_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "MX4_C301.h"
#include "Keyboard16keys.h"

///@brief 
/// Display test suite 
class Display_TestClass : public MX4_C301Class
{
 private:
	 int j;		// counter

 public:
	 void init();
	 void increase_counters();
	 void decimal_counter();
	 void rowcol(uint8_t row, uint8_t col);
	 void showKeyboard(Keyboard16keysClass kb);
};

extern Display_TestClass Display_Test;

#endif

