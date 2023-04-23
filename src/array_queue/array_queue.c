/**
 * @file array_queue.c
 * @brief Array queue data type implementation
 * @author Jonathan E
 * @date 08-04-2023
 * 
 * This is an implementation of an array queue data type that can be used to store
 * generic data.
 * This implementation is a queue type that makes use of a dynamic array
 * as the underlying collection.
 * The data stored in the array is a void pointers which is dynamically allocated
 * to the heap.
*/

#include "array_queue.h"

/**
 * Creates a new queue using a dynamic array as the underlying collection.
 * This function uses malloc to allocate memory for the queue.
 * 
 * @return the pointer to the array queue, or NULL if the memory allocation
 *         failed.
*/
ArrayQueue* new_ArrayQueue() {
  ArrayQueue* queue = malloc(sizeof(ArrayQueue));
  // If the memory allocation failed, return NULL.
  if (queue == NULL) {
    return NULL;
  }
  
  // Initialise the queue.
  queue->collection = NULL;
  queue->size = 0;
  return queue;
}

/**
 * Adds a new element to the queue.
 * The data is stored in a dynamic array. Note that the data is not
 * copied, but rather the pointer to the data is stored in the array.
 * 
 * @param Queue* the pointer to the array queue.
 * @param void*  the data to be stored in the node.
 * @return true if the node was added successfully, false otherwise.
*/
bool ArrayQueue_enqueue(ArrayQueue* queue, void* data) {
  // If the queue is NULL, return false.
  if (queue == NULL) {
    return false;
  }

  // If the size is 0, then the collection is empty.
  if (queue->size == 0) {
    void** new_collection = malloc(sizeof(void*));
    // If the memory allocation failed, return false.
    if (new_collection == NULL) {
      return false;
    }
    new_collection[0] = data;
    queue->collection = new_collection;
    queue->size++;
    return true;
  }

  // If the size is greater than 0, then the collection is not empty.
  if (queue->size > 0) {
    void** new_collection = realloc(queue->collection, sizeof(void*) * (queue->size + 1));
    // If the memory allocation failed, return false.
    if (new_collection == NULL) {
      return false;
    }

    // Add the data to the new collection.
    new_collection[queue->size] = data;
    // Increment the size.
    queue->size++;
    queue->collection = new_collection;

    return true;
  }

  // If the code reaches this point, then the code is invalid.
  return false;
}

/**
 * Removes the element at the front of the queue and returns the data stored.
 * The data is stored in a dynamic array. This function returns the pointer stored
 * in the array, not a copy of the data.
 * 
 * @param ArrayQueue* the pointer to the array queue.
 * @return the data stored in the first node, or NULL if the queue is empty.
*/
void* ArrayQueue_dequeue(ArrayQueue* queue) {
  // If the queue is NULL, return NULL.
  if (queue == NULL) {
    return NULL;
  }

  // If the collection is NULL, return NULL.
  if (queue->collection == NULL) {
    return NULL;
  }

  // If the size is 0, then the collection is empty.
  if (queue->size == 0) {
    return NULL;
  }

  if (queue->size == 1) {
    void* data = queue->collection[0];
    free(queue->collection);
    queue->collection = NULL;
    queue->size--;
    return data;
  }

  // If the size is greater than 0, then the collection is not empty.
  if (queue->size > 0) {
    void* data = queue->collection[0];

    void** new_collection = malloc(sizeof(void*) * (queue->size - 1));
    // If the memory allocation failed, return NULL.
    if (new_collection == NULL) {
      return NULL;
    }

    // Copy the data from the old collection to the new collection.
    memcpy(new_collection, &queue->collection[1], sizeof(void*) * (queue->size - 1));

    free(queue->collection);

    // Set the collection to the new collection.
    queue->collection = new_collection;
    // Decrement the size.
    queue->size--;
    return data;
  }

  // If the size is less than 0, then the size is invalid.
  if (queue->size < 0) {
    return NULL;
  }

  // If the code reaches this point, then the code is invalid.
  return NULL;
}

/**
 * Peeks at the front of the queue and returns the data stored.
 * The data is stored in a dynamic array. This function returns the pointer stored
 * in the array, not a copy of the data.
 * 
 * @param ArrayQueue* the pointer to the array queue.
 * @return the data stored in the first node, or NULL if the queue is empty.
*/
void* ArrayQueue_peek(ArrayQueue* queue) {
  // If the queue is NULL, return NULL.
  if (queue == NULL) {
    return NULL;
  }

  // If the collection is NULL, return NULL.
  if (queue->collection == NULL) {
    return NULL;
  }

  // If the size is 0, then the collection is empty.
  if (queue->size == 0) {
    return NULL;
  }

  // If the size is greater than 0, then the collection is not empty.
  if (queue->size > 0) {
    return queue->collection[0];
  }

  // If the size is less than 0, then the size is invalid.
  if (queue->size < 0) {
    return NULL;
  }

  // If the code reaches this point, then the code is invalid.
  return NULL;
}

