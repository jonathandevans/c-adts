/**
 * @file stack.h
 * @brief Stack data type implementation using a node structure
 * @author Jonathan E
 * @date 23-04-2023
 * 
 * This is a stack data type that can be used to store data in a LIFO data
 * structure.
 * This implementation is a stack data type that makes use of a dynamic array
 * as the underlying collection.
 * The data stored in the array are void pointers which are dynamically allocated
 * to the heap.
*/

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Stack_Node {
  void *data;
  struct Stack_Node *next;
} Stack_Node;

typedef struct Stack {
  Stack_Node *top;
  int size;
} Stack;

/**
 * Creates a new stack using a series of nodes as the underlying collection.
 * 
 * @return The new stack.
*/
Stack* new_Stack();

/**
 * Pushes a new element onto the stack.
 * The data is stored as a node in a series of nodes. Note that the data is not
 * copied, but rather the pointer to the data is copied.
 * 
 * @param Stack* The stack to push the element onto.
 * @param void*  The data to push onto the stack.
 * @return true if the push was successful, false otherwise.
*/
bool Stack_push(Stack*, void*);

/**
 * Pops the top element off the stack.
 * The data is stored as a node in a series of nodes. Note that the data is not
 * copied, but rather the pointer to the data is copied.
 * 
 * @param Stack* The stack to pop the element off.
 * @return The data that was popped off the stack.
*/
void* Stack_pop(Stack*);

/**
 * Peeks at the top element on the stack.
 * The data is stored as a node in a series of nodes. This function returns the
 * pointer to the data, not a copy of the data.
 * 
 * @param Stack* The stack to peek at.
 * @return The data that is on the top of the stack.
*/
void* Stack_peek(Stack*);

/**
 * Gets the size of the stack.
 * 
 * @param Stack* The stack to get the size of.
 * @return The size of the stack.
*/
int Stack_size(Stack*);

/**
 * Checks if the stack is empty.
 * 
 * @param Stack* The stack to check if it is empty.
 * @return true if the stack is empty, false otherwise.
*/
bool Stack_isEmpty(Stack*);

/**
 * Prints the stack as a list of pointers.
 * 
 * @param Stack* The stack to print.
*/
void Stack_print(Stack*);

/**
 * Prints the stack as a list of integers.
 * 
 * @param Stack* The stack to print.
*/
void Stack_printInt(Stack*);

/**
 * Clears the given stack.
 * 
 * @param Stack* The stack to clear.
 * @return true if the stack was cleared, false otherwise.
*/
bool Stack_clear(Stack*);

/**
 * Frees the given stack.
 * 
 * @param Stack* The stack to free.
*/
void Stack_free(Stack*);

#endif /* STACK_H */
