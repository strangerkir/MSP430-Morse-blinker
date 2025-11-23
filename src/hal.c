#include "hal.h"
#include "iterator.h"
#include <driverlib.h>
/**
 * A time unit used to get different intervals.
 * ~200ms
 */
#define TIMER_PERIOD_UNIT (ALCLK_FREQUENCY * 0.2)

static isrCallback callback;

void setIsrCallback(isrCallback cb) {
    callback = cb;
}

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

void setUpTimer(unsigned short timerPeriod) {
    Timer_A_initUpModeParam initParam;
    initParam.clockSource = TIMER_A_CLOCKSOURCE_ACLK;
    initParam.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1;
    initParam.timerPeriod = timerPeriod;
    initParam.captureCompareInterruptEnable_CCR0_CCIE = TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE;
    initParam.timerInterruptEnable_TAIE = TIMER_A_TAIE_INTERRUPT_DISABLE;
    initParam.timerClear = TIMER_A_DO_CLEAR;
    initParam.startTimer = false;

    Timer_A_initUpMode(TIMER_A0_BASE, &initParam);

    Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE,
    TIMER_A_CAPTURECOMPARE_REGISTER_0);

    Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void myISR_TA0_Other(void) {
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    Timer_A_stop(TIMER_A0_BASE);
    callback();
}
