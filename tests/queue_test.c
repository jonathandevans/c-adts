/**
 * @file queue_test.c
 * @brief Test file for queue.c
 * @author Jonathan E
 * @date 28-04-2023
 * 
 * This file contains tests functions for queue.c.
 * By running this file, you can test the functions in queue.c with the
 * test cases outputted to the console.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../src/queue/queue.h"

/**
 * Test function for new_Queue().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_new_Queue() {
  Queue *queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  if (queue->head != NULL) {
    return false;
  }

  if (queue->tail != NULL) {
    return false;
  }

  if (queue->size != 0) {
    return false;
  }

  Queue_free(queue);
  return true;
}

/**
 * Test function for Queue_enqueue().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_Queue_enqueue() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  int data = 5;

  if (!Queue_enqueue(queue, &data)) {
    return false;
  }

  if (queue->head == NULL) {
    return false;
  }

  if (queue->tail == NULL) {
    return false;
  }

  if (queue->size != 1) {
    return false;
  }

  if (queue->head->data != &data) {
    return false;
  }

  if (queue->tail->data != &data) {
    return false;
  }

  Queue_free(queue);
  return true;
}

bool test_Queue_enqueue_multiple() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  int data1 = 5;
  int data2 = 10;
  int data3 = 15;

  if (!Queue_enqueue(queue, &data1)) {
    return false;
  }

  if (!Queue_enqueue(queue, &data2)) {
    return false;
  }

  if (!Queue_enqueue(queue, &data3)) {
    return false;
  }

  if (queue->head == NULL) {
    return false;
  }

  if (queue->tail == NULL) {
    return false;
  }

  if (queue->size != 3) {
    return false;
  }

  if (queue->head->data != &data1) {
    return false;
  }

  if (queue->tail->data != &data3) {
    return false;
  }

  Queue_free(queue);
  return true;
}

bool test_Queue_enqueue_to_null() {
  Queue* queue = NULL;

  int data = 5;

  if (Queue_enqueue(queue, &data)) {
    return false;
  }

  return true;
}

/**
 * Test function for Queue_dequeue().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_Queue_dequeue() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  int data = 5;
  Queue_enqueue(queue, &data);

  void *dequeue_data = Queue_dequeue(queue);
  if (dequeue_data == NULL) {
    return false;
  }

  if (queue->head != NULL) {
    return false;
  }

  if (queue->tail != NULL) {
    return false;
  }

  if (queue->size != 0) {
    return false;
  }

  if (dequeue_data != &data) {
    return false;
  }

  Queue_free(queue);
  return true;
}

bool test_Queue_dequeue_multiple() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  int data1 = 5;
  int data2 = 10;
  int data3 = 15;

  Queue_enqueue(queue, &data1);
  Queue_enqueue(queue, &data2);
  Queue_enqueue(queue, &data3);

  void *dequeue_data1 = Queue_dequeue(queue);
  if (dequeue_data1 == NULL) {
    return false;
  }

  if (queue->head == NULL) {
    return false;
  }

  if (queue->tail == NULL) {
    return false;
  }

  if (queue->size != 2) {
    return false;
  }

  if (dequeue_data1 != &data1) {
    return false;
  }

  void *dequeue_data2 = Queue_dequeue(queue);
  if (dequeue_data2 == NULL) {
    return false;
  }

  if (queue->head == NULL) {
    return false;
  }

  if (queue->tail == NULL) {
    return false;
  }

  if (queue->size != 1) {
    return false;
  }

  if (dequeue_data2 != &data2) {
    return false;
  }

  void *dequeue_data3 = Queue_dequeue(queue);
  if (dequeue_data3 == NULL) {
    return false;
  }

  if (queue->head != NULL) {
    return false;
  }

  if (queue->tail != NULL) {
    return false;
  }

  if (queue->size != 0) {
    return false;
  }

  if (dequeue_data3 != &data3) {
    return false;
  }

  Queue_free(queue);
  return true;
}

bool test_Queue_dequeue_from_null() {
  Queue* queue = NULL;

  void *dequeue_data = Queue_dequeue(queue);
  if (dequeue_data != NULL) {
    return false;
  }

  return true;
}

bool test_Queue_dequeue_from_empty() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  void *dequeue_data = Queue_dequeue(queue);
  if (dequeue_data != NULL) {
    return false;
  }

  Queue_free(queue);
  return true;
}

/**
 * Test function for Queue_peek().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_Queue_peek() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  int data = 5;
  Queue_enqueue(queue, &data);

  void *peek_data = Queue_peek(queue);
  if (peek_data == NULL) {
    return false;
  }

  if (queue->size != 1) {
    return false;
  }

  if (peek_data != &data) {
    return false;
  }

  Queue_free(queue);
  return true;
}

bool test_Queue_peek_multiple() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  int data1 = 5;
  int data2 = 10;
  int data3 = 15;

  Queue_enqueue(queue, &data1);
  Queue_enqueue(queue, &data2);
  Queue_enqueue(queue, &data3);

  void *peek_data1 = Queue_peek(queue);
  if (peek_data1 == NULL) {
    return false;
  }

  if (queue->size != 3) {
    return false;
  }

  if (peek_data1 != &data1) {
    return false;
  }

  Queue_free(queue);
  return true;
}

bool test_Queue_peek_from_null() {
  Queue* queue = NULL;

  void *peek_data = Queue_peek(queue);
  if (peek_data != NULL) {
    return false;
  }

  return true;
}

bool test_Queue_peek_from_empty() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  void *peek_data = Queue_peek(queue);
  if (peek_data != NULL) {
    return false;
  }

  Queue_free(queue);
  return true;
}

/**
 * Test function for Queue_size().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_Queue_size() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  int data = 5;
  Queue_enqueue(queue, &data);

  if (Queue_size(queue) != 1) {
    return false;
  }

  Queue_free(queue);
  return true;
}

bool test_Queue_size_multiple() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  int data1 = 5;
  int data2 = 10;
  int data3 = 15;

  Queue_enqueue(queue, &data1);
  Queue_enqueue(queue, &data2);
  Queue_enqueue(queue, &data3);

  if (Queue_size(queue) != 3) {
    return false;
  }

  Queue_free(queue);
  return true;
}

bool test_Queue_size_from_null() {
  Queue* queue = NULL;

  if (Queue_size(queue) != -1) {
    return false;
  }

  return true;
}

bool test_Queue_size_from_empty() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  if (Queue_size(queue) != 0) {
    return false;
  }

  Queue_free(queue);
  return true;
}

/**
 * Test function for Queue_isEmpty().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_Queue_isEmpty() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  if (!Queue_isEmpty(queue)) {
    return false;
  }

  Queue_free(queue);
  return true;
}

bool test_Queue_isEmpty_multiple() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  int data = 5;
  int data2 = 10;
  int data3 = 15;
  Queue_enqueue(queue, &data);
  Queue_enqueue(queue, &data2);
  Queue_enqueue(queue, &data3);

  if (Queue_isEmpty(queue)) {
    return false;
  }

  Queue_free(queue);
  return true;
}

bool test_Queue_isEmpty_from_null() {
  Queue* queue = NULL;

  if (!Queue_isEmpty(queue)) {
    return false;
  }

  return true;
}

/**
 * Test function for Queue_clear().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_Queue_clear() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  int data = 5;
  Queue_enqueue(queue, &data);

  Queue_clear(queue);

  if (queue->head != NULL) {
    return false;
  }

  if (queue->tail != NULL) {
    return false;
  }

  if (queue->size != 0) {
    return false;
  }

  Queue_free(queue);
  return true;
}

bool test_Queue_clear_multiple() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  int data1 = 5;
  int data2 = 10;
  int data3 = 15;

  Queue_enqueue(queue, &data1);
  Queue_enqueue(queue, &data2);
  Queue_enqueue(queue, &data3);

  Queue_clear(queue);

  if (queue->head != NULL) {
    return false;
  }

  if (queue->tail != NULL) {
    return false;
  }

  if (queue->size != 0) {
    return false;
  }

  Queue_free(queue);
  return true;
}

bool test_Queue_clear_from_null() {
  Queue* queue = NULL;

  if (Queue_clear(queue)) {
    return false;
  }

  return true;
}

bool test_Queue_clear_from_empty() {
  Queue* queue = new_Queue();
  if (queue == NULL) {
    return false;
  }

  Queue_clear(queue);

  if (queue->head != NULL) {
    return false;
  }

  if (queue->tail != NULL) {
    return false;
  }

  if (queue->size != 0) {
    return false;
  }

  Queue_free(queue);
  return true;
}

/**
 * Main function used to run the tests.
*/
int main() {
  printf("Running unit tests for Queue.h...\n");

  printf("\ttesting new_Queue()..............................%s\n", test_new_Queue() ? "PASS" : "FAIL");

  printf("\ttesting Queue_enqueue()..........................%s\n", test_Queue_enqueue() ? "PASS" : "FAIL");
  printf("\ttesting Queue_enqueue() with multiple elements...%s\n", test_Queue_enqueue_multiple() ? "PASS" : "FAIL");
  printf("\ttesting Queue_enqueue() to NULL..................%s\n", test_Queue_enqueue_to_null() ? "PASS" : "FAIL");

  printf("\ttesting Queue_dequeue()..........................%s\n", test_Queue_dequeue() ? "PASS" : "FAIL");
  printf("\ttesting Queue_dequeue() with multiple elements...%s\n", test_Queue_dequeue_multiple() ? "PASS" : "FAIL");
  printf("\ttesting Queue_dequeue() from NULL................%s\n", test_Queue_dequeue_from_null() ? "PASS" : "FAIL");
  printf("\ttesting Queue_dequeue() from empty queue.........%s\n", test_Queue_dequeue_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting Queue_peek().............................%s\n", test_Queue_peek() ? "PASS" : "FAIL");
  printf("\ttesting Queue_peek() with multiple elements......%s\n", test_Queue_peek_multiple() ? "PASS" : "FAIL");
  printf("\ttesting Queue_peek() from NULL...................%s\n", test_Queue_peek_from_null() ? "PASS" : "FAIL");
  printf("\ttesting Queue_peek() from empty queue............%s\n", test_Queue_peek_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting Queue_size().............................%s\n", test_Queue_size() ? "PASS" : "FAIL");
  printf("\ttesting Queue_size() with multiple elements......%s\n", test_Queue_size_multiple() ? "PASS" : "FAIL");
  printf("\ttesting Queue_size() from NULL...................%s\n", test_Queue_size_from_null() ? "PASS" : "FAIL");
  printf("\ttesting Queue_size() from empty queue............%s\n", test_Queue_size_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting Queue_isEmpty()..........................%s\n", test_Queue_isEmpty() ? "PASS" : "FAIL");
  printf("\ttesting Queue_isEmpty() with multiple elements...%s\n", test_Queue_isEmpty_multiple() ? "PASS" : "FAIL");
  printf("\ttesting Queue_isEmpty() from NULL................%s\n", test_Queue_isEmpty_from_null() ? "PASS" : "FAIL");

  printf("\ttesting Queue_clear()............................%s\n", test_Queue_clear() ? "PASS" : "FAIL");
  printf("\ttesting Queue_clear() with multiple elements.....%s\n", test_Queue_clear_multiple() ? "PASS" : "FAIL");
  printf("\ttesting Queue_clear() from NULL..................%s\n", test_Queue_clear_from_null() ? "PASS" : "FAIL");
  printf("\ttesting Queue_clear() from empty queue...........%s\n", test_Queue_clear_from_empty() ? "PASS" : "FAIL");

  printf("Unit tests complete.\n");
}
