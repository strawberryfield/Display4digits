/*
 Name:		Display4digit.ino
 Created:	12/11/2019 9:09:33 PM
 Author:	Roberto Ceccarelli
*/



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

		delay(500);
	}
}

ISR(TIMER1_COMPA_vect) {        // timer compare interrupt service routine
	MX4_C301.refresh();
}