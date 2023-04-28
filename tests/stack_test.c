/**
 * @file stack_test.c
 * @brief Test file for stack.c
 * @author Jonathan E
 * @date 28-04-2023
 * 
 * This file contains the tests for the stack.c file.
 * By running this file, you can test the functions in stack.c with the
 * test cases outputted to the console.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../src/stack/stack.h"

/**
 * Test function for new_Stack().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_new_Stack() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  if (stack->size != 0) {
    return false;
  }

  if (stack->top != NULL) {
    return false;
  }

  Stack_free(stack);
  return true;
}

/**
 * Test function for Stack_push().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_Stack_push() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  int data = 5;
  Stack_push(stack, &data);

  if (stack->size != 1) {
    return false;
  }

  if (stack->top->data != &data) {
    return false;
  }

  Stack_free(stack);
  return true;
}

bool test_Stack_push_multiple() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  int data1 = 5;
  int data2 = 10;
  int data3 = 15;
  Stack_push(stack, &data1);
  Stack_push(stack, &data2);
  Stack_push(stack, &data3);

  if (stack->size != 3) {
    return false;
  }

  if (stack->top->data != &data3) {
    return false;
  }

  if (stack->top->next->data != &data2) {
    return false;
  }

  if (stack->top->next->next->data != &data1) {
    return false;
  }

  Stack_free(stack);
  return true;
}

bool test_Stack_push_to_null() {
  Stack *stack = NULL;
  if (stack != NULL) {
    return false;
  }

  int data = 5;
  if (Stack_push(stack, &data)) {
    return false;
  }

  return true;
}

/**
 * Test function for Stack_pop().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_Stack_pop() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  int data = 5;
  Stack_push(stack, &data);

  void* popped = Stack_pop(stack);
  if (popped == NULL) {
    return false;
  }

  if (*(int*)popped != data) {
    return false;
  }

  if (stack->size != 0) {
    return false;
  }

  if (stack->top != NULL) {
    return false;
  }

  Stack_free(stack);
  return true;
}

bool test_Stack_pop_multiple() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  int data1 = 5;
  int data2 = 10;
  int data3 = 15;
  Stack_push(stack, &data1);
  Stack_push(stack, &data2);
  Stack_push(stack, &data3);

  void* popped1 = Stack_pop(stack);
  if (popped1 == NULL) {
    return false;
  }

  if (*(int*)popped1 != data3) {
    return false;
  }

  void* popped2 = Stack_pop(stack);
  if (popped2 == NULL) {
    return false;
  }

  if (*(int*)popped2 != data2) {
    return false;
  }

  void* popped3 = Stack_pop(stack);
  if (popped3 == NULL) {
    return false;
  }

  if (*(int*)popped3 != data1) {
    return false;
  }

  if (stack->size != 0) {
    return false;
  }

  if (stack->top != NULL) {
    return false;
  }

  Stack_free(stack);
  return true;
}

bool test_Stack_pop_from_null() {
  Stack *stack = NULL;

  void* popped = Stack_pop(stack);
  if (popped != NULL) {
    return false;
  }

  return true;
}

bool test_Stack_pop_from_empty() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  void* popped = Stack_pop(stack);
  if (popped != NULL) {
    return false;
  }

  Stack_free(stack);
  return true;
}

/**
 * Test function for Stack_peek().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_Stack_peek() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  int data = 5;
  Stack_push(stack, &data);

  void* peeked = Stack_peek(stack);
  if (peeked == NULL) {
    return false;
  }

  if (*(int*)peeked != data) {
    return false;
  }

  if (stack->size != 1) {
    return false;
  }

  Stack_free(stack);
  return true;
}

bool test_Stack_peek_multiple() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  int data1 = 5;
  int data2 = 10;
  int data3 = 15;
  Stack_push(stack, &data1);
  Stack_push(stack, &data2);
  Stack_push(stack, &data3);

  void* peeked = Stack_peek(stack);
  if (peeked == NULL) {
    return false;
  }

  if (*(int*)peeked != data3) {
    return false;
  }

  if (stack->size != 3) {
    return false;
  }

  Stack_free(stack);
  return true;
}

bool test_Stack_peek_from_null() {
  Stack *stack = NULL;

  void* peeked = Stack_peek(stack);
  if (peeked != NULL) {
    return false;
  }

  return true;
}

bool test_Stack_peek_from_empty() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  void* peeked = Stack_peek(stack);
  if (peeked != NULL) {
    return false;
  }

  Stack_free(stack);
  return true;
}

/**
 * Test function fo Stack_size().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_Stack_size() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  if (Stack_size(stack) != 0) {
    return false;
  }

  int data = 5;
  Stack_push(stack, &data);

  if (Stack_size(stack) != 1) {
    return false;
  }

  Stack_free(stack);
  return true;
}

bool test_Stack_size_multiple() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  if (Stack_size(stack) != 0) {
    return false;
  }

  int data1 = 5;
  int data2 = 10;
  int data3 = 15;
  Stack_push(stack, &data1);
  Stack_push(stack, &data2);
  Stack_push(stack, &data3);

  if (Stack_size(stack) != 3) {
    return false;
  }

  Stack_free(stack);
  return true;
}

bool test_Stack_size_from_null() {
  Stack *stack = NULL;

  if (Stack_size(stack) != -1) {
    return false;
  }

  return true;
}

bool test_Stack_size_from_empty() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  if (Stack_size(stack) != 0) {
    return false;
  }

  Stack_free(stack);
  return true;
}

/**
 * Test function for Stack_isEmpty().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_Stack_isEmpty() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  if (Stack_isEmpty(stack) != true) {
    return false;
  }

  Stack_free(stack);
  return true;
}

bool test_Stack_isEmpty_multiple() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  int data = 5;
  int data2 = 10;
  int data3 = 15;
  Stack_push(stack, &data);
  Stack_push(stack, &data2);
  Stack_push(stack, &data3);

  if (Stack_isEmpty(stack)) {
    return false;
  }

  Stack_free(stack);
  return true;
}

bool test_Stack_isEmpty_from_null() {
  Stack *stack = NULL;

  if (!Stack_isEmpty(stack)) {
    return false;
  }

  return true;
}

/**
 * Test function for Stack_clear().
 * 
 * @return true if the test passed, false otherwise.
*/
bool test_Stack_clear() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  int data = 5;
  Stack_push(stack, &data);

  Stack_clear(stack);

  if (stack->size != 0) {
    return false;
  }

  if (stack->top != NULL) {
    return false;
  }

  Stack_free(stack);
  return true;
}

