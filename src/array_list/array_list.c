/**
 * @file array_list.c
 * @brief Array list data type implementation
 * @author Jonathan E
 * @date 07-04-2023
 * 
 * This is an implementation of an array list data type that can be used to store
 * generic data.
 * This implementation is a singly linked list that makes use of a dynamic array
 * as the underlying collection.
 * The data stored in the array is a void pointers which is dynamically allocated
 * to the heap.
*/

#include "array_list.h"

/**
 * Creates a new array list, using malloc to allocate memory for the list.
 * 
 * @return the pointer to the array list, or NULL if the memory allocation
 * failed.
*/
array_list* array_list_new() {
  array_list* list = malloc(sizeof(array_list));
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
 * Adds a new node to the array list, using malloc to allocate memory for the
 * node.
 * The data is stored in the node as a void pointer. Note that the data is not
 * copied, but rather the pointer to the data is stored in the node.
 * 
 * @param list the pointer to the array list.
 * @param data the data to be stored in the node.
 * @return true if the node was added successfully, false otherwise.
*/
bool array_list_add(array_list* list, void* data) {
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
 * Removes an element from the array list, using free to deallocate memory for
 * the element.
 * The data is stored in the node as a void pointer. Note that the data is not
 * copied, but rather the pointer to the data is stored in the node.
 * 
 * @param list the pointer to the array list.
 * @param index the index of the element to be removed.
 * @return true if the element was removed successfully, false otherwise.
*/
bool array_list_remove(array_list* list, int index) {
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

  // If the size is 1, free the collection.
  if (list->size == 1) {
    free(list->collection);
    list->collection = NULL;
    list->size--;
    return true;
  }

  // Otherwise, move the elements down the list
    if (index == 0) {
        memmove(&list->collection[0], &list->collection[1], sizeof(void*) * (list->size - 1));
    } else if (index == list->size - 1) {
        memmove(&list->collection[0], &list->collection[0], sizeof(void*) * (list->size - 1));
    } else {
        memmove(&list->collection[index], &list->collection[index + 1], sizeof(void*) * (list->size - index - 1));
    }

    // Update the collection
    void** newData = realloc(list->collection, sizeof(void*) * (list->size - 1));
    list->collection = newData;
    list->size--;
    return true;
}

/**
 * Gets the element at the specified index from the array list.
 * 
 * @param list the pointer to the array list.
 * @param index the index of the element to be retrieved.
 * @return the element at the specified index, or NULL if the index is out of
 * bounds.
*/
void* array_list_get(array_list* list, int index) {
  // If the list is NULL, return NULL.
  if (list == NULL) {
    return NULL;
  }

  // If the collection is NULL, return NULL.
  if (list->collection == NULL) {
    return NULL;
  }

  // If the index is out of bounds, return NULL.
  if (index < 0 || index >= list->size) {
    return NULL;
  }

  // Otherwise, return the element at the specified index.
  return list->collection[index];
}

/**
 * Gets the size of the array list.
 * 
 * @param list the pointer to the array list.
 * @return the size of the array list.
*/
int array_list_size(array_list* list) {
  // If the list is NULL, return 0.
  if (list == NULL) {
    return 0;
  }

  // Otherwise, return the size of the list.
  return list->size;
}

/**
 * Checks if the array list is empty.
 * 
 * @param list the pointer to the array list.
 * @return true if the array list is empty, false otherwise.
*/
bool array_list_isEmpty(array_list* list) {
  // If the list is NULL, return true.
  if (list == NULL) {
    return true;
  }

  return list->size == 0;
}

/**
 * Checks if the array list contains the specified element.
 * 
 * @param list the pointer to the array list.
 * @param data the data to be checked.
 * @return true if the array list contains the specified element, false
 * otherwise.
*/
bool array_list_contains(array_list* list, void* data) {
  // If the list is NULL, return false.
  if (list == NULL) {
    return false;
  }

  // If the collection is NULL, return false.
  if (list->collection == NULL) {
    return false;
  }

  // Otherwise, iterate through the list and check if the data is in the list.
  for (int i = 0; i < list->size; i++) {
    if (list->collection[i] == data) {
      return true;
    }
  }

  return false;
}

/**
 * Gets the index of the specified element in the array list.
 * 
 * @param list the pointer to the array list.
 * @param data the data to be checked.
 * @return the index of the specified element, or -1 if the element is not in
 * the list.
*/
int array_list_indexOf(array_list* list, void* data) {
  // If the list is NULL, return -1.
  if (list == NULL) {
    return -1;
  }

  // If the collection is NULL, return -1.
  if (list->collection == NULL) {
    return -1;
  }

  // Otherwise, iterate through the list and check if the data is in the list.
  for (int i = 0; i < list->size; i++) {
    if (list->collection[i] == data) {
      return i;
    }
  }

  return -1;
}

/**
 * Prints the array list as a list of integers.
 * 
 * @param list the pointer to the array list.
*/
void array_list_print(array_list* list) {
  // If the list is NULL, print "NULL".
  if (list == NULL) {
    printf("NULL\n");
    return;
  }

  // Print the list.
  printf("[");
  for (int i = 0; i < list->size; i++) {
    printf("%d ", *(int*)list->collection[i]);
  }
  printf("]\n");
}

/**
 * Clears the array list, freeing all memory associated with the list.
 * 
 * @param list the pointer to the array list.
 * @return true if the array list was cleared successfully, false otherwise.
*/
bool array_list_clear(array_list* list) {
  // If the list is NULL, return false.
  if (list == NULL) {
    return false;
  }

  // If the collection is NULL, return false.
  if (list->collection == NULL) {
    return false;
  }

  // Otherwise, free the collection and set it to NULL.
  void** new_collection = realloc(list->collection, sizeof(void*));
  if (new_collection == NULL) {
    return false;
  }
  list->collection = new_collection;
  list->collection = NULL;
  list->size = 0;
  return true;
}

/**
 * Frees the array list, freeing all memory associated with the list.
 * 
 * @param list the pointer to the array list.
 * @return true if the array list was freed successfully, false otherwise.
*/
bool array_list_free(array_list* list) {
  // If the list is NULL, return false.
  if (list == NULL) {
    return true;
  }

  // If the collection is NULL, free the list and return true.
  if (list->collection == NULL) {
    free(list);
    return true;
  }

  // Otherwise, free the collection and the list.
  free(list->collection);
  free(list);
  return true;
}