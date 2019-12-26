/// @file 
/// Main Arduino entry point.
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
/// @name Wiring diagram
/// @image html BaseDisplay_bb.jpg


#include "Keyboard16keys.h"
#include "Display_Test.h"
#include "Timer.h"
// #include "MX4_C301.h"

uint32_t old_millis;	 //!< millis reference 

/** the setup function runs once when you press reset or power the board */
void setup() {
	Display_Test.init();
	Timer.init(250);	    //Base interrupt frequency 250Hz
	Keyboard16keys.init();
	old_millis = millis();
}

/** the loop function runs over and over again until power down or reset */
void loop() {
	if (millis() - old_millis >= 100) {
		old_millis = millis();
		Display_Test.write(Keyboard16keys.readColumn());
	}
}

/// timer compare interrupt service routine
/// Called every 4 milliseconds
ISR(TIMER1_COMPA_vect) {        
	Display_Test.refresh();
}


