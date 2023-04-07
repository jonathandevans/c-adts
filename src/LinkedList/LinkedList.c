/**
 * @file LinkedList.c
 * @brief Linked List class implementation
 * @author Jonathan E
 * @date 07-04-2023
 * 
 * This is an implementation of a linked list class that can be used to store
 * generic data.
 * This implementation is a singly linked list that makes use of a series of
 * nodes as the underlying collection.
 * The data stored in the nodes is a void pointer which is dynamically allocated
 * to the heap.
*/

#include "LinkedList.h"

/**
 * Creates a new linked list, using malloc to allocate memory for the list.
 * 
 * @return the pointer to the linked list, or NULL if the memory allocation
 * failed.
*/
LinkedList* new_LinkedList() {
  LinkedList* list = malloc(sizeof(LinkedList));
  // If the memory allocation failed, return NULL.
  if (list == NULL) {
    return NULL;
  }

  // Initialise the list.
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

/**
 * Adds a new node to the linked list, using malloc to allocate memory for the
 * node.
 * The data is stored in the node as a void pointer. Note that the data is not
 * copied, but rather the pointer to the data is stored in the node.
 * 
 * @param list the pointer to the linked list.
 * @param data the data to be stored in the node.
 * @return true if the node was added successfully, false otherwise.
*/
bool LinkedList_add(LinkedList* list, void* data) {
  // If the list is NULL, return false.
  if (list == NULL) {
    return false;
  }

  Node* node = malloc(sizeof(Node));
  // If the memory allocation failed, return false.
  if (node == NULL) {
    return false;
  }

  // Initialise the node.
  node->data = data;
  node->next = NULL;

  // Add the node to the list.
  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }

  list->size++;
  return true;
}

/**
 * Removes a given index from the linked list, using free to deallocate memory.
 * Only the pointer to the data is freed, not the data itself.
 * 
 * @param list  the pointer to the linked list.
 * @param index the index of the node to be removed.
 * @return true if the node was removed successfully, false otherwise.
*/
bool LinkedList_remove(LinkedList* list, int index) {
  // If the list is NULL, return false.
  if (list == NULL) {
    return false;
  }

  // If the index is out of bounds, return false.
  if (index < 0 || index >= list->size) {
    return false;
  }

  // If the index is 0, remove the head.
  if (index == 0) {
    Node* node = list->head;
    list->head = list->head->next;
    free(node);
  } else {
    // Find the node before the node to be removed.
    Node* node = list->head;
    for (int i = 0; i < index - 1; i++) {
      node = node->next;
    }

    // Remove the node.
    Node* temp = node->next;
    node->next = node->next->next;
    free(temp);
  }

  list->size--;
  return true;
}

/**
 * Gets the data from the node at the specified index.
 * 
 * @param list  the pointer to the linked list.
 * @param index the index of the node to get the data from.
 * @return the data from the node at the specified index, or NULL if the index
 * is out of bounds.
*/
void* LinkedList_get(LinkedList* list, int index) {
  // If the list is NULL, return NULL.
  if (list == NULL) {
    return NULL;
  }

  // If the index is out of bounds, return NULL.
  if (index < 0 || index >= list->size) {
    return NULL;
  }

  // Find the node at the specified index.
  Node* node = list->head;
  for (int i = 0; i < index; i++) {
    node = node->next;
  }

  return node->data;
}

/**
 * Gets the size of the linked list.
 * 
 * @param list the pointer to the linked list.
 * @return the size of the linked list, or -1 if the list is NULL.
*/
int LinkedList_size(LinkedList* list) {
  // If the list is NULL, return 0.
  if (list == NULL) {
    return -1;
  }

  return list->size;
}

/**
 * Checks if the linked list is empty.
 * 
 * @param list the pointer to the linked list.
 * @return true if the linked list is empty, false otherwise.
*/
bool LinkedList_isEmpty(LinkedList* list) {
  // If the list is NULL, return true.
  if (list == NULL) {
    return true;
  }

  return list->size == 0;
}

/**
 * Checks if the linked list contains the specified data.
 * 
 * @param list the pointer to the linked list.
 * @param data the data to check for.
 * @return true if the linked list contains the specified data, false otherwise.
*/
bool LinkedList_contains(LinkedList* list, void* data) {
  // If the list is NULL, return false.
  if (list == NULL) {
    return false;
  }

  // Find the node with the specified data.
  Node* node = list->head;
  while (node != NULL) {
    if (node->data == data) {
      return true;
    }
    node = node->next;
  }

  return false;
}

/**
 * Gets the index of the node with the specified data.
 * 
 * @param list the pointer to the linked list.
 * @param data the data to check for.
 * @return the index of the node with the specified data, or -1 if the data is
 * not found.
*/
int LinkedList_indexOf(LinkedList* list, void* data) {
  // If the list is NULL, return -1.
  if (list == NULL) {
    return -1;
  }

  // Find the node with the specified data.
  Node* node = list->head;
  int index = 0;
  while (node != NULL) {
    if (node->data == data) {
      return index;
    }
    node = node->next;
    index++;
  }

  return -1;
}

/**
 * Prints the linked list.
 * 
 * @param list the pointer to the linked list.
*/
void LinkedList_print(LinkedList* list) {
  // If the list is NULL, return.
  if (list == NULL) {
    return;
  }

  // Print the list.
  printf("[");
  Node* node = list->head;
  while (node != NULL) {
    printf("%d ", *(int*)node->data);
    node = node->next;
  }
  printf("]\n");
}

/**
 * Removes all nodes from the linked list, using free to deallocate memory.
 * Only the pointer to the data is freed, not the data itself.
 * 
 * @param list the pointer to the linked list.
 * @return true if the nodes were removed successfully, false otherwise.
*/
bool LinkedList_clear(LinkedList* list) {
  // If the list is NULL, return false.
  if (list == NULL) {
    return false;
  }

  // Remove all nodes.
  while (list->head != NULL) {
    Node* node = list->head;
    list->head = list->head->next;
    free(node);
  }

  list->size = 0;
  return true;
}

/**
 * Deallocates the memory used by the linked list, using free to deallocate
 * memory. Only the pointer to the data is freed, not the data itself.
 * 
 * @param list the pointer to the linked list.
 * @return true if the memory was deallocated successfully, false otherwise.
*/
bool LinkedList_free(LinkedList* list) {
  // If the list is NULL, return false.
  if (list == NULL) {
    return false;
  }

  // Remove all nodes.
  while (list->head != NULL) {
    Node* node = list->head;
    list->head = list->head->next;
    free(node);
  }

  // Deallocate the list.
  free(list);
  return true;
}
