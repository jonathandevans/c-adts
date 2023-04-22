/**
 * @file array_list_test.c
 * @brief Test file for array_list.c
 * @author Jonathan E
 * @date 09-04-2023
 * 
 * This file contains the test functions for array_list.c.
 * By running this file, you can test the functions in array_list.c with
 * the test conditions outputted to the console.
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

  if (list->collection != NULL) {
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

  if (list->size != 0) {
    return false;
  }

  return true;
}