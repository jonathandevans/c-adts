CC = clang
RM = rm -fr
DFLAG = -g
GFLAGS = -Wall -Wextra
CFLAGS = $(DFLAG) $(GFLAGS)


all: ArrayListTest ArrayQueueTest ArrayStackTest LinkedListTest QueueTest


# Executables

ArrayListTest: array_list.o array_list_test.o
	$(CC) $(CFLAGS) bin/src/array_list.o bin/tests/array_list_test.o -o bin/ArrayListTest

ArrayQueueTest: array_queue.o array_queue_test.o
	$(CC) $(CFLAGS) bin/src/array_queue.o bin/tests/array_queue_test.o -o bin/ArrayQueueTest

ArrayStackTest: array_stack.o array_stack_test.o
	$(CC) $(CFLAGS) bin/src/array_stack.o bin/tests/array_stack_test.o -o bin/ArrayStackTest

LinkedListTest: linked_list.o linked_list_test.o
	$(CC) $(CFLAGS) bin/src/linked_list.o bin/tests/linked_list_test.o -o bin/LinkedListTest

QueueTest: queue.o queue_test.o
	$(CC) $(CFLAGS) bin/src/queue.o bin/tests/queue_test.o -o bin/QueueTest

# Source

array_list.o: src/array_list/array_list.c src/array_list/array_list.h
	mkdir -p bin/src
	$(CC) $(CFLAGS) -c src/array_list/array_list.c -o bin/src/array_list.o

array_queue.o: src/array_queue/array_queue.c src/array_queue/array_queue.h
	mkdir -p bin/src
	$(CC) $(CFLAGS) -c src/array_queue/array_queue.c -o bin/src/array_queue.o

array_stack.o: src/array_stack/array_stack.c src/array_stack/array_stack.h
	mkdir -p bin/src
	$(CC) $(CFLAGS) -c src/array_stack/array_stack.c -o bin/src/array_stack.o

linked_list.o: src/linked_list/linked_list.c src/linked_list/linked_list.h
	mkdir -p bin/src
	$(CC) $(CFLAGS) -c src/linked_list/linked_list.c -o bin/src/linked_list.o

queue.o: src/queue/queue.c src/queue/queue.h
	mkdir -p bin/src
	$(CC) $(CFLAGS) -c src/queue/queue.c -o bin/src/queue.o

# Testing

array_list_test.o: tests/array_list_test.c
	mkdir -p bin/tests
	$(CC) $(CFLAGS) -c tests/array_list_test.c -o bin/tests/array_list_test.o

array_queue_test.o: tests/array_queue_test.c
	mkdir -p bin/tests
	$(CC) $(CFLAGS) -c tests/array_queue_test.c -o bin/tests/array_queue_test.o

array_stack_test.o: tests/array_stack_test.c
	mkdir -p bin/tests
	$(CC) $(CFLAGS) -c tests/array_stack_test.c -o bin/tests/array_stack_test.o

linked_list_test.o: tests/linked_list_test.c
	mkdir -p bin/tests
	$(CC) $(CFLAGS) -c tests/linked_list_test.c -o bin/tests/linked_list_test.o

queue_test.o: tests/queue_test.c
	mkdir -p bin/tests
	$(CC) $(CFLAGS) -c tests/queue_test.c -o bin/tests/queue_test.o

# Clean

clean: 
	$(RM) bin