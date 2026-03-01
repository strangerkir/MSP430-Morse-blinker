#ifndef HAL_H
#define HAL_H

#include <driverlib.h>

// Input clock frequency.
#define ALCLK_FREQUENCY 32768UL

#define OUTPUT_PORT GPIO_PORT_P6
#define OUTPUT_PIN GPIO_PIN1

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
