#include "hal.h"
#include "timer.h"
#include <driverlib.h>
/**
 * A time unit used to get different intervals.
 * ~200ms
 */
#define TIMER_PERIOD_UNIT (ALCLK_FREQUENCY * 0.2)

void ledOn() {
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
};

void ledOff() {
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
};

void waitUnits(unsigned short units) {
    setUpTimer(units * TIMER_PERIOD_UNIT);
}


void init() {
    WDT_A_hold(WDT_A_BASE);
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    _enable_interrupt();
}
