/**
 * Map character - set of Morse signals.
 */

#include "iterator.h"
#include "signals.h"
#include "char-signals_map.h"

const FuncPtr sPattern[] = {dit, dit, dit, 0};
const FuncPtr aPattern[] = {dit, dah, 0};
const FuncPtr bPattern[] = {dah, dit, dit, dit, 0};
const FuncPtr cPattern[] = {dah, dit, dah, dit, 0};
const FuncPtr dPattern[] = {dah, dit, dit, 0};
const FuncPtr ePattern[] = {dit, 0};
const FuncPtr fPattern[] = {dit, dit, dah, dit, 0};
const FuncPtr gPattern[] = {dah, dah, dit, 0};
const FuncPtr hPattern[] = {dit, dit, dit, dit, 0};
const FuncPtr iPattern[] = {dit, dit, 0};
const FuncPtr jPattern[] = {dit, dah, dah, dah, 0};
const FuncPtr kPattern[] = {dah, dit, dah, 0};
const FuncPtr lPattern[] = {dit, dah, dit, dit, 0};
const FuncPtr mPattern[] = {dah, dah, 0};
const FuncPtr nPattern[] = {dah, dit, 0};
const FuncPtr oPattern[] = {dah, dah, dah, 0};
const FuncPtr pPattern[] = {dit, dah, dah, dit, 0};
const FuncPtr qPattern[] = {dah, dah, dit, dah, 0};
const FuncPtr rPattern[] = {dit, dah, dit, 0};
const FuncPtr tPattern[] = {dah, 0};
const FuncPtr uPattern[] = {dit, dit, dah, 0};
const FuncPtr vPattern[] = {dit, dit, dit, dah, 0};
const FuncPtr wPattern[] = {dit, dah, dah, 0};
const FuncPtr xPattern[] = {dah, dit, dit, dah, 0};
const FuncPtr yPattern[] = {dah, dit, dah, dah, 0};
const FuncPtr zPattern[] = {dah, dah, dit, dit, 0};

const FuncPtr onePattern[] = {dit, dah, dah, dah, dah, 0};
const FuncPtr twoPattern[] = {dit, dit, dah, dah, dah, 0};
const FuncPtr threePattern[] = {dit, dit, dit, dah, dah, 0};
const FuncPtr fourPattern[] = {dit, dit, dit, dit, dah, 0};
const FuncPtr fivePattern[] = {dit, dit, dit, dit, dit, 0};
const FuncPtr sixPattern[] = {dah, dit, dit, dit, dit, 0};
const FuncPtr sevenPattern[] = {dah, dah, dit, dit, dit, 0};
const FuncPtr eightPattern[] = {dah, dah, dah, dit, dit, 0};
const FuncPtr ninePattern[] = {dah, dah, dah, dah, dit, 0};
const FuncPtr zeroPattern[] = {dah, dah, dah, dah, dah, 0};

const FuncPtr dotPattern[] = {dit, dah, dit, dah, dit, dah, 0};
const FuncPtr commaPattern[] = {dah, dah, dit, dit, dah, dah, 0};
const FuncPtr dashPattern[] = {dah, dit, dit, dit, dit, dah, 0};
const FuncPtr questionPattern[] = {dit, dit, dah, dah, dit, dit, 0};
const FuncPtr exclamationPattern[] = {dah, dit, dah, dit, dah, dah, 0};
const FuncPtr endPattern[] = {0};



struct CharPattern charMap[] = {
    {'A', aPattern},
    {'B', bPattern},
    {'C', cPattern},
    {'D', dPattern},
    {'E', ePattern},
    {'F', fPattern},
    {'G', gPattern},
    {'H', hPattern},
    {'I', iPattern},
    {'J', jPattern},
    {'K', kPattern},
    {'L', lPattern},
    {'M', mPattern},
    {'N', nPattern},
    {'O', oPattern},
    {'P', pPattern},
    {'Q', qPattern},
    {'R', rPattern},
    {'S', sPattern},
    {'T', tPattern},
    {'U', uPattern},
    {'V', vPattern},
    {'W', wPattern},
    {'X', xPattern},
    {'Y', yPattern},
    {'Z', zPattern},

    {'1', onePattern},
    {'2', twoPattern},
    {'3', threePattern},
    {'4', fourPattern},
    {'5', fivePattern},
    {'6', sixPattern},
    {'7', sevenPattern},
    {'8', eightPattern},
    {'9', ninePattern},
    {'0', zeroPattern},

    {'.', dotPattern},
    {',', commaPattern},
    {'-', dashPattern},
    {'?', questionPattern},
    {'!', exclamationPattern},
    {'\0', endPattern},
};

