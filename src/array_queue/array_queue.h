/**
 * @file array_queue.h
 * @brief Array queue data type
 * @author Jonathan E
 * @date 07-04-2023
 * 
 * This is an queue data type that can be used to store data in a FIFO data
 * structure.
 * This implementation is a queue that makes use of a dynamic array as 
 * the underlying collection.
*/

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct array_queue {
  void** collection;
  int size;
} array_queue;

/**
 * Creates a new array queue.
 * 
 * @return A pointer to the new array queue.
*/
array_queue* new_array_queue();

/**
 * Adds an element to the end of the queue.
 * 
 * @param queue   The queue to add the element to.
 * @param element The element to add to the queue.
 * @return true if the element was added successfully, false otherwise.
*/
bool array_queue_enqueue(array_queue* queue, void* element);

/**
 * Removes the element at the front of the queue.
 * 
 * @param queue The queue to remove the element from.
 * @return The element that was removed from the queue.
*/
void* array_queue_dequeue(array_queue* queue);

/**
 * Gets the element at the front of the queue, without removing it.
 * 
 * @param queue The queue to get the element from.
 * @return The element at the front of the queue.
*/
void* array_queue_peek(array_queue* queue);

/**
 * Gets the size of the queue.
 * 
 * @param queue The queue to get the size of.
 * @return The size of the queue.
*/
int array_queue_size(array_queue* queue);

/**
 * Checks if the queue is empty.
 * 
 * @param queue The queue to check.
 * @return true if the queue is empty, false otherwise.
*/
bool array_queue_isEmpty(array_queue* queue);

/**
 * Prints the queue as a list of integers.
 * 
 * @param queue  The queue to print.
 * @param print  The function to use to print the elements.
*/
void array_queue_print(array_queue* queue, void (*print)(void*));

/**
 * Clears the queue.
 * 
 * @param queue The queue to clear.
 * @return true if the queue was cleared successfully, false otherwise.
*/
bool array_queue_clear(array_queue* queue);

/**
 * Frees the queue.
 * 
 * @param queue The queue to free.
 * @return true if the queue was freed successfully, false otherwise.
*/
bool array_queue_free(array_queue* queue);

#endif /* ARRAY_QUEUE_H */