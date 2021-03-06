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
///

#include "Multiplexer.h"
#include "Keyboard16keys.h"
#include "Display_Test.h"
#include "Timer.h"
// #include "MX4_C301.h"

/// @name Wiring
/// Pin 11: Enable dots  
/// Pin 12: Enable digit 1  
/// Pin A1: Enable digit 2  
/// Pin A2: Enable digit 3  
/// Pin A3: Enable digit 4  
uint8_t cathodes[] = {
	12, PIN_A1, PIN_A2, PIN_A3, 11
};

uint32_t old_millis;	 //!< millis reference 


/** the setup function runs once when you press reset or power the board */
void setup() {
	Display_Test.init();
	Multiplexer.init(cathodes, DISPLAY_SIZE + 1);
	Keyboard16keys.init();
	Timer.init(250);	    //Base interrupt frequency 250Hz
	old_millis = millis();
//	Display_Test.write(12345);
//	Display_Test.dots = LED_67;
	Keyboard16keys.numericInputInit(Display_Test.display, DISPLAY_SIZE);
}

/** the loop function runs over and over again until power down or reset */
void loop() {
	if (millis() - old_millis >= 100) {
		old_millis = millis();
//		Display_Test.rowcol(Keyboard16keys.currentKeyRow, Keyboard16keys.currentKeyCol);
//		Display_Test.showKeyboard(Keyboard16keys);
		Keyboard16keys.numericInput();
	}
}

/// timer compare interrupt service routine
/// Called every 4 milliseconds
ISR(TIMER1_COMPA_vect) { 
	Display_Test.blinking();
	Multiplexer.deactivateCurrent();
	Multiplexer.next();
	Display_Test.refresh(Multiplexer.active);
	Multiplexer.activateCurrent();
	Keyboard16keys.scanKey(Multiplexer.active);
}


