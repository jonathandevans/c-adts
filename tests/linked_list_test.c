/**
 * @file linked_list_test.c
 * @brief Test file for linked_list.c
 * @author Jonathan E
 * @date 28-04-2023
 * 
 * This file contains the test functions for linked_list.c.
 * By running this file, you can test the functions of linked_list.c with
 * the test cases outputted to the console.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../src/linked_list/linked_list.h"

/**
 * Test function for new_LinkedList().
 * 
 * @return true if test passed, false otherwise.
*/
bool test_new_LinkedList() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  if (list->size != 0) {
    return false;
  }

  if (list->head != NULL) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

/**
 * Test function for LinkedList_add().
 * 
 * @return true if test passed, false otherwise.
*/
bool test_LinkedList_add() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element = 5;

  if (!LinkedList_add(list, &element)) {
    return false;
  }

  if (list->size != 1) {
    return false;
  }

  if (list->head == NULL) {
    return false;
  }

  if (*(int*)list->head->data != element) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_add_multiple() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element1 = 5;
  int element2 = 10;
  int element3 = 15;

  if (!LinkedList_add(list, &element1)) {
    return false;
  }

  if (!LinkedList_add(list, &element2)) {
    return false;
  }

  if (!LinkedList_add(list, &element3)) {
    return false;
  }

  if (list->size != 3) {
    return false;
  }

  if (list->head == NULL) {
    return false;
  }

  if (*(int*)list->head->data != element1) {
    return false;
  }

  if (list->head->next == NULL) {
    return false;
  }

  if (*(int*)list->head->next->data != element2) {
    return false;
  }

  if (list->head->next->next == NULL) {
    return false;
  }

  if (*(int*)list->head->next->next->data != element3) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_add_to_null() {
  LinkedList* list = NULL;

  int element = 5;

  if (LinkedList_add(list, &element)) {
    return false;
  }

  return true;
}

/**
 * Test function for LinkedList_remove().
 * 
 * @return true if test passed, false otherwise.
*/
bool test_LinkedList_remove() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element = 5;
  LinkedList_add(list, &element);

  if (!LinkedList_remove(list, 0)) {
    return false;
  }

  if (list->size != 0) {
    return false;
  }

  if (list->head != NULL) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_remove_multiple() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element1 = 5;
  int element2 = 10;
  int element3 = 15;

  LinkedList_add(list, &element1);
  LinkedList_add(list, &element2);
  LinkedList_add(list, &element3);

  if (!LinkedList_remove(list, 1)) {
    return false;
  }

  if (list->size != 2) {
    return false;
  }

  if (list->head == NULL) {
    return false;
  }

  if (*(int*)list->head->data != element1) {
    return false;
  }

  if (list->head->next == NULL) {
    return false;
  }

  if (*(int*)list->head->next->data != element3) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_remove_from_null() {
  LinkedList* list = NULL;

  if (LinkedList_remove(list, 0)) {
    return false;
  }

  return true;
}

bool test_LinkedList_remove_index_too_large() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element = 5;
  LinkedList_add(list, &element);

  if (LinkedList_remove(list, 1)) {
    return false;
  }

  if (list->size != 1) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_remove_index_too_small() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element = 5;
  LinkedList_add(list, &element);

  if (LinkedList_remove(list, -1)) {
    return false;
  }

  if (list->size != 1) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_remove_from_empty() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  if (LinkedList_remove(list, 0)) {
    return false;
  }

  if (list->size != 0) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

/**
 * Test function for LinkedList_get().
 * 
 * @return true if test passed, false otherwise.
*/
bool test_LinkedList_get() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element = 5;
  LinkedList_add(list, &element);

  if (*(int*)LinkedList_get(list, 0) != element) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_get_multiple() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element1 = 5;
  int element2 = 10;
  int element3 = 15;

  LinkedList_add(list, &element1);
  LinkedList_add(list, &element2);
  LinkedList_add(list, &element3);

  if (*(int*)LinkedList_get(list, 0) != element1) {
    return false;
  }

  if (*(int*)LinkedList_get(list, 1) != element2) {
    return false;
  }

  if (*(int*)LinkedList_get(list, 2) != element3) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_get_from_null() {
  LinkedList* list = NULL;

  if (LinkedList_get(list, 0) != NULL) {
    return false;
  }

  return true;
}