/**
 * Returns the size of the queue.
 * 
 * @param ArrayQueue* the pointer to the array queue.
 * @return the size of the array queue, or -1 if the queue is NULL.
*/
int ArrayQueue_size(ArrayQueue* queue) {
  // If the queue is NULL, return -1.
  if (queue == NULL) {
    return -1;
  }

  return queue->size;
}

/**
 * Returns true if the array queue is empty, false otherwise.
 * 
 * @param ArrayQueue* the pointer to the array queue.
 * @return true if the array queue is empty, false otherwise.
*/
bool ArrayQueue_isEmpty(ArrayQueue* queue) {
  // If the queue is NULL, return true.
  if (queue == NULL) {
    return true;
  }

  // If the size is 0, then the collection is empty.
  if (queue->size == 0) {
    return true;
  }

  // If the size is greater than 0, then the collection is not empty.
  if (queue->size > 0) {
    return false;
  }

  // If the size is less than 0, then the size is invalid.
  if (queue->size < 0) {
    return true;
  }

  // If the code reaches this point, then the code is invalid.
  return true;
}

/**
 * Prints the array queue as a list of pointers.
 * 
 * @param ArrayQueue* the pointer to the array queue.
*/
void ArrayQueue_print(ArrayQueue* queue) {
  // If the queue is NULL, return.
  if (queue == NULL) {
    printf("[]\n");
    return;
  }

  // If the collection is NULL, return.
  if (queue->collection == NULL) {
    return;
  }

  // If the size is 0, then the collection is empty.
  if (queue->size == 0) {
    printf("[]\n");
    return;
  }

  // If the size is greater than 0, then the collection is not empty.
  if (queue->size > 0) {
    printf("[");
    for (int i = 0; i < queue->size; i++) {
      printf("%p ", queue->collection[i]);
      if (i < queue->size - 1) {
        printf(", ");
      }
    }
    printf("]\n");
    return;
  }

  // If the size is less than 0, then the size is invalid.
  if (queue->size < 0) {
    return;
  }

  // If the code reaches this point, then the code is invalid.
  return;
}

/**
 * Prints the array queue as a list of integers.
 * 
 * @param ArrayQueue* the pointer to the array queue.
*/
void ArrayQueue_printInt(ArrayQueue* queue) {
  // If the queue is NULL, return.
  if (queue == NULL) {
    printf("[]\n");
    return;
  }

  // If the collection is NULL, return.
  if (queue->collection == NULL) {
    return;
  }

  // If the size is 0, then the collection is empty.
  if (queue->size == 0) {
    printf("[]\n");
    return;
  }

  // If the size is greater than 0, then the collection is not empty.
  if (queue->size > 0) {
    printf("[");
    for (int i = 0; i < queue->size; i++) {
      printf("%d ", *(int*)queue->collection[i]);
      if (i < queue->size - 1) {
        printf(", ");
      }
    }
    printf("]\n");
    return;
  }

  // If the size is less than 0, then the size is invalid.
  if (queue->size < 0) {
    return;
  }

  // If the code reaches this point, then the code is invalid.
  return;
}

/**
 * Clears the array queue.
 * 
 * @param ArrayQueue* the pointer to the array queue.
 * @return true if the array queue was cleared, false otherwise.
*/
bool ArrayQueue_clear(ArrayQueue* queue) {
  // If the queue is NULL, return false.
  if (queue == NULL) {
    return false;
  }

  // If the collection is NULL, return false.
  if (queue->collection == NULL) {
    return false;
  }

  // If the size is 0, then the collection is empty.
  if (queue->size == 0) {
    return true;
  }

  // If the size is greater than 0, then the collection is not empty.
  if (queue->size > 0) {
    // Free the collection.
    free(queue->collection);
    // Set the collection to NULL.
    queue->collection = NULL;
    // Set the size to 0.
    queue->size = 0;
    return true;
  }

  // If the size is less than 0, then the size is invalid.
  if (queue->size < 0) {
    return false;
  }

  // If the code reaches this point, then the code is invalid.
  return false;
}

/**
 * Frees the memory allocated to the queue.
 * 
 * @param ArrayQueue the pointer to the array queue.
 * @return true if the array queue was freed, false otherwise.
*/
void ArrayQueue_free(ArrayQueue* queue) {
  // If the queue is NULL, return false.
  if (queue == NULL) {
    return;
  }

  // If the collection is empty, free the queue and return.
  if (queue->size == 0) {
    free(queue);
    return;
  }


  // Free the collection.
  free(queue->collection);
  // Set the collection to NULL.
  queue->collection = NULL;
  // Free the queue.
  free(queue);
}
