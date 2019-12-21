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

#include "Timer.h"
#include "MX4_C301.h"

uint32_t old_millis;	// millis reference

// the setup function runs once when you press reset or power the board
void setup() {
	MX4_C301.init();
	Timer.init(250);	    //Base interrupt frequency 250Hz
	old_millis = millis();
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (millis() - old_millis >= 500) {
		old_millis = millis();
		increase_counters();
	}
}

int j = 0;		// counter
// advances counters
void increase_counters() {
	if (j < 99) {
		j++;

		MX4_C301.dots = LED_67;
		MX4_C301.display[0] = j / 10;
		MX4_C301.display[1] = j % 10;
		MX4_C301.display[2] = j / 16;
		MX4_C301.display[3] = j % 16;
		if (j % 10 == 0) {
			MX4_C301.blink[4] ^= 0xFF;
		}
	}
	else {
		j = 0;
		MX4_C301.clear();
	}


}

// timer compare interrupt service routine
// Called every 4 milliseconds
ISR(TIMER1_COMPA_vect) {        
	MX4_C301.refresh();
}