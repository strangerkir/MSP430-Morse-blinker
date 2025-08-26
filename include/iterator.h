#ifndef ITERATOR_H
#define ITERATOR_H

typedef void (*FuncPtr)(void);

struct Caller {
    unsigned short idx;
    FuncPtr *fp;
    FuncPtr next;

};

void initializeCaller(FuncPtr fp[]);

extern struct Caller caller;

#endif
