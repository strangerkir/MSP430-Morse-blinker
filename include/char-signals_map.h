#ifndef CHAR_SIGNALS_MAP
#define CHAR_SIGNALS_MAP

#include "iterator.h"

struct CharPattern {
    char ch;
    const FuncPtr* fp;
};

extern struct CharPattern charMap[];

extern const FuncPtr emptyPattern[];

#endif
