#ifndef CHAR_SIGNALS_MAP
#define CHAR_SIGNALS_MAP

#include "iterator.h"

struct CharPattern {
    char ch;
    const SignalFn* fp;
};

extern struct CharPattern charMap[];

extern const SignalFn emptyPattern[];

#endif
