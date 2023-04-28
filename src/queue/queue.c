/**
 * @file queue.c
 * @brief Queue data type implementation using a node structure
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
 * Creates a new queue using a node structure as the underlying collection.
 * This function uses malloc to allocate memory for the queue.
 * 
 * @return A pointer to the new queue, or NULL if the memory allocation failed.
*/
Queue* new_Queue() {
  Queue* queue = malloc(sizeof(Queue));
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
 * Adds a new element to the queue.
 * The data is stored in the node as a void pointer. Note that the data is not
 * copied, but rather the pointer to the data is stored in the node.
 * 
 * @param Queue* the pointer to the queue.
 * @param void*  the data to be stored in the node.
 * @return true if the node was added successfully, false otherwise.
*/
bool Queue_enqueue(Queue* queue, void* data) {
  // If the queue is NULL, return false.
  if (queue == NULL) {
    return false;
  }

  // Create a new node.
  Queue_Node* new_node = malloc(sizeof(Queue_Node));
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
 * Removes the node at the head of the queue, and returns the stored data.
 * The data is stored in the node as a void pointer. This function returns the
 * data stored in the node, not a copy of the data.
 * 
 * @param Queue* the pointer to the queue.
 * @return the data stored in the node that was removed, or NULL if the queue
 * is empty.
*/
void* Queue_dequeue(Queue* queue) {
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
  Queue_Node* next_node = queue->head->next;

  // Free the head node.
  free(queue->head);

  // Set the head to the next node.
  queue->head = next_node;

  if (queue->size == 1) {
    queue->tail = NULL;
  }

  // Decrement the size of the queue.
  queue->size--;
  return data;
}

/**
 * Peeks at the front of the queue, and returns the stored data.
 * The data is stored in the node as a void pointer. This function returns the
 * data stored in the node, not a copy of the data.
 * 
 * @param Queue* the pointer to the queue.
 * @return the data stored in the node at the head of the queue, or NULL if the
 * queue is empty.
*/
void* Queue_peek(Queue* queue) {
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
 * @param Queue* the pointer to the queue.
 * @return the size of the queue, or -1 if the queue is NULL.
*/
int Queue_size(Queue* queue) {
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
 * @param Queue* the pointer to the queue.
 * @return true if the queue is empty, false otherwise.
*/
bool Queue_isEmpty(Queue* queue) {
  // If the queue is NULL, return true.
  if (queue == NULL) {
    return true;
  }

  // Return true if the size of the queue is 0.
  return queue->size == 0;
}

/**
 * Prints the queue as a list of pointers.
 * 
 * @param Queue* the pointer to the queue.
*/
void Queue_print(Queue* queue) {
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
  Queue_Node* current_node = queue->head;
  // While the next node is not NULL, print the data.
  while (current_node != NULL) {
    printf("%p ", current_node->data);
    current_node = current_node->next;
  }
  // Print a new line.
  printf("]\n");
}

/**
 * Prints the queue as a list of integers.
 * 
 * @param Queue* the pointer to the queue.
*/
void Queue_printInt(Queue* queue) {
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
  Queue_Node* current_node = queue->head;
  // While the next node is not NULL, print the data.
  while (current_node != NULL) {
    printf("%d ", *(int*)current_node->data);
    current_node = current_node->next;
  }
  // Print a new line.
  printf("]\n");
}

/**
 * Clears the queue.
 * 
 * @param Queue* the pointer to the queue.
 * @return true if the queue was cleared successfully, false otherwise.
*/
bool Queue_clear(Queue* queue) {
  // If the queue is NULL, return false.
  if (queue == NULL) {
    return false;
  }

  // If the queue is empty, return true.
  if (queue->size == 0) {
    return true;
  }

  // Get the head of the queue.
  Queue_Node* current_node = queue->head;
  // While the next node is not NULL, free the current node and set the current
  // node to the next node.
  while (current_node != NULL) {
    Queue_Node* next_node = current_node->next;
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
 * @param Queue* the pointer to the queue.
*/
void Queue_free(Queue* queue) {
  // If the queue is NULL, return false.
  if (queue == NULL) {
    return;
  }

  // Free the queue nodes and the queue.
  Queue_clear(queue);
  free(queue);
}