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

    for (int j = 0; j <= DISPLAY_SIZE; j++) {
        blink[j] = 0; // No blinking
        blink_status[j] = 0xFF; // All segments visible
    }
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

void  MX4_C301Class::writeDigit(uint8_t picture, uint8_t blink_mask) {
    picture &= blink_mask;
    PORTD = (PORTD & ~DMASK) | (picture & DMASK);
    PORTB = (PORTB & ~BMASK) | (picture & BMASK);
}

void  MX4_C301Class::writeDigit(uint8_t picture) {
    writeDigit(picture, 0xFF);
}

void MX4_C301Class::writeChar(char digit, uint8_t blink_mask) {
    if ((digit & 0x80) > 0) {
        writeDigit(digit, blink_mask);
    }
    else {
        writeDigit(charmap[digit], blink_mask);
    }
}

void MX4_C301Class::writeChar(char digit) {
    writeChar(digit, 0xFF);
}

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

void MX4_C301Class::blinking()
{
    blink_counter = 0;
    for (int j = 0; j <= DISPLAY_SIZE; j++) {
        blink_status[j] ^= blink[j];
        blink_status[j] |= ~blink[j];
    }
}


MX4_C301Class MX4_C301;

