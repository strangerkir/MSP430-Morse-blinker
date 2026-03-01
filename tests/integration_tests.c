#include "../include/iterator.h"
#include "hal_mock.h"
#include <string.h>

int runIntegrationTests(void);

int runIntegrationTests(void) {
    initializeCaller();
    setInput("SOS");
    outputBuffer[0] = '\0';

    while (caller.next()) {
        // nothing to do here
    }

    int result = strcmp(outputBuffer, "+/+/+///+++/+++/+++///+/+/+///");

    return result == 0 ? 0 : 1;
}