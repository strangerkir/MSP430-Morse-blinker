#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdbool.h>

typedef void (*FuncPtr)(void);

struct Caller {
    unsigned short idx;
    const FuncPtr* fp;
    FuncPtr next;
    bool signalOutput; //true for led on (signal output), false for led off(not started, or finished, or in-between signals pause)

};

void initializeCaller();

char getNextChar();

char toUpper(char c);

void setInput(char* text);

extern struct Caller caller;

#endif
