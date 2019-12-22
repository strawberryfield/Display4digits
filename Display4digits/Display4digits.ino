/** @file Display4digits.ino */
/**
\file Display4digits.ino
Main Arduino entry point
*/

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
#include "Timer.h"
// #include "MX4_C301.h"

/** millis reference */
uint32_t old_millis;	 

/** the setup function runs once when you press reset or power the board */
void setup() {
	Display_Test.init();
	Timer.init(250);	    //Base interrupt frequency 250Hz
	old_millis = millis();
}

/** the loop function runs over and over again until power down or reset */
void loop() {
	if (millis() - old_millis >= 500) {
		old_millis = millis();
		Display_Test.decimal_counter();
	}
}

/// timer compare interrupt service routine
/// Called every 4 milliseconds
ISR(TIMER1_COMPA_vect) {        
	Display_Test.refresh();
}