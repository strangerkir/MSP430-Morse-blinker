#include <stdio.h>
#include "char-signals_map.h"
#include "iterator.h"

int test_toUpper(void) {
    if(toUpper('c') != 'C') {
        return 1;
    }

    if(toUpper('a') != 'A') {
        return 1;
    }

    if(toUpper('Z') != 'Z') {
        return 1;
    }
}

int main(void) {
    int executed = 0;
    int failed = 0;

    failed += test_toUpper();


    printf("Total tests executed:%d\n", executed);
    printf("Failed tests:%d\n", failed);

    return failed != 0;
}

