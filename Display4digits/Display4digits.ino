/*
 Name:		Display4digit.ino
 Created:	12/11/2019 9:09:33 PM
 Author:	Roberto Ceccarelli
*/



#include "MX4_C301.h"



// the setup function runs once when you press reset or power the board
void setup() {
    MX4_C301.init();
}

// the loop function runs over and over again until power down or reset
void loop() {
    int j = 1;
//    for (int j = 0; j < 13; j++) {
        MX4_C301.display[0] = j;
        MX4_C301.display[1] = j+1;
        MX4_C301.display[2] = j+2;
        MX4_C301.display[3] = j+3;
        for (int k = 0; k < 5; k++) {
            MX4_C301.refresh();
            delay(500);
 //       }
    }


}

