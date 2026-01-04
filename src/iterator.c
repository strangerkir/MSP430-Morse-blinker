/**
 * Logic of iterating through individual signals.
 */
#include "iterator.h"
#include "char-signals_map.h"
#include "signals.h"

struct Caller caller;

static char* input = "";

struct CharPattern* findCharPattern(unsigned char toFind) {
    int i = 0;
    do {
        if (charMap[i].ch == toFind) {
            return &charMap[i];
        }

        i++;
    } while (charMap[i].ch != '\0');

    return &charMap[--i];
}

void setInput(char* text) { input = text; }

char getNextChar(void) {
    static int i = 0;
    return input[i++];
}

void callNext(void) {
    struct CharPattern* nextCharPattern;

    if (*(caller.fp) == 0) {
        char nextChar = getNextChar();
        nextChar = toUpper(nextChar);
        if (nextChar == '\0') {
            // End of the text.
            return;
        }
        nextCharPattern = findCharPattern(nextChar);
        caller.fp = nextCharPattern->fp;
    } else if (caller.signalOutput) {
        intraCharacterSpace();
        caller.signalOutput = false;
        return;
    }

    (*caller.fp)();
    caller.signalOutput = true;
    caller.fp++;
}

void initializeCaller(void) {
    caller.idx = 0;
    caller.fp = emptyPattern;
    caller.next = callNext;
    caller.signalOutput = false;
}

char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }

    return c;
}
