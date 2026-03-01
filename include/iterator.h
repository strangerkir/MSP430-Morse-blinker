#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdbool.h>
#include <stddef.h>

typedef bool (*FuncPtr)(void);
typedef void (*SignalFn)(void);

struct Caller {
    unsigned short idx;
    const SignalFn* fp;
    FuncPtr next;
    bool signalOutput;         // true for led on (signal output), false for led off(not started, or
                               // finished, or in-between signals pause)
    bool characterSpaceOutput; // whether a space after a character was output.
    size_t charIdx;            // Index of the current character in the string to output
};

struct CharPattern* findCharPattern(unsigned char toFind);

extern struct Caller caller;

bool callNext(void);

void initializeCaller(void);

char getNextChar(struct Caller* caller);

char toUpper(char c);

void setInput(char* text);

#endif
