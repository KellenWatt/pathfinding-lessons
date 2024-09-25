#include "linked-list.h"
#include <stdlib.h>
#include <stdio.h>

#include "unity.h"

// struct List {
//   // up to you
// }
//
// x List* list_new(int value)
// x void list_free(List*)
// x usize list_len(List*)
// x List* list_push_front(List*, int value)
// x List* list_push_back(List*, int value)
// x List* list_insert(List*, size_t i, int value)
// x List* list_remove(List*, size_t i)
// x void list_set(List*, size_t i, int value)
// x int list_get(List*, i)

struct List* list_from_array(int data[], size_t len) {
    if(len == 0) {
        return NULL;
    }
    struct List* l = NULL;
    for(int i=len-1; i>=0; i--) {
        l = list_push_front(l, data[i]);
    }

    return l;
}


void test_empty_list_is_valid() {
    struct List* l = NULL;
    TEST_ASSERT_EQUAL_UINT64(0, list_len(l));
}

void test_creates_new_list() {
    struct List* l = list_new(0);
    TEST_ASSERT_NOT_NULL(l);
    TEST_ASSERT_EQUAL_UINT64(1, list_len(l));
    list_free(l);
}

void test_arbitrary_readable_indexing() {
    int data[] = {1,2,3,4,5,6};
    struct List* l = list_from_array(data, 6);

    TEST_ASSERT_EQUAL_INT(5, list_get(l, 4));
    TEST_ASSERT_EQUAL_INT(1, list_get(l, 0));

    list_free(l);
}

void test_arbitrary_writable_indexing() {
    int data[] = {1,2,3,4,5,6};
    struct List* l = list_from_array(data, 6);

    int new_value = 42;
    size_t index = 4;

    list_set(l, index, new_value);
    TEST_ASSERT_EQUAL_INT(new_value, list_get(l, index));

    // make sure to leave the rest unaffected
    for(int i = 0; i < 6; i++) {
        if(i == index) continue;
        TEST_ASSERT_EQUAL_INT(data[i], list_get(l, i));
    }

    list_free(l);
}

void test_push_front_prepends() {
    struct List* l = list_new(0);
    struct List* l2 = list_push_front(l, 1);
    TEST_ASSERT_NOT_NULL(l2);
    TEST_ASSERT_EQUAL_UINT64(2, list_len(l2));
    TEST_ASSERT_EQUAL_INT(1, list_get(l2, 0));

    list_free(l2);
}

void test_push_back_appends() {
    struct List* l = list_new(0);
    l = list_push_back(l, 1);
    TEST_ASSERT_NOT_NULL(l);
    TEST_ASSERT_EQUAL_UINT64(2, list_len(l));
    TEST_ASSERT_EQUAL_INT(1, list_get(l, 1));

    list_free(l);
}

void test_arbitrary_insertion() {
    int data[] = {1,2,3,4,5,6};
    struct List* l = list_from_array(data, 6);

    size_t index = 3;
    int value = 10;

    l = list_insert(l, index, value);
    TEST_ASSERT_EQUAL_UINT64(7, list_len(l));
    TEST_ASSERT_EQUAL_INT(value, list_get(l, index));
    for(int i = 0; i < 6; i++) {
        size_t idx = i;
        if(i >= index) {
            idx += 1;
        }
        TEST_ASSERT_EQUAL_INT(data[i], list_get(l, idx));
    }

    list_free(l);
}

void test_insert_works_at_head() {
    struct List* l = list_new(0);

    l = list_insert(l, 0, 10);
    TEST_ASSERT_EQUAL_UINT64(2, list_len(l));
    TEST_ASSERT_EQUAL_INT(10, list_get(l, 0));
}

void test_arbitrary_removal() {
    int data[] = {1,2,3,4,5,6};
    struct List* l = list_from_array(data, 6);

    size_t index = 5;

    l = list_remove(l, index);
    TEST_ASSERT_EQUAL_UINT64(5, list_len(l));
    for(int i = 0; i < 5; i++) {
        size_t idx = i;
        if(i >= index) {
            idx -= 1;
        }
        TEST_ASSERT_EQUAL_INT(data[idx], list_get(l, i));
    }

    list_free(l);
}

void test_remove_on_single_item_returns_empty() {
    struct List* l = list_new(0);
    TEST_ASSERT_EQUAL_UINT64(1, list_len(l));
    l = list_remove(l, 0);
    TEST_ASSERT_EQUAL_UINT64(0, list_len(l));
}


