#ifndef HAL_H
#define HAL_H

// Input clock frequency.
#define ALCLK_FREQUENCY 32768UL

typedef void (*isrCallback)(void);
/**
 * Timer configuration.
 */
void setUpTimer(unsigned short timerPeriod);

void ledOn(void);

void ledOff(void);

void waitUnits(short unsigned units);

void init(void);

void setIsrCallback(isrCallback);

#endif
