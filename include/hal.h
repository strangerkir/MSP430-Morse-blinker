#ifndef HAL_H
#define HAL_H

#include "iterator.h"

/**
 * Timer configuration.
 */
void setUpTimer(unsigned short timerPeriod);

void ledOn(void);

void ledOff(void);

void waitUnits(short unsigned units);

void init(void);

void setIsrCallback(FuncPtr cb);

#endif
