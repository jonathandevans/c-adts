/**
 * @file array_list_test.c
 * @brief Test file for array_list.c
 * @author Jonathan E
 * @date 09-04-2023
 * 
 * This file contains the test functions for array_list.c.
 * By running this file, you can test the functions in array_list.c with
 * the test cases outputted to the console.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../src/array_list/array_list.h"

/**
 * Test function for new_ArrayList().
 * 
 * @return true if the test passes, false otherwise.
*/
bool test_new_ArrayList() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  if (list->size != 0) {
    return false;
  }

  if (list->collection == NULL) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

/**
 * Test function for ArrayList_add().
 * 
 * @return true if the test passes, false otherwise.
*/
bool test_ArrayList_add() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element = 1;

  if (!ArrayList_add(list, &element)) {
    return false;
  }

  if (list->size != 1) {
    return false;
  }

  if (*(int*)list->collection[0] != 1) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_add_multiple() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element1 = 1;
  int element2 = 2;
  int element3 = 3;

  if (!ArrayList_add(list, &element1)) {
    return false;
  }

  if (!ArrayList_add(list, &element2)) {
    return false;
  }

  if (!ArrayList_add(list, &element3)) {
    return false;
  }

  if (list->size != 3) {
    return false;
  }

  if (*(int*)list->collection[0] != 1) {
    return false;
  }

  if (*(int*)list->collection[1] != 2) {
    return false;
  }

  if (*(int*)list->collection[2] != 3) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_add_to_null() {
  ArrayList* list = NULL;

  int element = 1;

  if (ArrayList_add(list, &element)) {
    return false;
  }

  return true;
}

/**
 * Test function for ArrayList_remove().
 * 
 * @return true if the test passes, false otherwise.
*/
bool test_ArrayList_remove() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element = 1;

  if (!ArrayList_add(list, &element)) {
    return false;
  }

  if (!ArrayList_remove(list, 0)) {
    return false;
  }

  if (list->size != 0) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_remove_multiple() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element1 = 1;
  int element2 = 2;
  int element3 = 3;

  if (!ArrayList_add(list, &element1)) {
    return false;
  }

  if (!ArrayList_add(list, &element2)) {
    return false;
  }

  if (!ArrayList_add(list, &element3)) {
    return false;
  }

  if (!ArrayList_remove(list, 1)) {
    return false;
  }
  if (list->collection[0] != &element1) {
    return false;
  }
  if (list->collection[1] != &element3) {
    return false;
  }
  if (list->size != 2) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_remove_from_null() {
  ArrayList* list = NULL;

  if (ArrayList_remove(list, 0)) {
    return false;
  }

  return true;
}

bool test_ArrayList_remove_index_too_large() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element = 1;

  if (!ArrayList_add(list, &element)) {
    return false;
  }

  if (ArrayList_remove(list, 1)) {
    return false;
  }

  if (list->size != 1) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_remove_index_too_small() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element = 1;

  if (!ArrayList_add(list, &element)) {
    return false;
  }

  if (ArrayList_remove(list, -1)) {
    return false;
  }

  if (list->size != 1) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_remove_from_empty() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  if (ArrayList_remove(list, 0)) {
    return false;
  }

  if (list->size != 0) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

/**
 * Test function for ArrayList_get().
 * 
 * @return true if the test passes, false otherwise.
*/
bool test_ArrayList_get() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element = 1;

  if (!ArrayList_add(list, &element)) {
    return false;
  }

  if (*(int*)ArrayList_get(list, 0) != 1) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_get_multiple() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element1 = 1;
  int element2 = 2;
  int element3 = 3;

  if (!ArrayList_add(list, &element1)) {
    return false;
  }

  if (!ArrayList_add(list, &element2)) {
    return false;
  }

  if (!ArrayList_add(list, &element3)) {
    return false;
  }

  if (*(int*)ArrayList_get(list, 0) != 1) {
    return false;
  }

  if (*(int*)ArrayList_get(list, 1) != 2) {
    return false;
  }

  if (*(int*)ArrayList_get(list, 2) != 3) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_get_from_null() {
  ArrayList* list = NULL;

  if (ArrayList_get(list, 0) != NULL) {
    return false;
  }

  return true;
}

