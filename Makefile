## This makefile is only intended for tests. The actual build is done via IDE without using this makefile.
CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wstrict-prototypes -Wmissing-prototypes -Iinclude -g -O0
TEST_CFLAGS := $(CFLAGS) -Itests
SRC := $(wildcard src/*.c)
TEST_SRC := $(filter-out src/hal.c src/main.c, $(SRC)) $(wildcard tests/*.c)
TEST_BIN := morse_tests/morse_tests
.PHONY: compile_tests tests clean debug format

compile_tests:
	mkdir -p morse_tests 
	$(CC) $(TEST_CFLAGS) $(TEST_SRC) -o $(TEST_BIN)

tests: compile_tests
	./$(TEST_BIN)

debug: tests
	gdb $(TEST_BIN)

clean:
	rm -f $(TEST_BIN)

format:
	clang-format -i src/*.c include/*.h tests/*.c tests/*.h
