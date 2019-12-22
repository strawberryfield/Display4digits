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

#ifndef _DISPLAY_TEST_h
#define _DISPLAY_TEST_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "MX4_C301.h"

class Display_TestClass : public MX4_C301Class
{
 protected:
	 int j;		// counter

 public:
	 void init();
	 void increase_counters();
	 void decimal_counter();
};

extern Display_TestClass Display_Test;

#endif

