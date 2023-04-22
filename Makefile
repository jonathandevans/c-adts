CC = clang
RM = rm -fr
DFLAG = -g
GFLAGS = -Wall -Wextra
CFLAGS = $(DFLAG) $(GFLAGS)


all: ArrayListTest


# Executables

ArrayListTest: array_list.o array_list_test.o
	$(CC) $(CFLAGS) bin/src/array_list.o bin/tests/array_list_test.o -o bin/ArrayListTest


# Source

array_list.o: src/array_list/array_list.c src/array_list/array_list.h
	mkdir -p bin/src
	$(CC) $(CFLAGS) -c src/array_list/array_list.c -o bin/src/array_list.o


# Testing

array_list_test.o: tests/array_list_test.c
	mkdir -p bin/tests
	$(CC) $(CFLAGS) -c tests/array_list_test.c -o bin/tests/array_list_test.o


# Clean
clean: 
	$(RM) bin