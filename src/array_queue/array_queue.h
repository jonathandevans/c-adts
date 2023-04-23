/**
 * @file array_queue.h
 * @brief Array queue data type implementation using a dynamic array
 * @author Jonathan E
 * @date 07-04-2023
 * 
 * This is a queue data type that can be used to store data in a FIFO data
 * structure.
 * This implementation is a queue that makes use of a dynamic array as 
 * the underlying collection.
 * The data stored in the array is a void pointers which is dynamically allocated
 * to the heap.
*/

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ArrayQueue {
  void** collection;
  int size;
} ArrayQueue;

/**
 * Creates a new queue using a dynamic array as the underlying collection.
 * 
 * @return A pointer to the new array queue.
*/
ArrayQueue* new_ArrayQueue();

/**
 * Adds an element to the end of the queue.
 * The data is stored in a dynamic array. Note that the data is not
 * copied, but rather the pointer to the data is copied.
 * 
 * @param ArrayQueue* The queue to add the element to.
 * @param void*       The element to add to the queue.
 * @return true if the element was added successfully, false otherwise.
*/
bool ArrayQueue_enqueue(ArrayQueue*, void*);

/**
 * Removes the element at the front of the queue.
 * The data is stored in a dynamic array. Note that the data is not
 * copied, but rather the pointer to the data is copied.
 * 
 * @param Queue* The queue to remove the element from.
 * @return The element that was removed from the queue.
*/
void* ArrayQueue_dequeue(ArrayQueue*);

/**
 * Peeks at the element at the front of the queue.
 * The data is stored in a dynamic array. This function returns the pointer
 * to the data, not a copy of the data.
 * 
 * @param ArrayQueue* The queue to get the element from.
 * @return The element at the front of the queue.
*/
void* ArrayQueue_peek(ArrayQueue*);

/**
 * Gets the size of the queue.
 * 
 * @param ArrayQueue* The queue to get the size of.
 * @return The size of the queue.
*/
int ArrayQueue_size(ArrayQueue*);

/**
 * Checks if the queue is empty.
 * 
 * @param ArrayQueue* The queue to check.
 * @return true if the queue is empty, false otherwise.
*/
bool ArrayQueue_isEmpty(ArrayQueue*);

/**
 * Prints the queue as a list of pointers.
 * 
 * @param ArrayQueue* The queue to print.
*/
void ArrayQueue_print(ArrayQueue*);

/**
 * Prints the queue as a list of integers.
 * 
 * @param ArrayQueue* The queue to print.
*/
void ArrayQueue_printInt(ArrayQueue*);

/**
 * Clears the queue.
 * 
 * @param ArrayQueue* The queue to clear.
 * @return true if the queue was cleared successfully, false otherwise.
*/
bool ArrayQueue_clear(ArrayQueue*);

/**
 * Frees the memory allocated for the queue.
 * 
 * @param ArrayQueue* The queue to free.
*/
void ArrayQueue_free(ArrayQueue*);

#endif /* ARRAY_QUEUE_H */