/**
 * Signals used in Morse code:
 * dah's (long signals),
 * dit's (short signals),
 * and spaces (used inside character, between characters, and between words).
 *
 */
#include "signals.h"
#include "hal.h"



void dah(void) {
    ledOn();
    waitUnits(3);
};


void dit(void) {
    ledOff();
    waitUnits(1);
}


void intraCharacterSpace(void) {
    ledOff();
    waitUnits(1);
}


void characterSpace(void) {
    ledOn();
    waitUnits(3);

}


void wordSpace(void) {
    ledOff();
    waitUnits(7);
}
