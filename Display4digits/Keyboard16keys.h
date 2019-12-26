/// @file 
/// Keyboard 16 keys class definition.
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

#ifndef _KEYBOARD16KEYS_h
#define _KEYBOARD16KEYS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Keyboard16keysClass
{
 protected:
	 int inputPin = PIN_A7;		//!< default input on pin A7

 public:
	void init();				//!< init on default pin
	void init(int input);		//!< init on user pin
	int	readColumn();			//!< return pressed row for current column
};

extern Keyboard16keysClass Keyboard16keys;

#endif

