/**
 * Signals used in Morse code:
 * dah's (long signals),
 * dit's (short signals),
 * and spaces (used inside character, between characters, and between words).
 *
 */

#include "driverlib.h"
#include "signals.h"
#include "timer.h"

/**
 * A time unit used to get different intervals.
 * ~200ms
 */
#define TIMER_PERIOD_UNIT (ALCLK_FREQUENCY * 0.2)



void dah(void) {
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
    setUpTimer(TIMER_PERIOD_UNIT * 3);
};


void dit(void) {
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
    setUpTimer(TIMER_PERIOD_UNIT);
}


void intraCharacterSpace(void) {
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    setUpTimer(TIMER_PERIOD_UNIT);
}


void characterSpace(void) {
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
        setUpTimer(TIMER_PERIOD_UNIT * 3);

}


void wordSpace(void) {
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    setUpTimer(TIMER_PERIOD_UNIT * 7);

}