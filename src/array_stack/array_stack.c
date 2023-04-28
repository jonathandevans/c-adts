/**
 * @file array_stack.c
 * @brief Stack data type implementation using a dynamic array
 * @author Jonathan E
 * @date 09-04-2023
 * 
 * This is an implementation of a stack data type that can be used to store a
 * generic pointer.
 * This implementation is a stack data type that makes use of a dynamic array
 * as the underlying collection.
 * The data stored in the array are void pointers which are dynamically allocated
 * to the heap.
*/

#include "array_stack.h"

/**
 * Creates a new stack using a dynamic array as the underlying collection.
 * This function uses malloc to allocate memory for the stack.
 * 
 * @return A pointer to the new stack, or NULL if the memory allocation failed.
*/
ArrayStack* new_ArrayStack() {
  ArrayStack* stack = malloc(sizeof(ArrayStack));
  // If the memory allocation failed, return NULL.
  if (stack == NULL) {
    return NULL;
  }

  // Initialise the collection.
  void** new_collection = malloc(sizeof(void*));
  // If the memory allocation failed, return NULL.
  if (new_collection == NULL) {
    return NULL;
  }

  // Initialise the stack.
  stack->collection = new_collection;
  stack->size = 0;
  return stack;
}

/**
 * Pushes an element onto the stack.
 * The data is stored in the node as a void pointer. Note that the data is not
 * copied, but rather the pointer to the data is stored in the node.
 * 
 * @param ArrayStack* The stack to push the element onto.
 * @param void*       The element to push onto the stack.
 * @return true if the element was pushed onto the stack, false otherwise.
*/
bool ArrayStack_push(ArrayStack* stack, void* data) {
  // If the stack is NULL, return false.
  if (stack == NULL) {
    return false;
  }

  // If the collection is NULL, return false.
  if (stack->collection == NULL) {
    return false;
  }

  // If the stack is empty, add the data to the collection.
  if (stack->size == 0) {
    stack->collection[0] = data;
    stack->size++;
    return true;
  }

  // Otherwise,
  // Reallocate the collection to make space for the new element.
  void** new_collection = realloc(stack->collection, sizeof(void*) * (stack->size + 1));
  // If the memory allocation failed, return false.
  if (new_collection == NULL) {
    return false;
  }

  // Add the data to the collection.
  new_collection[stack->size] = data;
  stack->collection = new_collection;
  stack->size++;
  return true;
}

/**
 * Pops an element off the stack.
 * The data is stored in the node as a void pointer. This function returns the
 * pointer to the data, not a copy of the data.
 * 
 * @param ArrayStack* The stack to pop the element off of.
 * @return The element that was popped off the stack.
*/
void* ArrayStack_pop(ArrayStack* stack) {
  // If the stack is NULL, return NULL.
  if (stack == NULL) {
    return NULL;
  }

  // If the collection is NULL, return NULL.
  if (stack->collection == NULL) {
    return NULL;
  }

  // If the stack is empty, return NULL.
  if (stack->size == 0) {
    return NULL;
  }

  // Get the data from the top of the stack.
  void* data = stack->collection[stack->size - 1];

  // If the stack only has one element, free the collection.
  

  // Reallocate the collection to make space for the new element.
  void** new_collection = realloc(stack->collection, sizeof(void*) * (stack->size - 1));
  // If the memory allocation failed, return NULL.
  if (new_collection == NULL) {
    return NULL;
  }

  // Remove the data from the collection.
  stack->collection = new_collection;
  stack->size--;
  return data;
}

/**
 * Peeks at the top element of the stack.
 * The data is stored in the node as a void pointer. This function returns the
 * pointer to the data, not a copy of the data.
 * 
 * @param ArrayStack* The stack to peek at.
 * @return The element at the top of the stack.
*/
void* ArrayStack_peek(ArrayStack* stack) {
  // If the stack is NULL, return NULL.
  if (stack == NULL) {
    return NULL;
  }

  // If the collection is NULL, return NULL.
  if (stack->collection == NULL) {
    return NULL;
  }

  // If the stack is empty, return NULL.
  if (stack->size == 0) {
    return NULL;
  }

  // Get the data from the top of the stack.
  void* data = stack->collection[stack->size - 1];
  return data;
}

/**
 * Gets the size of the stack.
 * 
 * @param ArrayStack* The stack to get the size of.
 * @return The size of the stack.
*/
int ArrayStack_size(ArrayStack* stack) {
  // If the stack is NULL, return 0.
  if (stack == NULL) {
    return 0;
  }

  // Return the size of the stack.
  return stack->size;
}

/**
 * Checks if the stack is empty.
 * 
 * @param ArrayStack* The stack to check.
 * @return true if the stack is empty, false otherwise.
*/
bool ArrayStack_isEmpty(ArrayStack* stack) {
  // If the stack is NULL, return true.
  if (stack == NULL) {
    return true;
  }

  // Return true if the stack is empty, false otherwise.
  return stack->size == 0;
}

/**
 * Prints the stack as a list of pointers.
 * 
 * @param ArrayStack* The stack to print.
*/
void ArrayStack_print(ArrayStack* stack) {
  // If the stack is NULL, return.
  if (stack == NULL) {
    return;
  }

  // If the collection is NULL, return.
  if (stack->collection == NULL) {
    return;
  }

  // Print the stack.
  printf("[ ");
  for (int i = 0; i < stack->size; i++) {
    printf("%p ", stack->collection[i]);
  }
  printf("]\n");
}

/**
 * Prints the stack as a list of integers.
 * 
 * @param ArrayStack* The stack to print.
*/
void ArrayStack_printInt(ArrayStack* stack) {
  // If the stack is NULL, return.
  if (stack == NULL) {
    return;
  }

  // If the collection is NULL, return.
  if (stack->collection == NULL) {
    return;
  }

  // Print the stack.
  printf("[ ");
  for (int i = 0; i < stack->size; i++) {
    printf("%d ", *(int*)stack->collection[i]);
  }
  printf("]\n");
}

/**
 * Clears the stack.
 * 
 * @param ArrayStack* The stack to clear.
 * @return true if the stack was cleared, false otherwise.
*/
bool ArrayStack_clear(ArrayStack* stack) {
  // If the stack is NULL, return false.
  if (stack == NULL) {
    return false;
  }

  // If the collection is NULL, return false.
  if (stack->collection == NULL) {
    return false;
  }

  // Clear the stack.
  free(stack->collection);
  stack->collection = NULL;
  stack->size = 0;
  return true;
}

/**
 * Frees the memory allocated for the stack.
 * 
 * @param ArrayStack* The stack to free.
*/
void ArrayStack_free(ArrayStack* stack) {
  // If the stack is NULL, return.
  if (stack == NULL) {
    return;
  }

  // If the collection is NULL, return.
  if (stack->collection == NULL) {
    free(stack);
    return;
  }

  // Free the stack.
  free(stack->collection);
  free(stack);
}

