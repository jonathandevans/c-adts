/**
 * @file linked_list.h
 * @brief Linked list data type implementation using a node structure
 * @author Jonathan E
 * @date 07-04-2023
 * 
 * This is a linked list data type that can be used to store data in a linked 
 * list structure.
 * This implementation is a singly linked list that makes use of a series of 
 * nodes as the underlying collection.
 * The data stored in the nodes is a void pointer which is dynamically allocated
 * to the heap.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List_Node {
  void* data;
  struct List_Node* next;
} List_Node;

typedef struct LinkedList {
  List_Node* head;
  List_Node* tail;
  int size;
} LinkedList;

/**
 * Creates a new linked list using a series of nodes as the underlying collection.
 * 
 * @return A pointer to the new linked list.
*/
LinkedList* new_LinkedList();

/**
 * Adds a new node to the linked list.
 * The data is stored as a node in a series of nodes. Note that the data is not
 * copied, but rather the pointer to the data is copied.
 * 
 * @param LinkedList* the pointer to the linked list.
 * @param void*       the data to be stored in the node.
 * @return true if the node was added successfully, false otherwise.
*/
bool LinkedList_add(LinkedList*, void*);

/**
 * Removes a given index from the linked list.
 * 
 * @param LinkedList* the pointer to the linked list.
 * @param int         the index of the node to be removed.
 * @return true if the node was removed successfully, false otherwise.
*/
bool LinkedList_remove(LinkedList*, int);

/**
 * Gets the data from the node at the specified index.
 * The data is stored as a node in a series of nodes. Note that the data is not
 * copied, but rather the pointer to the data is copied.
 * 
 * @param LinkedList* the pointer to the linked list.
 * @param int         the index of the node to get the data from.
 * @return the data from the node at the specified index.
*/
void* LinkedList_get(LinkedList*, int);

/**
 * Gets the size of the linked list.
 * 
 * @param LinkedList* the pointer to the linked list.
 * @return the size of the linked list.
*/
int LinkedList_size(LinkedList*);

/**
 * Checks if the linked list is empty.
 * 
 * @param LinkedList* the pointer to the linked list.
 * @return true if the linked list is empty, false otherwise.
*/
bool LinkedList_isEmpty(LinkedList*);

/**
 * Checks if the linked list contains the specified data.
 * The data is stored as a node in a series of nodes. Note that the data is not
 * copied, but rather the pointer to the data is copied. When checking if the
 * linked list contains the specified data, the pointer to the data is checked.
 * 
 * @param LinkedList* the pointer to the linked list.
 * @param void*       the data to be checked.
 * @return true if the linked list contains the specified data, false otherwise.
*/
bool LinkedList_contains(LinkedList*, void*);

/**
 * Gets the index of the specified data in the linked list.
 * The data is stored as a node in a series of nodes. Note that the data is not
 * copied, but rather the pointer to the data is copied. When checking if the
 * linked list contains the specified data, the pointer to the data is checked.
 * 
 * @param LinkedList* the pointer to the linked list.
 * @param void*       the data to be checked.
 * @return the index of the specified data, or -1 if the data is not in the
 *         linked list.
*/
int LinkedList_indexOf(LinkedList*, void*);

/**
 * Prints the linked list as a list of pointers.
 * 
 * @param LinkedList* the pointer to the linked list.
*/
void LinkedList_print(LinkedList*);

/**
 * Prints the linked list as a list of integers.
 * 
 * @param LinkedList* the pointer to the linked list.
*/
void LinkedList_printInt(LinkedList*);

/**
 * Clears the given linked list.
 * 
 * @param LinkedList* the pointer to the linked list.
 * @return true if the linked list was cleared successfully, false otherwise.
*/
bool LinkedList_clear(LinkedList*);

/**
 * Frees the memory allocated to the linked list.
 * 
 * @param LinkedList* the pointer to the linked list.
*/
void LinkedList_free(LinkedList*);

#endif /* LINKEDLIST_H */