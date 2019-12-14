// 
// 
// 

#include "MX4_C301.h"

void MX4_C301Class::init()
{
    DDRD = DDRD | DMASK; // sets pins 2 to 6 as outputs
    DDRB = DDRB | B00011111; // sets pins 8 to 12 as outputs
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);

    active = 0;
    brightness = 255;
}


void MX4_C301Class::init_timer() {
    //Base interrupt frequency 250Hz
    // 16MHz / 64 = 250 KHz after prescaler
    noInterrupts();
    // reset registers
    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    OCR1A = 1000;  // Counter after prescaler
    TCCR1B |= (1 << WGM12);   // CTC mode
    TCCR1B |= (1 << CS11) | (1 << CS10);    // 64 prescaler 
    TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
    interrupts();
}

void  MX4_C301Class::writeDigit(uint8_t picture) {
    PORTD = (PORTD & ~DMASK) | (picture & DMASK);
    PORTB = (PORTB & ~BMASK) | (picture & BMASK);
}

void MX4_C301Class::writeChar(char digit) {
    if ((digit & 0x80) > 0) {
        writeDigit(digit);
    }
    else {
        writeDigit(charmap[digit]);
    }
}

void  MX4_C301Class::refresh() {
    digitalWrite(cathodes[active], LOW);
    if (active == DISPLAY_SIZE) {
        active = 0;
    }
    else {
        active++;
    }
    if (active == DISPLAY_SIZE) {
        writeDigit(dots);
    }
    else {
        writeChar(display[active]);
    }
    digitalWrite(cathodes[active], HIGH);
}

MX4_C301Class MX4_C301;

