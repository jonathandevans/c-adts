/**
 * @file stack.c
 * @brief Stack data type implementation using a node structure
 * @author Jonathan E
 * @date 23-04-2023
 * 
 * This is an implementation of a stack data type that can be used to store a
 * generic pointer.
 * This implementation is a stack data type that makes use of a node structure
 * as the underlying collection.
 * The data stored in the nodes are void pointers which are dynamically allocated
 * to the heap.
*/

#include "stack.h"

/**
 * Creates a new stack using a node structure as the underlying collection.
 * This function uses malloc to allocate memory for the stack.
 * 
 * @return The new stack.
*/
Stack* new_Stack() {
  Stack* stack = malloc(sizeof(Stack));
  // If the memory allocation failed, return NULL.
  if (stack == NULL) {
    return NULL;
  }

  // Initialise the stack.
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

/**
 * Pushes an element onto the stack.
 * The data is stored in the node as a void pointer. Note that the data is not
 * copied, but rather the pointer to the data is stored in the node.
 * 
 * @param Stack* The stack to push the element onto.
 * @param void*  The element to push onto the stack.
 * @return true if the element was pushed onto the stack, false otherwise.
*/
bool Stack_push(Stack* stack, void* data) {
  // If the stack is NULL, return false.
  if (stack == NULL) {
    return false;
  }

  // Create a new node.
  Stack_Node* new_node = malloc(sizeof(Stack_Node));
  // If the memory allocation failed, return false.
  if (new_node == NULL) {
    return false;
  }

  // Initialise the node.
  new_node->data = data;
  new_node->next = stack->top;
  stack->top = new_node;
  stack->size++;
  return true;
}

/**
 * Pops an element off the stack.
 * The data is stored in the node as a void pointer. This function returns the
 * data stored in the node, not a copy of the data.
 * 
 * @param Stack* The stack to pop the element off.
 * @return The data stored in the node, or NULL if the stack is empty.
*/
void* Stack_pop(Stack* stack) {
  // If the stack is NULL, return NULL.
  if (stack == NULL) {
    return NULL;
  }

  // If the stack is empty, return NULL.
  if (stack->size == 0) {
    return NULL;
  }

  // If the stack is NULL, return NULL.
  if (stack->top == NULL) {
    return NULL;
  }

  // Get the data from the top node.
  void* data = stack->top->data;

  // Remove the top node.
  Stack_Node* temp = stack->top;
  stack->top = stack->top->next;
  free(temp);
  stack->size--;
  return data;
}

/**
 * Peeks at the top element of the stack.
 * The data is stored in the node as a void pointer. This function returns the
 * data stored in the node, not a copy of the data.
 * 
 * @param Stack* The stack to peek at.
 * @return The data stored in the node, or NULL if the stack is empty.
*/
void* Stack_peek(Stack* stack) {
  // If the stack is NULL, return NULL.
  if (stack == NULL) {
    return NULL;
  }

  // If the stack is empty, return NULL.
  if (stack->size == 0) {
    return NULL;
  }

  // If the stack is NULL, return NULL.
  if (stack->top == NULL) {
    return NULL;
  }

  // Get the data from the top node.
  void* data = stack->top->data;
  return data;
}

/**
 * Gets the size of the stack.
 * 
 * @param Stack* The stack to get the size of.
 * @return The size of the stack, or -1 if the stack is NULL.
*/
int Stack_size(Stack* stack) {
  // If the stack is NULL, return 0.
  if (stack == NULL) {
    return -1;
  }

  return stack->size;
}

/**
 * Checks if the stack is empty.
 * 
 * @param Stack* The stack to check.
 * @return true if the stack is empty, false otherwise.
*/
bool Stack_isEmpty(Stack* stack) {
  // If the stack is NULL, return true.
  if (stack == NULL) {
    return true;
  }

  return stack->size == 0;
}

/**
 * Prints the stack as a list of pointers.
 * 
 * @param Stack* The stack to print.
*/
void Stack_print(Stack* stack) {
  // If the stack is NULL, return.
  if (stack == NULL) {
    return;
  }

  // If the stack is empty, return.
  if (stack->size == 0) {
    return;
  }

  // If the stack is NULL, return.
  if (stack->top == NULL) {
    return;
  }

  // Print the stack.
  Stack_Node* current = stack->top;
  printf("[ ");
  while (current != NULL) {
    printf("%p, ", current->data);
    current = current->next;
  }
  printf("]\n");
}

/**
 * Prints the stack as a list of integers.
 * 
 * @param Stack* The stack to print.
*/
void Stack_printInt(Stack* stack) {
  // If the stack is NULL, return.
  if (stack == NULL) {
    return;
  }

  // If the stack is empty, return.
  if (stack->size == 0) {
    return;
  }

  // If the stack is NULL, return.
  if (stack->top == NULL) {
    return;
  }

  // Print the stack.
  Stack_Node* current = stack->top;
  printf("[ ");
  while (current != NULL) {
    printf("%d, ", *(int*)current->data);
    current = current->next;
  }
  printf("]\n");
}

/**
 * Clears the stack.
 * 
 * @param Stack* The stack to clear.
 * @return true if the stack was cleared, false otherwise.
*/
bool Stack_clear(Stack* stack) {
  // If the stack is NULL, return false.
  if (stack == NULL) {
    return false;
  }

  // If the stack is empty, return false.
  if (stack->size == 0) {
    return false;
  }

  // If the stack is NULL, return false.
  if (stack->top == NULL) {
    return false;
  }

  // Clear the stack.
  Stack_Node* current = stack->top;
  while (current != NULL) {
    Stack_Node* temp = current;
    current = current->next;
    free(temp);
  }
  stack->top = NULL;
  stack->size = 0;
  return true;
}

/**
 * Frees the stack.
 * 
 * @param Stack* The stack to free.
*/
void Stack_free(Stack* stack) {
  // If the stack is NULL, return.
  if (stack == NULL) {
    return;
  }

  // Clear the stack.
  Stack_clear(stack);

  // Free the stack.
  free(stack);
}
