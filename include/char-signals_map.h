#ifndef CHAR_SIGNALS_MAP
#define CHAR_SIGNALS_MAP

#include "iterator.h"

struct CharPattern {
    char ch;
    FuncPtr fp[7];
};


extern struct CharPattern charMap[];

#endif
