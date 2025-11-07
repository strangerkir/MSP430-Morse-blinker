#ifndef ITERATOR_H
#define ITERATOR_H

typedef void (*FuncPtr)(void);

struct Caller {
    unsigned short idx;
    const FuncPtr* fp;
    FuncPtr next;

};

void initializeCaller();

extern struct Caller caller;

#endif
