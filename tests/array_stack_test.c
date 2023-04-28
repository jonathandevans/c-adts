/**
 * @file array_stack_test.c
 * @brief Test file for array_stack.c
 * @author Jonathan E
 * @date 28-04-2023
 * 
 * This file contains the tests for the array_stack.c file.
 * By running this file, you can test the functions in array_stack.c with
 * the test cases outputted to the console.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../src/array_stack/array_stack.h"

/**
 * Test function for new_ArrayStack().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_new_ArrayStack() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  if (stack->size != 0) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

/**
 * Test function for ArrayStack_push().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_ArrayStack_push() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  int* data = malloc(sizeof(int));
  *data = 5;
  ArrayStack_push(stack, data);

  if (stack->size != 1) {
    return false;
  }

  if (*(int*)stack->collection[0] != 5) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

bool test_ArrayStack_push_multiple() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  int* data1 = malloc(sizeof(int));
  *data1 = 5;
  ArrayStack_push(stack, data1);

  int* data2 = malloc(sizeof(int));
  *data2 = 10;
  ArrayStack_push(stack, data2);

  int* data3 = malloc(sizeof(int));
  *data3 = 15;
  ArrayStack_push(stack, data3);

  if (stack->size != 3) {
    return false;
  }

  if (*(int*)stack->collection[0] != 5) {
    return false;
  }

  if (*(int*)stack->collection[1] != 10) {
    return false;
  }

  if (*(int*)stack->collection[2] != 15) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

bool test_ArrayStack_push_to_null() {
  ArrayStack* stack = NULL;
  int* data = malloc(sizeof(int));
  *data = 5;
  bool result = ArrayStack_push(stack, data);
  if (result) {
    return false;
  }

  return true;
}

/**
 * Test function for ArrayStack_pop().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_ArrayStack_pop() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  int data = 5;
  ArrayStack_push(stack, &data);

  ArrayStack_printInt(stack);

  void* popped = ArrayStack_pop(stack);
  if (popped == NULL) {
    printf("popped is null");
    return false;
  }

  if (*(int*)popped != 5) {
    return false;
  }

  if (stack->size != 0) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

bool test_ArrayStack_pop_multiple() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  int* data1 = malloc(sizeof(int));
  *data1 = 5;
  ArrayStack_push(stack, data1);

  int* data2 = malloc(sizeof(int));
  *data2 = 10;
  ArrayStack_push(stack, data2);

  int* data3 = malloc(sizeof(int));
  *data3 = 15;
  ArrayStack_push(stack, data3);

  int* popped1 = ArrayStack_pop(stack);
  if (popped1 == NULL) {
    return false;
  }

  if (*popped1 != 15) {
    return false;
  }

  int* popped2 = ArrayStack_pop(stack);
  if (popped2 == NULL) {
    return false;
  }

  if (*popped2 != 10) {
    return false;
  }

  int* popped3 = ArrayStack_pop(stack);
  if (popped3 == NULL) {
    return false;
  }

  if (*popped3 != 5) {
    return false;
  }

  if (stack->size != 0) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

bool test_ArrayStack_pop_from_null() {
  ArrayStack* stack = NULL;
  int* popped = ArrayStack_pop(stack);
  if (popped != NULL) {
    return false;
  }

  return true;
}

bool test_ArrayStack_pop_from_empty() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  int* popped = ArrayStack_pop(stack);
  if (popped != NULL) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

/**
 * Test function for ArrayStack_peek().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_ArrayStack_peek() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  int* data = malloc(sizeof(int));
  *data = 5;
  ArrayStack_push(stack, data);

  int* peeked = ArrayStack_peek(stack);
  if (peeked == NULL) {
    return false;
  }

  if (*peeked != 5) {
    return false;
  }

  if (stack->size != 1) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

bool test_ArrayStack_peek_multiple() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  int* data1 = malloc(sizeof(int));
  *data1 = 5;
  ArrayStack_push(stack, data1);

  int* data2 = malloc(sizeof(int));
  *data2 = 10;
  ArrayStack_push(stack, data2);

  int* data3 = malloc(sizeof(int));
  *data3 = 15;
  ArrayStack_push(stack, data3);

  int* peeked3 = ArrayStack_peek(stack);
  if (peeked3 == NULL) {
    return false;
  }

  if (*peeked3 != 15) {
    return false;
  }

  if (stack->size != 3) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

bool test_ArrayStack_peek_from_null() {
  ArrayStack* stack = NULL;
  int* peeked = ArrayStack_peek(stack);
  if (peeked != NULL) {
    return false;
  }

  return true;
}

bool test_ArrayStack_peek_from_empty() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  int* peeked = ArrayStack_peek(stack);
  if (peeked != NULL) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

/**
 * Test function for ArrayStack_size().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_ArrayStack_size() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  if (ArrayStack_size(stack) != 0) {
    return false;
  }

  int* data = malloc(sizeof(int));
  *data = 5;
  ArrayStack_push(stack, data);

  if (ArrayStack_size(stack) != 1) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

bool test_ArrayStack_size_multiple() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  if (ArrayStack_size(stack) != 0) {
    return false;
  }

  int* data1 = malloc(sizeof(int));
  *data1 = 5;
  ArrayStack_push(stack, data1);

  if (ArrayStack_size(stack) != 1) {
    return false;
  }

  int* data2 = malloc(sizeof(int));
  *data2 = 10;
  ArrayStack_push(stack, data2);

  if (ArrayStack_size(stack) != 2) {
    return false;
  }

  int* data3 = malloc(sizeof(int));
  *data3 = 15;
  ArrayStack_push(stack, data3);

  if (ArrayStack_size(stack) != 3) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

bool test_ArrayStack_size_from_null() {
  ArrayStack* stack = NULL;
  if (ArrayStack_size(stack) != -1) {
    return false;
  }

  return true;
}

bool test_ArrayStack_size_from_empty() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  if (ArrayStack_size(stack) != 0) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

/**
 * Test function for ArrayStack_isEmpty().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_ArrayStack_isEmpty() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  if (!ArrayStack_isEmpty(stack)) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

bool test_ArrayStack_isEmpty_multiple() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  if (!ArrayStack_isEmpty(stack)) {
    return false;
  }

  int* data1 = malloc(sizeof(int));
  *data1 = 5;
  ArrayStack_push(stack, data1);

  if (ArrayStack_isEmpty(stack)) {
    return false;
  }

  int* data2 = malloc(sizeof(int));
  *data2 = 10;
  ArrayStack_push(stack, data2);

  if (ArrayStack_isEmpty(stack)) {
    return false;
  }

  int* data3 = malloc(sizeof(int));
  *data3 = 15;
  ArrayStack_push(stack, data3);

  if (ArrayStack_isEmpty(stack)) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

bool test_ArrayStack_isEmpty_from_null() {
  ArrayStack* stack = NULL;
  if (!ArrayStack_isEmpty(stack)) {
    return false;
  }

  return true;
}

/**
 * Test function for ArrayStack_clear().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_ArrayStack_clear() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  int* data1 = malloc(sizeof(int));
  *data1 = 5;
  ArrayStack_push(stack, data1);

  ArrayStack_clear(stack);

  if (stack->size != 0) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

bool test_ArrayStack_clear_multiple() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  int* data1 = malloc(sizeof(int));
  *data1 = 5;
  ArrayStack_push(stack, data1);

  int* data2 = malloc(sizeof(int));
  *data2 = 10;
  ArrayStack_push(stack, data2);

  int* data3 = malloc(sizeof(int));
  *data3 = 15;
  ArrayStack_push(stack, data3);

  ArrayStack_clear(stack);

  if (stack->size != 0) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

bool test_ArrayStack_clear_from_null() {
  ArrayStack* stack = NULL;
  ArrayStack_clear(stack);

  return true;
}

bool test_ArrayStack_clear_from_empty() {
  ArrayStack* stack = new_ArrayStack();
  if (stack == NULL) {
    return false;
  }

  ArrayStack_clear(stack);

  if (stack->size != 0) {
    return false;
  }

  ArrayStack_free(stack);
  return true;
}

/**
 * Main function used to run the tests.
*/
int main() {
  printf("Running unit tests for ArrayStack...\n");

  printf("\ttesting new_ArrayStack()..............................%s\n", test_new_ArrayStack() ? "PASS" : "FAIL");

  printf("\ttesting ArrayStack_push().............................%s\n", test_ArrayStack_push() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_push() with multiple elements......%s\n", test_ArrayStack_push_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_push() with NULL stack.............%s\n", test_ArrayStack_push_to_null() ? "PASS" : "FAIL");

  printf("\ttesting ArrayStack_pop()..............................%s\n", test_ArrayStack_pop() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_pop() with multiple elements.......%s\n", test_ArrayStack_pop_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_pop() with NULL stack..............%s\n", test_ArrayStack_pop_from_null() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_pop() with empty stack.............%s\n", test_ArrayStack_pop_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting ArrayStack_peek().............................%s\n", test_ArrayStack_peek() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_peek() with multiple elements......%s\n", test_ArrayStack_peek_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_peek() with NULL stack.............%s\n", test_ArrayStack_peek_from_null() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_peek() with empty stack............%s\n", test_ArrayStack_peek_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting ArrayStack_size().............................%s\n", test_ArrayStack_size() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_size() with multiple elements......%s\n", test_ArrayStack_size_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_size() with NULL stack.............%s\n", test_ArrayStack_size_from_null() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_size() with empty stack............%s\n", test_ArrayStack_size_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting ArrayStack_isEmpty()..........................%s\n", test_ArrayStack_isEmpty() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_isEmpty() with multiple elements...%s\n", test_ArrayStack_isEmpty_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_isEmpty() with NULL stack..........%s\n", test_ArrayStack_isEmpty_from_null() ? "PASS" : "FAIL");

  printf("\ttesting ArrayStack_clear()............................%s\n", test_ArrayStack_clear() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_clear() with multiple elements.....%s\n", test_ArrayStack_clear_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_clear() with NULL stack............%s\n", test_ArrayStack_clear_from_null() ? "PASS" : "FAIL");
  printf("\ttesting ArrayStack_clear() with empty stack...........%s\n", test_ArrayStack_clear_from_empty() ? "PASS" : "FAIL");

  printf("Unit tests complete.\n");
}
