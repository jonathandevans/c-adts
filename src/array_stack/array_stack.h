/**
 * @file array_stack.h
 * @brief Stack data type implementation using a dynamic array
 * @author Jonathan E
 * @date 09-04-2023
 * 
 * This is a stack data type that can be used to store data in a LIFO data
 * structure.
 * This implementation is a stack that makes use of a dynamic array as 
 * the underlying collection.
 * The data stored in the stack are void pointers which are dynamically allocated
 * to the heap.
*/

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ArrayStack {
    void** collection;
    int size;
} ArrayStack;

/**
 * Creates a new stack using a dynamic array as the underlying collection.
 * 
 * @return The new array stack.
*/
ArrayStack* new_ArrayStack();

/**
 * Pushes an element onto the stack.
 * The data is stored in the array as a void pointer. Note that the data is not
 * copied, but rather the pointer to the data is stored in the node
 * 
 * @param ArrayStack* The stack to push the element onto.
 * @param void*        The element to push onto the stack.
 * @return true if the element was pushed onto the stack, false otherwise.
*/
bool ArrayStack_push(ArrayStack* stack, void* data);

/**
 * Pops an element off the stack.
 * The data is stored in the array as a void pointer. This function returns the
 * pointer to the data, not a copy of the data.
 * 
 * @param ArrayStack* The stack to pop the element off of.
 * @return The element that was popped off the stack.
*/
void* ArrayStack_pop(ArrayStack* stack);

/**
 * Peeks at the top element of the stack.
 * The data is stored in the array as a void pointer. This function returns the
 * pointer to the data, not a copy of the data.
 * 
 * @param ArrayStack* The stack to peek at.
 * @return The element at the top of the stack.
*/
void* ArrayStack_peek(ArrayStack* stack);

/**
 * Gets the size of the stack.
 * 
 * @param ArrayStack* The stack to get the size of.
 * @return The size of the stack.
*/
int ArrayStack_size(ArrayStack* stack);

/**
 * Checks if the stack is empty.
 * 
 * @param ArrayStack* The stack to check.
 * @return true if the stack is empty, false otherwise.
*/
bool ArrayStack_isEmpty(ArrayStack* stack);

/**
 * Prints the stack as a list of pointers.
 * 
 * @param ArrayStack* The stack to print.
*/
void ArrayStack_print(ArrayStack* stack);

/**
 * Prints the stack as a list of integers.
 * 
 * @param ArrayStack* The stack to print.
*/
void ArrayStack_printInt(ArrayStack* stack);

/**
 * Clears the given stack.
 * 
 * @param ArrayStack* The stack to clear.
 * @return true if the stack was cleared, false otherwise.
*/
bool ArrayStack_clear(ArrayStack* stack);

/**
 * Frees the stack.
 * 
 * @param ArrayStack* The stack to free.
*/
void ArrayStack_free(ArrayStack* stack);

#endif /* ARRAY_STACK_H */