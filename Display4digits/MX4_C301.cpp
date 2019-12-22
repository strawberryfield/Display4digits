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

#pragma region Inits

// inits the display
void MX4_C301Class::init()
{
    DDRD = DDRD | DMASK; // sets pins 2 to 6 as outputs
    DDRB = DDRB | B00011111; // sets pins 8 to 12 as outputs
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);

    active = 0;

    clear();
}

// clears blinking flags
void MX4_C301Class::reset_blinking()
{
    for (int j = 0; j <= DISPLAY_SIZE; j++) {
        blink[j] = 0;               // No blinking
        blink_status[j] = 0xFF;     // All segments visible
    }
}

// clears the display
void MX4_C301Class::clear()
{
    dots = 0;
    for (int j = 0; j < DISPLAY_SIZE; j++) {
        display[j] = BLANK;
    }
    reset_blinking();
}

// set display to 0
void MX4_C301Class::zero()
{
    clear();
    display[DISPLAY_SIZE - 1] = 0;
}

#pragma endregion

#pragma region Low level writes

// writes raw data to output ports with blinking mask
void  MX4_C301Class::writeDigit(uint8_t picture, uint8_t blink_mask) {
    picture &= blink_mask;
    PORTD = (PORTD & ~DMASK) | (picture & DMASK);
    PORTB = (PORTB & ~BMASK) | (picture & BMASK);
}

// writes raw data to output ports
void  MX4_C301Class::writeDigit(uint8_t picture) {
    writeDigit(picture, 0xFF);
}

// writes built-incharacter to output ports with blinking mask
void MX4_C301Class::writeChar(char digit, uint8_t blink_mask) {
    if ((digit & 0x80) > 0) {
        writeDigit(digit, blink_mask);
    }
    else {
        writeDigit(charmap[digit], blink_mask);
    }
}

// writes built-incharacter to output ports
void MX4_C301Class::writeChar(char digit) {
    writeChar(digit, 0xFF);
}

#pragma endregion

#pragma region multiplexing

// performs the digits multiplexing
void  MX4_C301Class::refresh() {
    blink_counter++;
    if (blink_counter == blink_speed) blinking();
    digitalWrite(cathodes[active], LOW);
    if (active == DISPLAY_SIZE) {
        active = 0;
    }
    else {
        active++;
    }
    if (active == DISPLAY_SIZE) {
        writeDigit(dots, blink_status[DISPLAY_SIZE]);
    }
    else {
        writeChar(display[active], blink_status[active]);
    }
    digitalWrite(cathodes[active], HIGH);
}

// make blinking
void MX4_C301Class::blinking()
{
    blink_counter = 0;
    for (int j = 0; j <= DISPLAY_SIZE; j++) {
        blink_status[j] ^= blink[j];
        blink_status[j] |= ~blink[j];
    }
}

#pragma endregion

// MX4_C301Class MX4_C301;

