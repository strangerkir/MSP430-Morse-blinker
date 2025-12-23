#include "char-signals_map.h"
#include "iterator.h"
#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

int test_toUpper(void) {
    short failed = 0;
    if (toUpper('c') != 'C') {
        failed++;
    }

    if (toUpper('a') != 'A') {
        failed++;
    }

    if (toUpper('Z') != 'Z') {
        failed++;
    }

    if (toUpper(',') != ',') {
        failed++;
    }

    if (toUpper(' ') != ' ') {
        failed++;
    }

    return failed;
}

int test_getNextChar() {
    short failed = 0;
    // Just check it returns next letter every time.
    if (getNextChar() != 'S') {
        failed++;
    }

    if (getNextChar() != 'o') {
        failed++;
    }

    return failed;
}

int main(void) {
    int executed = 0;
    int failed = 0;

    setInput("Some longer text for a good testing of a Morse Blinker."); // todo: replace with
                                                                         // reading from a file

    failed += test_toUpper();
    failed += test_getNextChar();
    executed = 1;

    printf("Total tests executed:%d\n", executed);
    const char* color = failed > 0 ? ANSI_COLOR_RED : ANSI_COLOR_GREEN;
    printf("%1$sFailed tests: %2$d%3$s\n", color, failed, ANSI_COLOR_RESET);

    return failed != 0;
}
