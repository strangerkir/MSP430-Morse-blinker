#ifndef CHAR_ITERATOR_H
#define CHAR_ITERATOR_H

#include <stdbool.h>

typedef struct {
    char text[1024];
    int pos;
 } CharIterator;

void CharIterator_init(CharIterator *st, char *text);

bool CharIterator_emit(CharIterator *st);

extern CharIterator charIterator;
 
#endif