bool test_LinkedList_get_index_too_large() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element = 5;
  LinkedList_add(list, &element);

  if (LinkedList_get(list, 1) != NULL) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_get_index_too_small() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element = 5;
  LinkedList_add(list, &element);

  if (LinkedList_get(list, -1) != NULL) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_get_from_empty() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  if (LinkedList_get(list, 0) != NULL) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

/**
 * Test function for LinkedList_size().
 * 
 * @return true if test passed, false otherwise.
*/
bool test_LinkedList_size() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element = 5;
  LinkedList_add(list, &element);

  if (LinkedList_size(list) != 1) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_size_multiple() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element1 = 5;
  int element2 = 10;
  int element3 = 15;

  LinkedList_add(list, &element1);
  LinkedList_add(list, &element2);
  LinkedList_add(list, &element3);

  if (LinkedList_size(list) != 3) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_size_from_null() {
  LinkedList* list = NULL;

  if (LinkedList_size(list) != -1) {
    return false;
  }

  return true;
}

bool test_LinkedList_size_from_empty() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  if (LinkedList_size(list) != 0) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

/**
 * Test function for LinkedList_isEmpty().
 * 
 * @return true if test passed, false otherwise.
*/
bool test_LinkedList_isEmpty() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  if (!LinkedList_isEmpty(list)) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_isEmpty_multiple() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element = 5;
  int element2 = 10;

  LinkedList_add(list, &element);
  LinkedList_add(list, &element2);

  if (LinkedList_isEmpty(list)) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_isEmpty_from_null() {
  LinkedList* list = NULL;

  if (!LinkedList_isEmpty(list)) {
    return false;
  }

  return true;
}

/**
 * Test function for LinkedList_contains().
 * 
 * @return true if test passed, false otherwise.
*/
bool test_LinkedList_contains() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element = 5;
  LinkedList_add(list, &element);

  if (!LinkedList_contains(list, &element)) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_contains_multiple() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element1 = 5;
  int element2 = 10;
  int element3 = 15;

  LinkedList_add(list, &element1);
  LinkedList_add(list, &element2);
  LinkedList_add(list, &element3);

  if (!LinkedList_contains(list, &element1)) {
    return false;
  }

  if (!LinkedList_contains(list, &element2)) {
    return false;
  }

  if (!LinkedList_contains(list, &element3)) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_contains_from_null() {
  LinkedList* list = NULL;

  if (LinkedList_contains(list, NULL)) {
    return false;
  }

  return true;
}

bool test_LinkedList_contains_from_empty() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  if (LinkedList_contains(list, NULL)) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

/**
 * Test function for LinkedList_indexOf().
 * 
 * @return true if test passed, false otherwise.
*/
bool test_LinkedList_indexOf() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element = 5;
  LinkedList_add(list, &element);

  if (LinkedList_indexOf(list, &element) != 0) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_indexOf_multiple() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element1 = 5;
  int element2 = 10;
  int element3 = 15;

  LinkedList_add(list, &element1);
  LinkedList_add(list, &element2);
  LinkedList_add(list, &element3);

  if (LinkedList_indexOf(list, &element1) != 0) {
    return false;
  }

  if (LinkedList_indexOf(list, &element2) != 1) {
    return false;
  }

  if (LinkedList_indexOf(list, &element3) != 2) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_indexOf_from_null() {
  LinkedList* list = NULL;

  if (LinkedList_indexOf(list, NULL) != -1) {
    return false;
  }

  return true;
}

bool test_LinkedList_indexOf_from_empty() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  if (LinkedList_indexOf(list, NULL) != -1) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

