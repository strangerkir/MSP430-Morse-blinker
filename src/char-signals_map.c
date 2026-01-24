/**
 * Map character - set of Morse signals.
 */

#include "char-signals_map.h"
#include "iterator.h"
#include "signals.h"

const SignalFn sPattern[] = {dit, dit, dit, 0};
const SignalFn aPattern[] = {dit, dah, 0};
const SignalFn bPattern[] = {dah, dit, dit, dit, 0};
const SignalFn cPattern[] = {dah, dit, dah, dit, 0};
const SignalFn dPattern[] = {dah, dit, dit, 0};
const SignalFn ePattern[] = {dit, 0};
const SignalFn fPattern[] = {dit, dit, dah, dit, 0};
const SignalFn gPattern[] = {dah, dah, dit, 0};
const SignalFn hPattern[] = {dit, dit, dit, dit, 0};
const SignalFn iPattern[] = {dit, dit, 0};
const SignalFn jPattern[] = {dit, dah, dah, dah, 0};
const SignalFn kPattern[] = {dah, dit, dah, 0};
const SignalFn lPattern[] = {dit, dah, dit, dit, 0};
const SignalFn mPattern[] = {dah, dah, 0};
const SignalFn nPattern[] = {dah, dit, 0};
const SignalFn oPattern[] = {dah, dah, dah, 0};
const SignalFn pPattern[] = {dit, dah, dah, dit, 0};
const SignalFn qPattern[] = {dah, dah, dit, dah, 0};
const SignalFn rPattern[] = {dit, dah, dit, 0};
const SignalFn tPattern[] = {dah, 0};
const SignalFn uPattern[] = {dit, dit, dah, 0};
const SignalFn vPattern[] = {dit, dit, dit, dah, 0};
const SignalFn wPattern[] = {dit, dah, dah, 0};
const SignalFn xPattern[] = {dah, dit, dit, dah, 0};
const SignalFn yPattern[] = {dah, dit, dah, dah, 0};
const SignalFn zPattern[] = {dah, dah, dit, dit, 0};

const SignalFn onePattern[] = {dit, dah, dah, dah, dah, 0};
const SignalFn twoPattern[] = {dit, dit, dah, dah, dah, 0};
const SignalFn threePattern[] = {dit, dit, dit, dah, dah, 0};
const SignalFn fourPattern[] = {dit, dit, dit, dit, dah, 0};
const SignalFn fivePattern[] = {dit, dit, dit, dit, dit, 0};
const SignalFn sixPattern[] = {dah, dit, dit, dit, dit, 0};
const SignalFn sevenPattern[] = {dah, dah, dit, dit, dit, 0};
const SignalFn eightPattern[] = {dah, dah, dah, dit, dit, 0};
const SignalFn ninePattern[] = {dah, dah, dah, dah, dit, 0};
const SignalFn zeroPattern[] = {dah, dah, dah, dah, dah, 0};

const SignalFn dotPattern[] = {dit, dah, dit, dah, dit, dah, 0};
const SignalFn commaPattern[] = {dah, dah, dit, dit, dah, dah, 0};
const SignalFn dashPattern[] = {dah, dit, dit, dit, dit, dah, 0};
const SignalFn questionPattern[] = {dit, dit, dah, dah, dit, dit, 0};
const SignalFn exclamationPattern[] = {dah, dit, dah, dit, dah, dah, 0};
const SignalFn spacePattern[] = {wordSpace, 0};
const SignalFn emptyPattern[] = {0};

struct CharPattern charMap[] = {
    {'A', aPattern},           {'B', bPattern},      {'C', cPattern},     {'D', dPattern},
    {'E', ePattern},           {'F', fPattern},      {'G', gPattern},     {'H', hPattern},
    {'I', iPattern},           {'J', jPattern},      {'K', kPattern},     {'L', lPattern},
    {'M', mPattern},           {'N', nPattern},      {'O', oPattern},     {'P', pPattern},
    {'Q', qPattern},           {'R', rPattern},      {'S', sPattern},     {'T', tPattern},
    {'U', uPattern},           {'V', vPattern},      {'W', wPattern},     {'X', xPattern},
    {'Y', yPattern},           {'Z', zPattern},      {' ', spacePattern},

    {'1', onePattern},         {'2', twoPattern},    {'3', threePattern}, {'4', fourPattern},
    {'5', fivePattern},        {'6', sixPattern},    {'7', sevenPattern}, {'8', eightPattern},
    {'9', ninePattern},        {'0', zeroPattern},

    {'.', dotPattern},         {',', commaPattern},  {'-', dashPattern},  {'?', questionPattern},
    {'!', exclamationPattern}, {'\0', emptyPattern},
};
