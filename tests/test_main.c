#include "iterator.h"
#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

int runUnitTests(void);
int runIntegrationTests(void);
void printResults(int failedTestsNumber, char* testsType);

int main(void) {

    setInput("Some longer text for a good testing of a Morse Blinker."); // todo: replace with
                                                                         // reading from a file
    int unitFailed = runUnitTests();
    printResults(unitFailed, "unit");

    int integrationFailed = runIntegrationTests();
    printResults(integrationFailed, "integration");

    return unitFailed != 0;
}

void printResults(int failedTestsNumber, char* testsType) {

    const char* color = failedTestsNumber > 0 ? ANSI_COLOR_RED : ANSI_COLOR_GREEN;
    printf("%1$sFailed %4$s tests: %2$d%3$s\n", color, failedTestsNumber, ANSI_COLOR_RESET,
           testsType);
}
