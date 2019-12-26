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

#include "Keyboard16keys.h"

void Keyboard16keysClass::init()
{
	init(PIN_A7);
}

void Keyboard16keysClass::init(int input)
{
	inputPin = input;
}

int Keyboard16keysClass::readColumn()
{
	int v = analogRead(inputPin);
	if (v < 400) return 0;
	if (v < 600) return 4;
	if (v < 700) return 3;
	if (v < 900) return 2;
	return 1;
}


Keyboard16keysClass Keyboard16keys;

