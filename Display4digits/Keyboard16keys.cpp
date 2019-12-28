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
	currentKeyCol = 0;
	currentKeyRow = 0;
}

void Keyboard16keysClass::scanKey(uint8_t col)
{
	if (col < 4) {
		uint8_t row = readColumn();
		if (row > 0) {
			currentKeyCol = col + 1;
			currentKeyRow = row;
		}
		else if (currentKeyCol == col + 1) {
			currentKeyCol = 0;
			currentKeyRow = 0;
		}
	}
}

int Keyboard16keysClass::readColumn()
{
	int v = analogRead(inputPin);
	if (v < ROW4EDGE) return 0;
	if (v > ROW1EDGE) return 1;
	if (v > ROW2EDGE) return 2;
	if (v > ROW3EDGE) return 3;
	return 4;
}

char Keyboard16keysClass::currentKey()
{
	if (currentKeyCol == 0) {
		return 0;
	}
	return keymap[currentKeyRow - 1][currentKeyCol - 1];
}


Keyboard16keysClass Keyboard16keys;

