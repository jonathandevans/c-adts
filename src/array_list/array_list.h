/**
 * @file array_list.h
 * @brief Array list data type
 * @author Jonathan E
 * @date 07-04-2023
 * 
 * This is an array list data type that can be used to store data in a list.
 * This implementation is a singly linked list that makes use of a dynamic 
 * array as the underlying collection.
*/

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct array_list {
    void** collection;
    int size;
} array_list;

/**
 * Creates a new array list.
 * 
 * @return A pointer to the new array list.
*/
array_list* new_array_list();

/**
 * Adds a new element to the end of the given array list.
 * 
 * @param list    The array list to add the element to.
 * @param element The pointer to the element to add to the array list.
 * @return true if the element was added successfully, false otherwise.
*/
bool array_list_add(array_list *list, void *data);

/**
 * Removes the element at the given index from the given array list.
 * 
 * @param list  The array list to remove the element from.
 * @param index The index of the element to remove.
 * @return true if the element was removed successfully, false otherwise.
*/
bool array_list_remove(array_list *list, int index);

/**
 * Gets the element at the given index from the given array list.
 * 
 * @param list  The array list to get the element from.
 * @param index The index of the element to get.
 * @return The element at the given index, or NULL if the index is out of bounds.
*/
void* array_list_get(array_list *list, int index);

/**
 * Gets the size of the given array list.
 * 
 * @param list The array list to get the size of.
 * @return The size of the given array list.
*/
int array_list_size(array_list *list);

/**
 * Checks if the array list is empty.
 * 
 * @param list The array list to check.
 * @return true if the array list is empty, false otherwise.
*/
bool array_list_isEmpty(array_list *list);

/**
 * Checks if the array list contains the given element.
 * 
 * @param list The array list to check.
 * @param data The data to check for.
 * @return true if the array list contains the given element, false otherwise.
*/
bool array_list_contains(array_list *list, void *data);

/**
 * Gets the index of the given element in the given array list.
 * 
 * @param list The array list to search.
 * @param data The data to search for.
 * @return The index of the given element in the given array list, or -1 if the element is not found.
*/
int array_list_indexOf(array_list *list, void *data);

/**
 * Prints the given array list as a list of integers.
 * 
 * @param list The array list to print.
*/
void array_list_print(array_list *list);

/**
 * Clears the given array list.
 * 
 * @param list The array list to clear.
 * @return true if the array list was cleared successfully, false otherwise.
*/
bool array_list_clear(array_list *list);

/**
 * Frees the given array list.
 * 
 * @param list The array list to free.
 * @return true if the array list was freed successfully, false otherwise.
*/
bool array_list_free(array_list *list);

#endif /* ARRAYLIST_H */