bool test_Stack_clear_multiple() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  int data1 = 5;
  int data2 = 10;
  int data3 = 15;
  Stack_push(stack, &data1);
  Stack_push(stack, &data2);
  Stack_push(stack, &data3);

  if (!Stack_clear(stack)) {
    return false;
  }

  if (stack->size != 0) {
    return false;
  }

  if (stack->top != NULL) {
    return false;
  }

  Stack_free(stack);
  return true;
}

bool test_Stack_clear_from_null() {
  Stack *stack = NULL;

  if (Stack_clear(stack)) {
    return false;
  }

  return true;
}

bool test_Stack_clear_from_empty() {
  Stack *stack = new_Stack();
  if (stack == NULL) {
    return false;
  }

  if (Stack_clear(stack)) {
    return false;
  }

  if (stack->size != 0) {
    return false;
  }

  if (stack->top != NULL) {
    return false;
  }

  Stack_free(stack);
  return true;
}

/**
 * Main function used to run the tests.
*/
int main() {
  printf("Running unit tests for Stack...\n");

  printf("\ttesting new_Stack()..............................%s\n", test_new_Stack() ? "PASS" : "FAIL");

  printf("\ttesting Stack_push().............................%s\n", test_Stack_push() ? "PASS" : "FAIL");
  printf("\ttesting Stack_push() with multiple elements......%s\n", test_Stack_push_multiple() ? "PASS" : "FAIL");
  printf("\ttesting Stack_push() to NULL.....................%s\n", test_Stack_push_to_null() ? "PASS" : "FAIL");

  printf("\ttesting Stack_pop()..............................%s\n", test_Stack_pop() ? "PASS" : "FAIL");
  printf("\ttesting Stack_pop() with multiple elements.......%s\n", test_Stack_pop_multiple() ? "PASS" : "FAIL");
  printf("\ttesting Stack_pop() from NULL....................%s\n", test_Stack_pop_from_null() ? "PASS" : "FAIL");
  printf("\ttesting Stack_pop() from empty...................%s\n", test_Stack_pop_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting Stack_peek().............................%s\n", test_Stack_peek() ? "PASS" : "FAIL");
  printf("\ttesting Stack_peek() with multiple elements......%s\n", test_Stack_peek_multiple() ? "PASS" : "FAIL");
  printf("\ttesting Stack_peek() from NULL...................%s\n", test_Stack_peek_from_null() ? "PASS" : "FAIL");
  printf("\ttesting Stack_peek() from empty..................%s\n", test_Stack_peek_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting Stack_size().............................%s\n", test_Stack_size() ? "PASS" : "FAIL");
  printf("\ttesting Stack_size() with multiple elements......%s\n", test_Stack_size_multiple() ? "PASS" : "FAIL");
  printf("\ttesting Stack_size() from NULL...................%s\n", test_Stack_size_from_null() ? "PASS" : "FAIL");
  printf("\ttesting Stack_size() from empty..................%s\n", test_Stack_size_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting Stack_isEmpty()..........................%s\n", test_Stack_isEmpty() ? "PASS" : "FAIL");
  printf("\ttesting Stack_isEmpty() with multiple elements...%s\n", test_Stack_isEmpty_multiple() ? "PASS" : "FAIL");
  printf("\ttesting Stack_isEmpty() from NULL................%s\n", test_Stack_isEmpty_from_null() ? "PASS" : "FAIL");

  printf("\ttesting Stack_clear()............................%s\n", test_Stack_clear() ? "PASS" : "FAIL");
  printf("\ttesting Stack_clear() with multiple elements.....%s\n", test_Stack_clear_multiple() ? "PASS" : "FAIL");
  printf("\ttesting Stack_clear() with NULL..................%s\n", test_Stack_clear_from_null() ? "PASS" : "FAIL");
  printf("\ttesting Stack_clear() with empty.................%s\n", test_Stack_clear_from_empty() ? "PASS" : "FAIL");
}
