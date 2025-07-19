/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/

#include "driverlib.h"

//******************************************************************************
//!
//!   Converts text into Morse signals outputted by led.
//!
//******************************************************************************

#define ALCLK_FREQUENCY 32768UL
#define TIMER_PERIOD_UNIT (ALCLK_FREQUENCY * 0.2)

typedef void (*FuncPtr)(void);

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

/**
 * Long signal
 */
void dah(void) {
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
    setUpTimer(TIMER_PERIOD_UNIT * 3);
};

/**
 * Short signal
 */
void dit(void) {
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
    setUpTimer(TIMER_PERIOD_UNIT);
}

/**
 * Short pause. Used between dits and dahs inside one character
 */
void intraCharacterSpace(void) {
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    setUpTimer(TIMER_PERIOD_UNIT);
}

/**
 * Middle pause. Used between characters inside word.
 */
void characterSpace(void) {
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
        setUpTimer(TIMER_PERIOD_UNIT * 3);

}

/**
 * Long pause. Used between words.
 */
void wordSpace(void) {
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    setUpTimer(TIMER_PERIOD_UNIT * 7);

}

struct Caller {
    unsigned short idx;
    unsigned short size;
    FuncPtr *fp;
    FuncPtr next;

};

struct Caller caller;

void callNext() {

    if(caller.idx >= caller.size) {
        caller.idx = 0;
    }

    caller.fp[caller.idx]();
    caller.idx ++;

}

void initializeCaller(FuncPtr fp[], short unsigned size) {
    caller.idx = 0;
    caller.size = size;
    caller.fp = fp;
    caller.next = callNext;
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void myISR_TA0_Other(void) {
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    Timer_A_stop(TIMER_A0_BASE);
    caller.next();
}

void main (void)
{
    char * text = "Test";

    WDT_A_hold(WDT_A_BASE);
    FuncPtr fp[] = {dit, intraCharacterSpace, dah, wordSpace, dit, wordSpace};
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    int singleSize = sizeof(fp[0]);
    short unsigned fpSize = sizeof(fp) / singleSize;
    initializeCaller(fp, fpSize);
    _enable_interrupt();
    caller.next();
    while (1) {
        __no_operation();
    }
}
