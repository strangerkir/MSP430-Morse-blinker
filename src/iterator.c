/**
 * Logic of iterating through individual signals.
 */

 #include "iterator.h"

struct Caller caller;

void callNext() {

    if(caller.idx >= caller.size) {
        caller.idx = 0;
    }

    caller.fp[caller.idx]();
    caller.idx ++;

}

void initializeCaller(FuncPtr fp[], short unsigned size) {
    caller.idx = 0;
    caller.size = size;
    caller.fp = fp;
    caller.next = callNext;
}