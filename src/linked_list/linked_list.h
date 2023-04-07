/**
 * @file linked_list.h
 * @brief Linked list data type
 * @author Jonathan E
 * @date 07-04-2023
 * 
 * This is a linked list data type that can be used to store data in a linked 
 * list.
 * This implementation is a singly linked list that makes use of a series of 
 * nodes as the underlying collection.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    void* data;
    struct node* next;
} node;

typedef struct linked_list {
    node* head;
    node* tail;
    int size;
} linked_list;

/**
 * Creates a new linked list.
 * 
 * @return the pointer to the linked list.
*/
linked_list* new_linked_list();

/**
 * Adds a new node to the linked list.
 * 
 * @param list the pointer to the linked list.
 * @param data the data to be stored in the node.
 * @return true if the node was added successfully, false otherwise.
*/
bool linked_list_add(linked_list* list, void* data);

/**
 * Removes a given index from the linked list.
 * 
 * @param list  the pointer to the linked list.
 * @param index the index of the node to be removed.
 * @return true if the node was removed successfully, false otherwise.
*/
bool linked_list_remove(linked_list* list, int index);

/**
 * Gets the data from the node at the specified index.
 * 
 * @param list  the pointer to the linked list.
 * @param index the index of the node to get the data from.
 * @return the data from the node at the specified index.
*/
void* linked_list_get(linked_list* list, int index);

/**
 * Gets the size of the linked list.
 * 
 * @param list the pointer to the linked list.
 * @return the size of the linked list.
*/
int linked_list_size(linked_list* list);

/**
 * Checks if the linked list is empty.
 * 
 * @param list the pointer to the linked list.
 * @return true if the linked list is empty, false otherwise.
*/
bool linked_list_isEmpty(linked_list* list);

/**
 * Checks if the linked list contains the specified data.
 * 
 * @param list the pointer to the linked list.
 * @param data the data to be checked.
 * @return true if the linked list contains the specified data, false otherwise.
*/
bool linked_list_contains(linked_list* list, void* data);

/**
 * Gets the index of the specified data.
 * 
 * @param list the pointer to the linked list.
 * @param data the data to be checked.
 * @return the index of the specified data.
*/
int linked_list_indexOf(linked_list* list, void* data);

/**
 * Prints the linked list as a list of integers.
 * 
 * @param list the pointer to the linked list.
*/
void linked_list_print(linked_list* list);

/**
 * Clears the linked list.
 * 
 * @param list the pointer to the linked list.
 * @return true if the linked list was cleared successfully, false otherwise.
*/
bool linked_list_clear(linked_list* list);

/**
 * Frees the memory allocated to the linked list.
 * 
 * @param list the pointer to the linked list.
 * @return true if the memory was freed successfully, false otherwise.
*/
bool linked_list_free(linked_list* list);

#endif /* LINKEDLIST_H */