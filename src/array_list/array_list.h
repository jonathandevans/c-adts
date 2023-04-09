/**
 * @file array_list.h
 * @brief List data type implementation using a dynamic array
 * @author Jonathan E
 * @date 07-04-2023
 * 
 * This is a list data type that can be used to store data in a singly linked
 * list data structure.
 * This implementation is a list that makes use of a dynamic array as 
 * the underlying collection.
 * The data stored in the list are void pointers which are dynamically allocated
 * to the heap.
*/

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ArrayList {
  void** collection;
  int size;
} ArrayList;

/**
 * Creates a new list using a dynamic array as the underlying collection.
 * 
 * @return The new array list, or NULL if the array list could not be created.
*/
ArrayList* new_ArrayList();

/**
 * Adds a new element to the end of the given array list.
 * The data is stored in the array list as a void pointer. Note that the data
 * is not copied, but rather the pointer to the data is stored in the array list.
 * 
 * @param ArrayList* The array list to add the element to.
 * @param void*      The pointer to the element to add to the array list.
 * @return true if the element was added successfully, false otherwise.
*/
bool ArrayList_add(ArrayList*, void*);

/**
 * Removes the element at the given index from the given array list.
 * The data is not freed, but rather the pointer to the data is removed 
 * from the array list.
 * 
 * @param ArrayList* The array list to remove the element from.
 * @param int        The index of the element to remove.
 * @return true if the element was removed successfully, false otherwise.
*/
bool ArrayList_remove(ArrayList*, int);

/**
 * Gets the element at the given index from the given array list.
 * The data is not copied, but rather the pointer to the data is returned.
 * 
 * @param ArrayList* The array list to get the element from.
 * @param int        The index of the element to get.
 * @return The element at the given index, or NULL if the index is out of bounds.
*/
bool ArrayList_get(ArrayList*, int);

/**
 * Gets the size of the given array list.
 * 
 * @param ArrayList* The array list to get the size of.
 * @return The size of the given array list, or -1 if the array list is NULL.
*/
int ArrayList_size(ArrayList*);

/**
 * Checks if the array list is empty.
 * 
 * @param ArrayList* The array list to check.
 * @return true if the array list is empty, false otherwise.
*/
bool ArrayList_isEmpty(ArrayList*);

/**
 * Checks if the array list contains the given element.
 * The data stored is a void pointer, so the data is not compared directly
 * but rather the pointers to the data are compared.
 * 
 * @param ArrayList* The array list to check.
 * @param void*      The data to check for.
 * @return true if the array list contains the given element, false otherwise.
*/
bool ArrayList_contains(ArrayList*, void*);

/**
 * Gets the index of the given element in the given array list.
 * The data stored is a void pointer, so the data is not compared directly
 * but rather the pointers to the data are compared.
 * 
 * @param ArrayList* The array list to search.
 * @param void*      The data to search for.
 * @return The index of the given element in the given array list, or -1 if 
 *         the element is not found.
*/
int ArrayList_indexOf(ArrayList*, void*);

/**
 * Prints the given array list as a list of pointers.
 * 
 * @param ArrayList* The array list to print.
*/
void ArrayList_print(ArrayList*);

/**
 * Prints the given array list as a list of integers.
 * 
 * @param ArrayList* The array list to print.
*/
void ArrayList_printInt(ArrayList*);

/**
 * Clears the given array list.
 * 
 * @param ArrayList* The array list to clear.
 * @return true if the array list was cleared successfully, false otherwise.
*/
bool ArrayList_clear(ArrayList*);

/**
 * Frees the given array list.
 * 
 * @param ArrayList* The array list to free.
*/
void ArrayList_free(ArrayList*);

#endif /* ARRAYLIST_H */
