#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdbool.h>

typedef bool (*FuncPtr)(void);
typedef void (*SignalFn)(void);

struct Caller {
    unsigned short idx;
    const SignalFn* fp;
    FuncPtr next;
    bool signalOutput; // true for led on (signal output), false for led off(not started, or
                       // finished, or in-between signals pause)
};

struct CharPattern* findCharPattern(unsigned char toFind);

bool callNext(void);

void initializeCaller(void);

char getNextChar(void);

char toUpper(char c);

void setInput(char* text);

extern struct Caller caller;

#endif
