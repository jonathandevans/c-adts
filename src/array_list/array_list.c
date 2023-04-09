/**
 * @file array_list.c
 * @brief List data type implementation using a dynamic array
 * @author Jonathan E
 * @date 07-04-2023
 * 
 * This is an implementation of a list data type that can be used to store data in 
 * a singly linked list data structure.
 * This implementation is a singly linked list that makes use of a dynamic array
 * as the underlying collection.
 * The data stored in the array is a void pointers which is dynamically allocated
 * to the heap.
*/

#include "array_list.h"

/**
 * Creates a new list using a dynamic array as the underlying collection.
 * 
 * @return The new array list, or NULL if the array list could not be created.
*/
ArrayList* new_ArrayList() {
  ArrayList* list = malloc(sizeof(ArrayList));
  // If the memory allocation failed, return NULL.
  if (list == NULL) {
    return NULL;
  }

  // Initialise the collection.
  void** new_collection = malloc(sizeof(void*));
  // If the memory allocation failed, return NULL.
  if (new_collection == NULL) {
    return NULL;
  }

  // Initialise the list.
  list->collection = new_collection;
  list->size = 0;
  return list;
}

/**
 * Adds a new element to the end of the given array list.
 * The data is stored in the array list as a void pointer. Note that the data
 * is not copied, but rather the pointer to the data is stored in the array list.
 * 
 * @param ArrayList* The array list to add the element to.
 * @param void*      The pointer to the element to add to the array list.
 * @return true if the element was added successfully, false otherwise.
*/
bool ArrayList_add(ArrayList* list, void* data) {
  // If the list is NULL, return false.
  if (list == NULL) {
    return false;
  }

  // If the collection is NULL, return false.
  if (list->collection == NULL) {
    return false;
  }

  // If the size is 0, initialise the collection.
  if (list->size == 0) {
    list->collection[0] = data;
    list->size++;
    return true;
  }

  // If the size is not 0, reallocate the collection.
  void** new_collection = realloc(list->collection, sizeof(void*) * (list->size + 1));
  // If the memory allocation failed, return false.
  if (new_collection == NULL) {
    return false;
  }

  // Add the data to the collection.
  new_collection[list->size] = data;
  list->collection = new_collection;
  list->size++;
  return true;
}

/**
 * Removes the element at the given index from the given array list.
 * The data is not freed, but rather the pointer to the data is removed 
 * from the array list.
 * 
 * @param ArrayList* The array list to remove the element from.
 * @param int        The index of the element to remove.
 * @return true if the element was removed successfully, false otherwise.
*/
bool ArrayList_remove(ArrayList* list, int index) {
  // If the list is NULL, return false.
  if (list == NULL) {
    return false;
  }

  // If the collection is NULL, return false.
  if (list->collection == NULL) {
    return false;
  }

  // If the index is out of bounds, return false.
  if (index < 0 || index >= list->size) {
    return false;
  }

  if (list->size == 1) {
    list->collection = NULL;
    list->size--;
    return true;
  }

  if (index == 0) {
    memmove(&list->collection[0], &list->collection[1], sizeof(void*) * (list->size - 1));
  } else if (index == list->size - 1) {
    memmove(&list->collection[0], &list->collection[0], sizeof(void*) * (list->size - 1));
  } else {
    memmove(&list->collection[index], &list->collection[index + 1], sizeof(void*) * (list->size - index - 1));
  }

  // If the size is not 1, reallocate the collection.
  void** new_collection = realloc(list->collection, sizeof(void*) * (list->size - 1));
  // If the memory allocation failed, return false.
  if (new_collection == NULL) {
    return false;
  }

  list->collection = new_collection;
  list->size--;
  return true;
}

/**
 * Gets the element at the given index from the given array list.
 * The data is not copied, but rather the pointer to the data is returned.
 * 
 * @param ArrayList* The array list to get the element from.
 * @param int        The index of the element to get.
 * @return The element at the given index, or NULL if the index is out of bounds.
*/
bool ArrayList_get(ArrayList* list, int index) {
  // If the list is NULL, return false.
  if (list == NULL) {
    return false;
  }

  // If the collection is NULL, return false.
  if (list->collection == NULL) {
    return false;
  }

  // If the index is out of bounds, return false.
  if (index < 0 || index >= list->size) {
    return false;
  }

  return list->collection[index];
}

