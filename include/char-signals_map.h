#ifndef CHAR_SIGNALS_MAP
#define CHAR_SIGNALS_MAP

#include "iterator.h"

struct CharPattern {
    char ch;
    FuncPtr fp[7];
} CharPattern;


extern struct CharPattern charMap[] = {
    {'A', {dit, dah, 0}},
    {'B', {dah, dit, dit, dit, 0}},
    {'C', {dah, dit, dah, dit, 0}},
    {'D', {dah, dit, dit, 0}},
    {'E', {dit, 0}},
    {'F', {dit, dit, dah, dit, 0}},
    {'G', {dah, dah, dit, 0}},
    {'H', {dit, dit, dit, dit, 0}},
    {'I', {dit, dit, 0}},
    {'J', {dit, dah, dah, dah, 0}},
    {'K', {dah, dit, dah, 0}},
    {'L', {dit, dah, dit, dit, 0}},
    {'M', {dah, dah, 0}},
    {'N', {dah, dit, 0}},
    {'O', {dah, dah, dah, 0}},
    {'P', {dit, dah, dah, dit, 0}},
    {'Q', {dah, dah, dit, dah, 0}},
    {'R', {dit, dah, dit, 0}},
    {'S', {dit, dit, dit, 0}},
    {'T', {dah, 0}},
    {'U', {dit, dit, dah, 0}},
    {'V', {dit, dit, dit, dah, 0}},
    {'W', {dit, dah, dah, 0}},
    {'X', {dah, dit, dit, dah, 0}},
    {'Y', {dah, dit, dah, dah, 0}},
    {'Z', {dah, dah, dit, dit, 0}},

    {'1', {dit, dah, dah, dah, dah, 0}},
    {'2', {dit, dit, dah, dah, dah, 0}},
    {'3', {dit, dit, dit, dah, dah, 0}},
    {'4', {dit, dit, dit, dit, dah, 0}},
    {'5', {dit, dit, dit, dit, dit, 0}},
    {'6', {dah, dit, dit, dit, dit, 0}},
    {'7', {dah, dah, dit, dit, dit, 0}},
    {'8', {dah, dah, dah, dit, dit, 0}},
    {'9', {dah, dah, dah, dah, dit, 0}},
    {'0', {dah, dah, dah, dah, dah, 0}},

    {'.', {dit, dah, dit, dah, dit, dah, 0}},
    {',', {dah, dah, dit, dit, dah, dah, 0}},
    {'-', {dah, dit, dit, dit, dit, dah, 0}},
    {'?', {dit, dit, dah, dah, dit, dit, 0}},
    {'!', {dah, dit, dah, dit, dah, dah, 0}},
    {'\0', {0}},
};

#endif
