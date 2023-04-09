/**
 * @file queue.h
 * @brief Queue data type
 * @author Jonathan E
 * @date 09-04-2023
 * 
 * This is an queue data type that can be used to store data in a FIFO data
 * structure.
 * This implementation is a queue that makes use of a node structure as 
 * the underlying collection.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct queue_node {
    void *data;
    struct queue_node *next;
} queue_node;

typedef struct queue {
    queue_node *head;
    queue_node *tail;
    int size;
} queue;

/**
 * Creates a new queue.
 * 
 * @return A pointer to the new queue.
*/
queue* new_queue();

/**
 * Adds an element to the queue.
 * 
 * @param queue The queue to add the element to.
 * @param data  The data to add to the queue.
 * @return true if the element was added successfully, false otherwise.
*/
bool queue_enqueue(queue *queue, void *data);

/**
 * Removes an element from the queue.
 * 
 * @param queue The queue to remove the element from.
 * @return The data that was removed from the queue.
*/
void* queue_dequeue(queue *queue);

/**
 * Gets the element at the front of the queue, without removing it.
 * 
 * @param queue The queue to get the element from.
 * @return The data at the front of the queue.
*/
void* queue_peek(queue *queue);

/**
 * Gets the size of the queue.
 * 
 * @param queue The queue to get the size of.
 * @return The size of the queue.
*/
int queue_size(queue *queue);

/**
 * Checks if the queue is empty.
 * 
 * @param queue The queue to check.
 * @return true if the queue is empty, false otherwise.
*/
bool queue_isEmpty(queue *queue);

/**
 * Prints the queue as a list of integers.
 * 
 * @param queue The queue to print.
*/
void queue_print(queue *queue);

/**
 * Clears the queue.
 * 
 * @param queue The queue to clear.
 * @return true if the queue was cleared successfully, false otherwise.
*/
bool queue_clear(queue *queue);

/**
 * Frees the queue.
 * 
 * @param queue The queue to free.
 * @return true if the queue was freed successfully, false otherwise.
*/
bool queue_free(queue *queue);

#endif /* QUEUE_H */