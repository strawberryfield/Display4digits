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

#include "Display_Test.h"

void Display_TestClass::init()
{
	MX4_C301Class::init();
	j = 0;
}

// advances counters
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
Display_TestClass Display_Test;

