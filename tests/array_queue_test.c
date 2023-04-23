/**
 * @file array_queue_test.c
 * @brief Test file for array_queue.c
 * @author Jonathan E
 * @date 23-04-2023
 * 
 * This file contains the test functions for array_queue.c.
 * By running this file, you can test the functions in array_queue.c with
 * the test cases outputted to the console.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../src/array_queue/array_queue.h"

/**
 * Test function for new_ArrayQueue().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_new_ArrayQueue() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  if (queue->size != 0) {
    return false;
  }

  ArrayQueue_free(queue);
  return true;
}

/**
 * Test function for ArrayQueue_enqueue().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_ArrayQueue_enqueue() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  // Add an element to the queue.
  int* data = malloc(sizeof(int));
  *data = 1;
  bool result = ArrayQueue_enqueue(queue, data);
  if (result == false) {
    return false;
  }
  if (queue->size != 1) {
    return false;
  }
  if (*(int*)queue->collection[0] != 1) {
    return false;
  }

  ArrayQueue_free(queue);
  return true;
}

bool test_ArrayQueue_enqueue_multiple() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  // Add an element to the queue.
  int* data = malloc(sizeof(int));
  *data = 1;
  bool result = ArrayQueue_enqueue(queue, data);
  if (result == false) {
    return false;
  }
  if (queue->size != 1) {
    return false;
  }
  if (*(int*)queue->collection[0] != 1) {
    return false;
  }

  // Add another element to the queue.
  int* data2 = malloc(sizeof(int));
  *data2 = 2;
  result = ArrayQueue_enqueue(queue, data2);
  if (result == false) {
    return false;
  }
  if (queue->size != 2) {
    return false;
  }
  if (*(int*)queue->collection[0] != 1) {
    return false;
  }
  if (*(int*)queue->collection[1] != 2) {
    return false;
  }

  ArrayQueue_free(queue);
  return true;
}

bool test_ArrayQueue_enqueue_to_null() {
  ArrayQueue* queue = NULL;
  int* data = malloc(sizeof(int));
  *data = 1;
  bool result = ArrayQueue_enqueue(queue, data);
  if (result == true) {
    return false;
  }
  return true;
}

/**
 * Test function for ArrayQueue_dequeue().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_ArrayQueue_dequeue() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  // Add an element to the queue.
  int* data = malloc(sizeof(int));
  *data = 1;
  ArrayQueue_enqueue(queue, data);

  // Dequeue the element.
  int* dequeued_data = ArrayQueue_dequeue(queue);
  if (dequeued_data == NULL) {
    return false;
  }
  if (queue->size != 0) {
    return false;
  }
  if (*dequeued_data != 1) {
    return false;
  }

  ArrayQueue_free(queue);
  return true;
}

bool test_ArrayQueue_dequeue_multiple() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  // Add an element to the queue.
  int data = 1;
  ArrayQueue_enqueue(queue, &data);

  // Add another element to the queue.
  int data2 = 2;
  ArrayQueue_enqueue(queue, &data2);

  // Dequeue the element.
  int* dequeued_data = ArrayQueue_dequeue(queue);
  if (dequeued_data == NULL) {
    return false;
  }
  if (queue->size != 1) {
    return false;
  }
  if (*dequeued_data != 1) {
    return false;
  }

  // Dequeue the element.
  int* dequeued_data2 = ArrayQueue_dequeue(queue);

  if (dequeued_data2 == NULL) {
    return false;
  }
  if (queue->size != 0) {
    return false;
  }
  if (*dequeued_data2 != 2) {
    return false;
  }

  ArrayQueue_free(queue);
  return true;
}

bool test_ArrayQueue_dequeue_from_null() {
  ArrayQueue* queue = NULL;
  int* dequeued_data = ArrayQueue_dequeue(queue);
  if (dequeued_data != NULL) {
    return false;
  }
  return true;
}

bool test_ArrayQueue_dequeue_from_empty() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  int* dequeued_data = ArrayQueue_dequeue(queue);
  if (dequeued_data != NULL) {
    return false;
  }
  return true;
}

/**
 * Test function for ArrayQueue_peek().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_ArrayQueue_peek() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  // Add an element to the queue.
  int* data = malloc(sizeof(int));
  *data = 1;
  ArrayQueue_enqueue(queue, data);

  // Peek at the element.
  int* peeked_data = ArrayQueue_peek(queue);
  if (peeked_data == NULL) {
    return false;
  }
  if (*peeked_data != 1) {
    return false;
  }

  ArrayQueue_free(queue);
  return true;
}

bool test_ArrayQueue_peek_multiple() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  // Add an element to the queue.
  int* data = malloc(sizeof(int));
  *data = 1;
  ArrayQueue_enqueue(queue, data);

  // Add another element to the queue.
  int* data2 = malloc(sizeof(int));
  *data2 = 2;
  ArrayQueue_enqueue(queue, data2);

  // Peek at the element.
  int* peeked_data = ArrayQueue_peek(queue);
  if (peeked_data == NULL) {
    return false;
  }
  if (*peeked_data != 1) {
    return false;
  }

  ArrayQueue_free(queue);
  return true;
}

bool test_ArrayQueue_peek_from_null() {
  ArrayQueue* queue = NULL;
  int* peeked_data = ArrayQueue_peek(queue);
  if (peeked_data != NULL) {
    return false;
  }
  return true;
}

bool test_ArrayQueue_peek_from_empty() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  int* peeked_data = ArrayQueue_peek(queue);
  if (peeked_data != NULL) {
    return false;
  }
  return true;
}

/**
 * Test function for ArrayQueue_size().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_ArrayQueue_size() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  // Add an element to the queue.
  int* data = malloc(sizeof(int));
  *data = 1;
  ArrayQueue_enqueue(queue, data);

  // Check the size.
  int size = ArrayQueue_size(queue);
  if (size != 1) {
    return false;
  }

  ArrayQueue_free(queue);
  return true;
}

bool test_ArrayQueue_size_multiple() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  // Add an element to the queue.
  int* data = malloc(sizeof(int));
  *data = 1;
  ArrayQueue_enqueue(queue, data);

  // Add another element to the queue.
  int* data2 = malloc(sizeof(int));
  *data2 = 2;
  ArrayQueue_enqueue(queue, data2);

  // Check the size.
  int size = ArrayQueue_size(queue);
  if (size != 2) {
    return false;
  }

  ArrayQueue_free(queue);
  return true;
}

bool test_ArrayQueue_size_from_null() {
  ArrayQueue* queue = NULL;
  int size = ArrayQueue_size(queue);
  if (size != -1) {
    return false;
  }
  return true;
}

bool test_ArrayQueue_size_from_empty() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  int size = ArrayQueue_size(queue);
  if (size != 0) {
    return false;
  }
  return true;
}

/**
 * Test function for ArrayQueue_isEmpty().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_ArrayQueue_isEmpty() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  // Check if the queue is empty.
  bool isEmpty = ArrayQueue_isEmpty(queue);
  if (!isEmpty) {
    return false;
  }

  ArrayQueue_free(queue);
  return true;
}

bool test_ArrayQueue_isEmpty_multiple() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  // Add an element to the queue.
  int* data = malloc(sizeof(int));
  *data = 1;
  ArrayQueue_enqueue(queue, data);

  // Check if the queue is empty.
  bool isEmpty = ArrayQueue_isEmpty(queue);
  if (isEmpty) {
    return false;
  }

  ArrayQueue_free(queue);
  return true;
}

bool test_ArrayQueue_isEmpty_from_null() {
  ArrayQueue* queue = NULL;
  bool isEmpty = ArrayQueue_isEmpty(queue);
  if (!isEmpty) {
    return false;
  }
  return true;
}

/**
 * Test function for ArrayQueue_clear().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_ArrayQueue_clear() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  // Add an element to the queue.
  int* data = malloc(sizeof(int));
  *data = 1;
  ArrayQueue_enqueue(queue, data);

  // Clear the queue.
  ArrayQueue_clear(queue);

  // Check if the queue is empty.
  bool isEmpty = ArrayQueue_isEmpty(queue);
  if (!isEmpty) {
    return false;
  }

  ArrayQueue_free(queue);
  return true;
}

bool test_ArrayQueue_clear_multiple() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  // Add an element to the queue.
  int* data = malloc(sizeof(int));
  *data = 1;
  ArrayQueue_enqueue(queue, data);

  // Add another element to the queue.
  int* data2 = malloc(sizeof(int));
  *data2 = 2;
  ArrayQueue_enqueue(queue, data2);

  // Clear the queue.
  ArrayQueue_clear(queue);

  // Check if the queue is empty.
  bool isEmpty = ArrayQueue_isEmpty(queue);
  if (!isEmpty) {
    return false;
  }

  ArrayQueue_free(queue);
  return true;
}

bool test_ArrayQueue_clear_from_null() {
  ArrayQueue* queue = NULL;
  ArrayQueue_clear(queue);
  return true;
}

bool test_ArrayQueue_clear_from_empty() {
  ArrayQueue* queue = new_ArrayQueue();
  if (queue == NULL) {
    return false;
  }

  ArrayQueue_clear(queue);
  return true;
}

/**
 * Main function used to run the tests.
*/
int main() {
  printf("Running unit tests for ArrayQueue.h...\n");

  printf("\ttesting new_ArrayQueue()..............................%s\n", test_new_ArrayQueue() ? "PASS" : "FAIL");

  printf("\ttesting ArrayQueue_enqueue()..........................%s\n", test_ArrayQueue_enqueue() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_enqueue() with multiple elements...%s\n", test_ArrayQueue_enqueue_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_enqueue() with NULL queue..........%s\n", test_ArrayQueue_enqueue_to_null() ? "PASS" : "FAIL");

  printf("\ttesting ArrayQueue_dequeue()..........................%s\n", test_ArrayQueue_dequeue() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_dequeue() with multiple elements...%s\n", test_ArrayQueue_dequeue_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_dequeue() with NULL queue..........%s\n", test_ArrayQueue_dequeue_from_null() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_dequeue() from empty queue.........%s\n", test_ArrayQueue_dequeue_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting ArrayQueue_peek().............................%s\n", test_ArrayQueue_peek() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_peek() with multiple elements......%s\n", test_ArrayQueue_peek_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_peek() with NULL queue.............%s\n", test_ArrayQueue_peek_from_null() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_peek() from empty queue............%s\n", test_ArrayQueue_peek_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting ArrayQueue_size().............................%s\n", test_ArrayQueue_size() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_size() with multiple elements......%s\n", test_ArrayQueue_size_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_size() with NULL queue.............%s\n", test_ArrayQueue_size_from_null() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_size() from empty queue............%s\n", test_ArrayQueue_size_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting ArrayQueue_isEmpty()..........................%s\n", test_ArrayQueue_isEmpty() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_isEmpty() with multiple elements...%s\n", test_ArrayQueue_isEmpty_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_isEmpty() with NULL queue..........%s\n", test_ArrayQueue_isEmpty_from_null() ? "PASS" : "FAIL");

  printf("\ttesting ArrayQueue_clear()............................%s\n", test_ArrayQueue_clear() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_clear() with multiple elements.....%s\n", test_ArrayQueue_clear_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_clear() with NULL queue............%s\n", test_ArrayQueue_clear_from_null() ? "PASS" : "FAIL");
  printf("\ttesting ArrayQueue_clear() from empty queue...........%s\n", test_ArrayQueue_clear_from_empty() ? "PASS" : "FAIL");

  printf("Unit tests complete.\n");
}
