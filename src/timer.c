/**
 * Timer configuration.
*/
#include "driverlib.h"
#include "timer.h"
#include "iterator.h"

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
    caller.next();
}