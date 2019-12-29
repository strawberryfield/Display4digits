/// @file 
/// Display test class implementation.
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

#include "Display_Test.h"

/** init base class and internal counter */ 
void Display_TestClass::init()
{
	MX4_C301Class::init();
	j = 0;
}

/** advances counters in decimal and hex */
void Display_TestClass::increase_counters() {
	if (j < 99) {
		j++;

		dots = LED_67;
		display[0] = j / 10;
		display[1] = j % 10;
		display[2] = j / 16;
		display[3] = j % 16;
		if (j % 10 == 0) {
			blink[4] ^= 0xFF;
		}
	}
	else {
		j = 0;
		clear();
	}
}

/** test for write method */
void Display_TestClass::decimal_counter() {
	if (j < 25) {
		write(j);
		j++;
	}
	else {
		j = -24;
		clear();
	}
}

void Display_TestClass::rowcol(uint8_t row, uint8_t col)
{
	if (row > 0) {
		display[0] = LOWER_R;
		display[1] = row;
		display[2] = LOWER_C;
		display[3] = col;
	}
	else {
		clear();
	}
}

void Display_TestClass::showKeyboard(Keyboard16keysClass kb)
{
	display[0] = kb.currentKeyRow;
	display[1] = kb.currentKeyCol;
	if (kb.currentKeyRow > 0) {
		display[3] = ascii2keymap(kb.currentKey());
	}
	else {
		display[3] = BLANK;
	}
}

Display_TestClass Display_Test;