bool test_ArrayList_get_index_too_large() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element = 1;

  if (!ArrayList_add(list, &element)) {
    return false;
  }

  if (ArrayList_get(list, 1) != NULL) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_get_index_too_small() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element = 1;

  if (!ArrayList_add(list, &element)) {
    return false;
  }

  if (ArrayList_get(list, -1) != NULL) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_get_from_empty() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  if (ArrayList_get(list, 0) != NULL) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

/**
 * Test function for ArrayList_size().
 * 
 * @return true if the test passes, false otherwise.
*/
bool test_ArrayList_size() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element = 1;

  if (!ArrayList_add(list, &element)) {
    return false;
  }

  if (ArrayList_size(list) != 1) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_size_with_multiple() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element1 = 1;
  int element2 = 2;
  int element3 = 3;

  if (!ArrayList_add(list, &element1)) {
    return false;
  }

  if (!ArrayList_add(list, &element2)) {
    return false;
  }

  if (!ArrayList_add(list, &element3)) {
    return false;
  }

  if (ArrayList_size(list) != 3) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_size_from_null() {
  ArrayList* list = NULL;

  if (ArrayList_size(list) != -1) {
    return false;
  }

  return true;
}

bool test_ArrayList_size_from_empty() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  if (ArrayList_size(list) != 0) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

/**
 * Test function for ArrayList_isEmpty().
 * 
 * @return true if the test passes, false otherwise.
*/
bool test_ArrayList_isEmpty() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  if (!ArrayList_isEmpty(list)) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_isEmpty_with_multiple() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element1 = 1;
  int element2 = 2;
  int element3 = 3;

  if (!ArrayList_add(list, &element1)) {
    return false;
  }

  if (!ArrayList_add(list, &element2)) {
    return false;
  }

  if (!ArrayList_add(list, &element3)) {
    return false;
  }

  if (ArrayList_isEmpty(list)) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_isEmpty_from_null() {
  ArrayList* list = NULL;

  if (!ArrayList_isEmpty(list)) {
    return false;
  }

  return true;
}

/**
 * Test function for ArrayList_contains().
 * 
 * @return true if the test passes, false otherwise.
*/
bool test_ArrayList_contains() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element = 1;

  if (!ArrayList_add(list, &element)) {
    return false;
  }

  if (!ArrayList_contains(list, &element)) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_contains_with_multiple() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element1 = 1;
  int element2 = 2;
  int element3 = 3;

  if (!ArrayList_add(list, &element1)) {
    return false;
  }

  if (!ArrayList_add(list, &element2)) {
    return false;
  }

  if (!ArrayList_add(list, &element3)) {
    return false;
  }

  if (!ArrayList_contains(list, &element1)) {
    return false;
  }

  if (!ArrayList_contains(list, &element2)) {
    return false;
  }

  if (!ArrayList_contains(list, &element3)) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_contains_from_null() {
  ArrayList* list = NULL;

  int element = 1;

  if (ArrayList_contains(list, &element)) {
    return false;
  }

  return true;
}

bool test_ArrayList_contains_from_empty() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element = 1;

  if (ArrayList_contains(list, &element)) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

/**
 * Test function for ArrayList_indexOf().
 * 
 * @return true if the test passes, false otherwise.
*/
bool test_ArrayList_indexOf() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element = 1;

  if (!ArrayList_add(list, &element)) {
    return false;
  }

  if (ArrayList_indexOf(list, &element) != 0) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_indexOf_with_multiple() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element1 = 1;
  int element2 = 2;
  int element3 = 3;

  if (!ArrayList_add(list, &element1)) {
    return false;
  }

  if (!ArrayList_add(list, &element2)) {
    return false;
  }

  if (!ArrayList_add(list, &element3)) {
    return false;
  }

  if (ArrayList_indexOf(list, &element1) != 0) {
    return false;
  }

  if (ArrayList_indexOf(list, &element2) != 1) {
    return false;
  }

  if (ArrayList_indexOf(list, &element3) != 2) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_indexOf_from_null() {
  ArrayList* list = NULL;

  int element = 1;

  if (ArrayList_indexOf(list, &element) != -1) {
    return false;
  }

  return true;
}

bool test_ArrayList_indexOf_from_empty() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element = 1;

  if (ArrayList_indexOf(list, &element) != -1) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

