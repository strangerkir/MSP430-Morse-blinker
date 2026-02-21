#include <stdbool.h>
#include "hal.h"
#include "hal_mock.h"

char outputBuffer[1024];
size_t outputBufferIdx = 0;

bool ledIsOn = false;

void setIsrCallback(isrCallback) {}

void ledOn(void) {
    ledIsOn = true;
}

void ledOff(void) {
    ledIsOn = false;
}

void init(void) {}

void waitUnits(unsigned short units) {
    char outputChar = ledIsOn ? '+' : '/';

    for (unsigned short i = 0; i<units; i++) {
        outputBuffer[outputBufferIdx] = outputChar;
        outputBufferIdx++;
    }

    outputBuffer[outputBufferIdx] = '\0';
}