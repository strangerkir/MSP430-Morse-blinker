#include "iterator.h"
#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

int runUnitTests();

int main(void) {
    //int executed = 0;
    int failed = 0;

    setInput("Some longer text for a good testing of a Morse Blinker."); // todo: replace with
                                                                         // reading from a file

    failed = runUnitTests();

    //printf("Total tests executed:%d\n", executed);
    const char* color = failed > 0 ? ANSI_COLOR_RED : ANSI_COLOR_GREEN;
    printf("%1$sFailed tests: %2$d%3$s\n", color, failed, ANSI_COLOR_RESET);

    return failed != 0;
}