/**
 * Test function for ArrayList_clear().
 * 
 * @return true if the test passes, false otherwise.
*/
bool test_ArrayList_clear() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element = 1;

  if (!ArrayList_add(list, &element)) {
    return false;
  }

  if (ArrayList_size(list) != 1) {
    return false;
  }

  if (!ArrayList_clear(list)) {
    return false;
  }

  if (ArrayList_size(list) != 0) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_clear_with_multiple() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  int element1 = 1;
  int element2 = 2;
  int element3 = 3;

  if (!ArrayList_add(list, &element1)) {
    return false;
  }

  if (!ArrayList_add(list, &element2)) {
    return false;
  }

  if (!ArrayList_add(list, &element3)) {
    return false;
  }

  if (ArrayList_size(list) != 3) {
    return false;
  }

  if (!ArrayList_clear(list)) {
    return false;
  }

  if (ArrayList_size(list) != 0) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

bool test_ArrayList_clear_from_null() {
  ArrayList* list = NULL;

  if (ArrayList_clear(list)) {
    return false;
  }

  return true;
}

bool test_ArrayList_clear_from_empty() {
  ArrayList* list = new_ArrayList();

  if (list == NULL) {
    return false;
  }

  if (!ArrayList_clear(list)) {
    return false;
  }

  ArrayList_free(list);
  return true;
}

/**
 * Main function used to run the tests.
*/
int main() {
  printf("Running unit tests for ArrayList.h...\n");

  printf("\ttesting new_ArrayList()...............................%s\n", test_new_ArrayList() ? "PASS" : "FAIL");
  
  printf("\ttesting ArrayList_add()...............................%s\n", test_ArrayList_add() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_add() with multiple elements........%s\n", test_ArrayList_add_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_add() to NULL.......................%s\n", test_ArrayList_add_to_null() ? "PASS" : "FAIL");

  printf("\ttesting ArrayList_remove()............................%s\n", test_ArrayList_remove() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_remove() with multiple elements.....%s\n", test_ArrayList_remove_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_remove() from NULL..................%s\n", test_ArrayList_remove_from_null() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_remove() using index too large......%s\n", test_ArrayList_remove_index_too_large() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_remove() using index too small......%s\n", test_ArrayList_remove_index_too_small() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_remove() from empty.................%s\n", test_ArrayList_remove_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting ArrayList_get()...............................%s\n", test_ArrayList_get() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_get() with multiple elements........%s\n", test_ArrayList_get_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_get() from NULL.....................%s\n", test_ArrayList_get_from_null() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_get() using index too large.........%s\n", test_ArrayList_get_index_too_large() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_get() using index too small.........%s\n", test_ArrayList_get_index_too_small() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_get() from empty....................%s\n", test_ArrayList_get_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting ArrayList_size()..............................%s\n", test_ArrayList_size() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_size() with multiple elements.......%s\n", test_ArrayList_size_with_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_size() from NULL....................%s\n", test_ArrayList_size_from_null() ? "PASS" : "FAIL");

  printf("\ttesting ArrayList_isEmpty()...........................%s\n", test_ArrayList_isEmpty() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_isEmpty() with multiple elements....%s\n", test_ArrayList_isEmpty_with_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_isEmpty() from NULL.................%s\n", test_ArrayList_isEmpty_from_null() ? "PASS" : "FAIL");

  printf("\ttesting ArrayList_contains()..........................%s\n", test_ArrayList_contains() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_contains() with multiple elements...%s\n", test_ArrayList_contains_with_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_contains() from NULL................%s\n", test_ArrayList_contains_from_null() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_contains() from empty...............%s\n", test_ArrayList_contains_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting ArrayList_indexOf()...........................%s\n", test_ArrayList_indexOf() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_indexOf() with multiple elements....%s\n", test_ArrayList_indexOf_with_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_indexOf() from NULL.................%s\n", test_ArrayList_indexOf_from_null() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_indexOf() from empty................%s\n", test_ArrayList_indexOf_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting ArrayList_clear().............................%s\n", test_ArrayList_clear() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_clear() with multiple elements......%s\n", test_ArrayList_clear_with_multiple() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_clear() from NULL...................%s\n", test_ArrayList_clear_from_null() ? "PASS" : "FAIL");
  printf("\ttesting ArrayList_clear() from empty..................%s\n", test_ArrayList_clear_from_empty() ? "PASS" : "FAIL");

  printf("Unit tests complete.\n");
}