/**
 * Test function for LinkedList_clear().
 * 
 * @return true if test passed, false otherwise.
*/
bool test_LinkedList_clear() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element = 5;
  LinkedList_add(list, &element);

  LinkedList_clear(list);

  if (!LinkedList_isEmpty(list)) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_clear_multiple() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  int element1 = 5;
  int element2 = 10;
  int element3 = 15;

  LinkedList_add(list, &element1);
  LinkedList_add(list, &element2);
  LinkedList_add(list, &element3);

  LinkedList_clear(list);

  if (!LinkedList_isEmpty(list)) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

bool test_LinkedList_clear_from_null() {
  LinkedList* list = NULL;

  if (LinkedList_clear(list)) {
    return false;
  }

  return true;
}

bool test_LinkedList_clear_from_empty() {
  LinkedList* list = new_LinkedList();

  if (list == NULL) {
    return false;
  }

  LinkedList_clear(list);

  if (!LinkedList_isEmpty(list)) {
    return false;
  }

  LinkedList_free(list);
  return true;
}

/**
 * Main function used to run the tests.
*/
int main() {
  printf("Running unit tests for LinkedList...\n");

  printf("\ttesting new_LinkedList()...............................%s\n", test_new_LinkedList() ? "PASS" : "FAIL");

  printf("\ttesting LinkedList_add()...............................%s\n", test_LinkedList_add() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_add() with multiple elements........%s\n", test_LinkedList_add_multiple() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_add() to NULL.......................%s\n", test_LinkedList_add_to_null() ? "PASS" : "FAIL");

  printf("\ttesting LinkedList_remove()............................%s\n", test_LinkedList_remove() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_remove() with multiple elements.....%s\n", test_LinkedList_remove_multiple() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_remove() from NULL..................%s\n", test_LinkedList_remove_from_null() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_remove() using index too large......%s\n", test_LinkedList_remove_index_too_large() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_remove() using index too small......%s\n", test_LinkedList_remove_index_too_small() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_remove() from empty.................%s\n", test_LinkedList_remove_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting LinkedList_get()...............................%s\n", test_LinkedList_get() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_get() with multiple elements........%s\n", test_LinkedList_get_multiple() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_get() from NULL.....................%s\n", test_LinkedList_get_from_null() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_get() using index too large.........%s\n", test_LinkedList_get_index_too_large() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_get() using index too small.........%s\n", test_LinkedList_get_index_too_small() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_get() from empty....................%s\n", test_LinkedList_get_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting LinkedList_size()..............................%s\n", test_LinkedList_size() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_size() with multiple elements.......%s\n", test_LinkedList_size_multiple() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_size() from NULL....................%s\n", test_LinkedList_size_from_null() ? "PASS" : "FAIL");

  printf("\ttesting LinkedList_isEmpty()...........................%s\n", test_LinkedList_isEmpty() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_isEmpty() with multiple elements....%s\n", test_LinkedList_isEmpty_multiple() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_isEmpty() from NULL.................%s\n", test_LinkedList_isEmpty_from_null() ? "PASS" : "FAIL");

  printf("\ttesting LinkedList_contains()..........................%s\n", test_LinkedList_contains() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_contains() with multiple elements...%s\n", test_LinkedList_contains_multiple() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_contains() from NULL................%s\n", test_LinkedList_contains_from_null() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_contains() from empty...............%s\n", test_LinkedList_contains_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting LinkedList_indexOf()...........................%s\n", test_LinkedList_indexOf() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_indexOf() with multiple elements....%s\n", test_LinkedList_indexOf_multiple() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_indexOf() from NULL.................%s\n", test_LinkedList_indexOf_from_null() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_indexOf() from empty................%s\n", test_LinkedList_indexOf_from_empty() ? "PASS" : "FAIL");

  printf("\ttesting LinkedList_clear().............................%s\n", test_LinkedList_clear() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_clear() with multiple elements......%s\n", test_LinkedList_clear_multiple() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_clear() from NULL...................%s\n", test_LinkedList_clear_from_null() ? "PASS" : "FAIL");
  printf("\ttesting LinkedList_clear() from empty..................%s\n", test_LinkedList_clear_from_empty() ? "PASS" : "FAIL");

  printf("Unit tests complete.\n");
}
