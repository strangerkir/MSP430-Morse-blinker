/**
 * Logic of iterating through individual signals.
 */
#include "iterator.h"
#include "char-signals_map.h"
#include "signals.h"
#include "string.h"

struct Caller caller;

static char input[1024];

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

void setInput(char* text) { 
    strcpy(input, text);
}

char getNextChar(struct Caller *caller) {
    char nextChar = input[caller->charIdx];
    caller->charIdx++;

    return nextChar;
}

bool callNext(void) {
    struct CharPattern* nextCharPattern;

    if (*(caller.fp) == 0) {
        if (!caller.characterSpaceOutput &&
            caller.fp != emptyPattern) { // Emitted a character, character space is needed
            characterSpace();
            caller.characterSpaceOutput = true;
            return true;
        }
        caller.characterSpaceOutput = false; // Reset the flag for the next character.
        char nextChar = getNextChar(&caller);
        nextChar = toUpper(nextChar);
        if (nextChar == '\0') {
            // End of the text.
            return false;
        }
        nextCharPattern = findCharPattern(nextChar);
        caller.fp = nextCharPattern->fp;
    } else if (caller.signalOutput) {
        intraCharacterSpace();
        caller.signalOutput = false;
        return true;
    }

    (*caller.fp)();
    caller.signalOutput = true;
    caller.fp++;
    return true;
}

void initializeCaller(void) {
    caller.idx = 0;
    caller.fp = emptyPattern;
    caller.next = callNext;
    caller.signalOutput = false;
    caller.characterSpaceOutput = false;
    caller.charIdx = 0;
}

char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }

    return c;
}
