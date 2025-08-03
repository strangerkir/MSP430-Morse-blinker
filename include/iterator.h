#ifndef ITERATOR_H
#define ITERATOR_H

typedef void (*FuncPtr)(void);

struct Caller {
    unsigned short idx;
    unsigned short size;
    FuncPtr *fp;
    FuncPtr next;

};

void initializeCaller(FuncPtr fp[], short unsigned size);

extern struct Caller caller;

#endif
