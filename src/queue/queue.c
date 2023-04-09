/**
 * @file queue.c
 * @brief Queue data type implementation
 * @author Jonathan E
 * @date 09-04-2023
 * 
 * This is an implementation of a queue data type that can be used to store
 * generic data.
 * This implementation is a queue type that makes use of a node structure
 * as the underlying collection.
 * The data stored in the array is a void pointers which is dynamically allocated
 * to the heap.
*/

#include "queue.h"

/**
 * Creates a new queue, using malloc to allocate memory for the queue.
 * 
 * @return the pointer to the queue, or NULL if the memory allocation
 * failed.
*/
queue* new_queue() {
  queue* queue = malloc(sizeof(queue));
  // If the memory allocation failed, return NULL.
  if (queue == NULL) {
    return NULL;
  }

  // Initialise the queue.
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  return queue;
}

/**
 * Adds a new node to the queue, using malloc to allocate memory for the
 * node.
 * The data is stored in the node as a void pointer. Note that the data is not
 * copied, but rather the pointer to the data is stored in the node.
 * 
 * @param queue the pointer to the queue.
 * @param data the data to be stored in the node.
 * @return true if the node was added successfully, false otherwise.
*/
bool queue_enqueue(queue* queue, void* data) {
  // If the queue is NULL, return false.
  if (queue == NULL) {
    return false;
  }

  // Create a new node.
  queue_node* new_node = malloc(sizeof(queue_node));
  // If the memory allocation failed, return false.
  if (new_node == NULL) {
    return false;
  }

  // Initialise the node.
  new_node->data = data;
  new_node->next = NULL;

  // If the queue is empty, set the head and tail to the new node.
  if (queue->size == 0) {
    queue->head = new_node;
    queue->tail = new_node;
  } else {
    // Otherwise, set the next pointer of the tail to the new node.
    queue->tail->next = new_node;
    // Set the tail to the new node.
    queue->tail = new_node;
  }

  // Increment the size of the queue.
  queue->size++;
  return true;
}

/**
 * Removes the node at the head of the queue.
 * 
 * @param queue the pointer to the queue.
 * @return the data stored in the node that was removed, or NULL if the queue
 * is empty.
*/
void* queue_dequeue(queue* queue) {
  // If the queue is NULL, return NULL.
  if (queue == NULL) {
    return NULL;
  }

  // If the queue is empty, return NULL.
  if (queue->size == 0) {
    return NULL;
  }

  // Get the data from the head of the queue.
  void* data = queue->head->data;

  // Get the next node.
  queue_node* next_node = queue->head->next;

  // Free the head node.
  free(queue->head);

  // Set the head to the next node.
  queue->head = next_node;

  // Decrement the size of the queue.
  queue->size--;
  return data;
}

/**
 * Gets the data stored in the node at the head of the queue.
 * 
 * @param queue the pointer to the queue.
 * @return the data stored in the node at the head of the queue, or NULL if the
 * queue is empty.
*/
void* queue_peek(queue* queue) {
  // If the queue is NULL, return NULL.
  if (queue == NULL) {
    return NULL;
  }

  // If the queue is empty, return NULL.
  if (queue->size == 0) {
    return NULL;
  }

  // Return the data from the head of the queue.
  return queue->head->data;
}

/**
 * Gets the size of the queue.
 * 
 * @param queue the pointer to the queue.
 * @return the size of the queue, or -1 if the queue is NULL.
*/
int queue_size(queue* queue) {
  // If the queue is NULL, return -1.
  if (queue == NULL) {
    return -1;
  }

  // Return the size of the queue.
  return queue->size;
}

/**
 * Checks if the queue is empty.
 * 
 * @param queue the pointer to the queue.
 * @return true if the queue is empty, false otherwise.
*/
bool queue_isEmpty(queue* queue) {
  // If the queue is NULL, return true.
  if (queue == NULL) {
    return true;
  }

  // Return true if the size of the queue is 0.
  return queue->size == 0;
}

/**
 * Prints the queue as a list of integers.
 * 
 * @param queue the pointer to the queue.
*/
void queue_print(queue* queue) {
  // If the queue is NULL, return.
  if (queue == NULL) {
    return;
  }

  // If the queue is empty, return.
  if (queue->size == 0) {
    printf("[]\n");
    return;
  }

  printf("[ ");
  // Get the head of the queue.
  queue_node* current_node = queue->head;
  // While the next node is not NULL, print the data.
  while (current_node != NULL) {
    printf("%i ", *(int*)current_node->data);
    current_node = current_node->next;
  }

  // Print a new line.
  printf("]\n");
}

/**
 * Clears the queue, freeing all the nodes in the queue
 * using free.
 * 
 * @param queue the pointer to the queue.
 * @return true if the queue was cleared successfully, false otherwise.
*/
bool queue_clear(queue* queue) {
  // If the queue is NULL, return false.
  if (queue == NULL) {
    return false;
  }

  // If the queue is empty, return true.
  if (queue->size == 0) {
    return true;
  }

  // Get the head of the queue.
  queue_node* current_node = queue->head;
  // While the next node is not NULL, free the current node and set the current
  // node to the next node.
  while (current_node != NULL) {
    queue_node* next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }

  // Set the head and tail to NULL.
  queue->head = NULL;
  queue->tail = NULL;

  // Set the size of the queue to 0.
  queue->size = 0;
  return true;
}

/**
 * Frees the memory allocated for the queue.
 * 
 * @param queue the pointer to the queue.
 * @return true if the queue was freed successfully, false otherwise.
*/
bool queue_free(queue* queue) {
  // If the queue is NULL, return false.
  if (queue == NULL) {
    return true;
  }

  // Free the queue nodes and the queue.
  queue_clear(queue);
  free(queue);
  return true;
}