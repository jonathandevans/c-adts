/**
 * @file queue.h
 * @brief Queue data type implementation using a node structure
 * @author Jonathan E
 * @date 09-04-2023
 * 
 * This is an queue data type that can be used to store data in a FIFO data
 * structure.
 * This implementation is a stack data type that makes use of a series of nodes
 * as the underlying collection.
 * The data stored in the nodes are void pointers which are dynamically allocated
 * to the heap.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Queue_Node {
  void *data;
  struct Queue_Node *next;
} Queue_Node;

typedef struct Queue {
  Queue_Node *head;
  Queue_Node *tail;
  int size;
} Queue;

/**
 * Creates a new queue using a series of nodes as the underlying collection.
 * 
 * @return A pointer to the new queue.
*/
Queue* new_Queue();

/**
 * Adds an element to the end of the queue.
 * The data is stored as a node in a series of nodes. Note that the data is not
 * copied, but rather the pointer to the data is copied.
 * 
 * @param Queue* The queue to add the element to.
 * @param void*  The data to add to the queue.
 * @return true if the element was added successfully, false otherwise.
*/
bool Queue_enqueue(Queue*, void*);

/**
 * Removes an element from the queue.
 * The data is stored as a node in a series of nodes. Note that the data is not
 * copied, but rather the pointer to the data is copied.
 * 
 * @param Queue* The queue to remove the element from.
 * @return The data that was removed from the queue.
*/
void* Queue_dequeue(Queue*);

/**
 * Peeks at the first element in the queue.
 * The data is stored as a node in a series of nodes. This function returns the
 * pointer to the data, not a copy of the data.
 * 
 * @param Queue* The queue to get the element from.
 * @return The data at the front of the queue.
*/
void* Queue_peek(Queue*);

/**
 * Gets the size of the queue.
 * 
 * @param Queue* The queue to get the size of.
 * @return The size of the queue.
*/
int Queue_size(Queue*);

/**
 * Checks if the queue is empty.
 * 
 * @param Queue* The queue to check if it is empty.
 * @return true if the queue is empty, false otherwise.
*/
bool Queue_isEmpty(Queue*);

/**
 * Prints the queue as a list of pointers.
 * 
 * @param Queue* The queue to print.
*/
void Queue_print(Queue*);

/**
 * Prints the queue as a list of integers.
 * 
 * @param Queue* The queue to print.
*/
void Queue_printInt(Queue*);

/**
 * Clears the given queue.
 * 
 * @param Queue* The queue to clear.
 * @return true if the queue was cleared successfully, false otherwise.
*/
bool Queue_clear(Queue*);

/**
 * Frees the memory allocated for the queue.
 * 
 * @param queue The queue to free.
*/
void Queue_free(Queue*);

#endif /* QUEUE_H */