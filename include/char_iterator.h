#ifndef CHAR_ITERATOR_H
#define CHAR_ITERATOR_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    char text[1024];
    size_t len;
    size_t pos;
 } CharIterator;

void CharIterator_init(CharIterator *st, char *text);

bool CharIterator_emit(CharIterator *st);

extern CharIterator charIterator;
 
#endif
