 #include "char-signals_map.h"
 #include "iterator.h"
 

 int test_toUpper(void);
 int test_getNextChar();

 int runUnitTests() {
    return test_toUpper() + 
        test_getNextChar();
 }

 int test_toUpper(void) {
    short failed = 0;
    if (toUpper('c') != 'C') {
        failed++;
    }

    if (toUpper('a') != 'A') {
        failed++;
    }

    if (toUpper('Z') != 'Z') {
        failed++;
    }

    if (toUpper(',') != ',') {
        failed++;
    }

    if (toUpper(' ') != ' ') {
        failed++;
    }

    return failed;
}

int test_getNextChar() {
    short failed = 0;
    // Just check it returns next letter every time.
    if (getNextChar() != 'S') {
        failed++;
    }

    if (getNextChar() != 'o') {
        failed++;
    }

    return failed;
}
