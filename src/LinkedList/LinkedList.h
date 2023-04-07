/**
 * @file LinkedList.h
 * @brief Linked List class
 * @author Jonathan E
 * @date 07-04-2023
 * 
 * This is a linked list class that can be used to store data in a linked list.
 * This implementation is a singly linked list that makes use of a series of 
 * nodes as the underlying collection.
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

/**
 * Creates a new linked list.
 * 
 * @return the pointer to the linked list.
*/
LinkedList* new_LinkedList();

/**
 * Adds a new node to the linked list.
 * 
 * @param list the pointer to the linked list.
 * @param data the data to be stored in the node.
 * @return true if the node was added successfully, false otherwise.
*/
bool LinkedList_add(LinkedList* list, void* data);

/**
 * Removes a node from the linked list.
 * 
 * @param list the pointer to the linked list.
 * @param data the data to be removed from the linked list.
 * @return true if the node was removed successfully, false otherwise.
*/
bool LinkedList_remove(LinkedList* list, void* data);

/**
 * Gets the data from the node at the specified index.
 * 
 * @param list  the pointer to the linked list.
 * @param index the index of the node to get the data from.
 * @return the data from the node at the specified index.
*/
void* LinkedList_get(LinkedList* list, int index);

/**
 * Gets the size of the linked list.
 * 
 * @param list the pointer to the linked list.
 * @return the size of the linked list.
*/
int LinkedList_size(LinkedList* list);

/**
 * Checks if the linked list is empty.
 * 
 * @param list the pointer to the linked list.
 * @return true if the linked list is empty, false otherwise.
*/
bool LinkedList_isEmpty(LinkedList* list);

/**
 * Checks if the linked list contains the specified data.
 * 
 * @param list the pointer to the linked list.
 * @param data the data to be checked.
*/
bool LinkedList_contains(LinkedList* list, void* data);

/**
 * Gets the index of the specified data.
 * 
 * @param list the pointer to the linked list.
 * @param data the data to be checked.
 * @return the index of the specified data.
*/
int LinkedList_indexOf(LinkedList* list, void* data);

/**
 * Prints the linked list.
 * 
 * @param list the pointer to the linked list.
*/
void LinkedList_print(LinkedList* list);

/**
 * Clears the linked list.
 * 
 * @param list the pointer to the linked list.
 * @return true if the linked list was cleared successfully, false otherwise.
*/
bool LinkedList_clear(LinkedList* list);

/**
 * Frees the memory allocated to the linked list.
 * 
 * @param list the pointer to the linked list.
*/
void LinkedList_free(LinkedList* list);

#endif /* LINKEDLIST_H */