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

#include "MX4_C301.h"

// the setup function runs once when you press reset or power the board
void setup() {
	MX4_C301.init();
	MX4_C301.init_timer();
}

// the loop function runs over and over again until power down or reset
void loop() {
	MX4_C301.dots = 0x08;
	for (int j = 0; j < 100; j++) {
		MX4_C301.display[0] = j / 10;
		MX4_C301.display[1] = j % 10;
		MX4_C301.display[2] = j / 16;
		MX4_C301.display[3] = j % 16;
		if (j % 10 == 0) {
			MX4_C301.blink[4] ^= 0xFF;
		}
		delay(500);
	}
}

// timer compare interrupt service routine
// Called every 4 milliseconds
ISR(TIMER1_COMPA_vect) {        
	MX4_C301.refresh();
}