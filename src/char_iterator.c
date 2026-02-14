/**
 * Logic of iterating over characters
 */

#include <string.h>
#include "../include/char_iterator.h"

CharIterator charIterator;

void CharIterator_init(CharIterator *charIterator, char *text){
    charIterator->len = strlen(text);
    charIterator->pos = 0;
    strcpy(charIterator->text, text);
}

bool CharIterator_emit(CharIterator *st) {
    if(st->pos >= st->len) {
        return false; //End of the string
    }

    //todo: call SignalsIterator here

    st->pos++;
    return true;
}
