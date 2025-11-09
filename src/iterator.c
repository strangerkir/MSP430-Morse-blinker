/**
 * Logic of iterating through individual signals.
 */
 #include "iterator.h"
 #include "signals.h"
 #include "char-signals_map.h"

struct Caller caller;

char getNextChar(struct Caller *caller) {
    char* text = "Some longer text for a good testing of a Morse Blinker.";
    static int i = 0;
    return text[i++];
}

struct CharPattern* findCharPattern(unsigned char toFind) {
    int i = 0;
    do {
        if(charMap[i].ch == toFind) {
            return &charMap[i];
        }

        i++;
    } while(charMap[i].ch != '\0');

    return &charMap[--i];
}

void callNext() {
    struct CharPattern* nextCharPattern;
    if(*(caller.fp) == 0) {
        char nextChar = getNextChar(&caller);
        if(nextChar == '\0') {
            //End of the text.
            return;
        }
        nextCharPattern = findCharPattern(nextChar);
        caller.fp = nextCharPattern->fp;
    }

    (*caller.fp)();
    caller.fp++;

}

void initializeCaller() {
    caller.idx = 0;
    caller.fp = emptyPattern;
    caller.next = callNext;
}