/**
 * Gets the size of the given array list.
 * 
 * @param ArrayList* The array list to get the size of.
 * @return The size of the given array list, or -1 if the array list is NULL.
*/
int ArrayList_size(ArrayList* list) {
  // If the list is NULL, return 0.
  if (list == NULL) {
    return -1;
  }

  return list->size;
}

/**
 * Checks if the array list is empty.
 * 
 * @param ArrayList* The array list to check.
 * @return true if the array list is empty, false otherwise.
*/
bool ArrayList_isEmpty(ArrayList* list) {
  // If the list is NULL, return true.
  if (list == NULL) {
    return true;
  }

  return list->size == 0;
}

/**
 * Checks if the array list contains the given element.
 * The data stored is a void pointer, so the data is not compared directly
 * but rather the pointers to the data are compared.
 * 
 * @param ArrayList* The array list to check.
 * @param void*      The data to check for.
 * @return true if the array list contains the given element, false otherwise.
*/
bool ArrayList_contains(ArrayList* list, void* data) {
  // If the list is NULL, return false.
  if (list == NULL) {
    return false;
  }

  // If the collection is NULL, return false.
  if (list->collection == NULL) {
    return false;
  }

  // Iterate through the collection.
  for (int i = 0; i < list->size; i++) {
    // If the data is found, return true.
    if (list->collection[i] == data) {
      return true;
    }
  }

  // If the data is not found, return false.
  return false;
}

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
int ArrayList_indexOf(ArrayList* list, void* data) {
  // If the list is NULL, return -1.
  if (list == NULL) {
    return -1;
  }

  // If the collection is NULL, return -1.
  if (list->collection == NULL) {
    return -1;
  }

  // Iterate through the collection.
  for (int i = 0; i < list->size; i++) {
    // If the data is found, return the index.
    if (list->collection[i] == data) {
      return i;
    }
  }

  // If the data is not found, return -1.
  return -1;
}

/**
 * Prints the given array list as a list of pointers.
 * 
 * @param ArrayList* The array list to print.
*/
void ArrayList_print(ArrayList* list) {
  // If the list is NULL, print NULL.
  if (list == NULL) {
    printf("NULL\n");
    return;
  }

  printf("[ ");
  for (int i = 0; i < list->size; i++) {
    printf("%p ", list->collection[i]);
  }
  printf("]\n");
}

/**
 * Prints the given array list as a list of integers.
 * 
 * @param ArrayList* The array list to print.
*/
void ArrayList_printInt(ArrayList* list) {
  // If the list is NULL, print NULL.
  if (list == NULL) {
    printf("NULL\n");
    return;
  }

  printf("[ ");
  for (int i = 0; i < list->size; i++) {
    printf("%d ", *(int*) list->collection[i]);
  }
  printf("]\n");
}

/**
 * Clears the given array list.
 * 
 * @param ArrayList* The array list to clear.
 * @return true if the array list was cleared successfully, false otherwise.
*/
bool ArrayList_clear(ArrayList* list) {
  // If the list is NULL, return false.
  if (list == NULL) {
    return false;
  }

  // If the collection is NULL, return false.
  if (list->collection == NULL) {
    return false;
  }

  // Reduce the collection.
  void** new_collection = realloc(list->collection, sizeof(void*));
  // If the memory allocation failed, return false.
  if (new_collection == NULL) {
    return false;
  }
  list->collection = new_collection;
  list->collection[0] = NULL;
  list->size = 0;
  return true;
}

/**
 * Frees the given array list.
 * 
 * @param ArrayList* The array list to free.
*/
void ArrayList_free(ArrayList* list) {
  // If the list is NULL, return.
  if (list == NULL) {
    return;
  }

  // If the collection is NULL, free the list and return.
  if (list->collection == NULL) {
    free(list);
    return;
  }

  // Free the collection and the list.
  free(list->collection);
  free(list);
}