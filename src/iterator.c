/**
 * Logic of iterating through individual signals.
 */

 #include "iterator.h"
 #include "signals.h"
 #include "char-signals_map.h"

struct Caller caller;

void getNextChar(struct Caller *caller) {
    caller->fp[0] = dit;
}

struct CharPattern findCharPattern(unsigned char toFind) {
    int i = 0;
    do {
        if(charMap[i].ch == toFind) {
            return charMap[1];
        }

        i++;
    } while(charMap[i].ch != '\0');

    return charMap[--i];
}

void callNext() {

    if(caller.idx >= caller.size) {
        getNextChar(&caller);
        caller.idx = 0;
    }

    caller.fp[caller.idx]();
    caller.idx ++;

}

void initializeCaller(FuncPtr fp[], short unsigned size) {
    caller.idx = 0;
    caller.size = size;
    caller.fp = fp;
    caller.next = callNext;
}
