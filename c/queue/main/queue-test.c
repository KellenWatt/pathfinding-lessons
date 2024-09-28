#include "queue.h"
#include "unity.h"

#include <stdlib.h>

void test_new_queue_is_empty() {
    struct Queue* q = queue_new();
    TEST_ASSERT_EQUAL_UINT64(0, queue_len(q));
    queue_free(q);
}

void test_push_adds_element() {
    struct Queue* q = queue_new();
    queue_push(q, 10);
    TEST_ASSERT_EQUAL_UINT64(1, queue_len(q));
    queue_free(q);
}

void test_can_push_multiple_elements() {
    struct Queue* q = queue_new();
    queue_push(q, 12);
    queue_push(q, 3);
    TEST_ASSERT_EQUAL_UINT64(2, queue_len(q));
    queue_free(q);
}

void test_push_adds_to_back() {
    struct Queue* q = queue_new();
    queue_push(q, 1);
    TEST_ASSERT_EQUAL_INT(1, queue_front(q));
    queue_push(q, 2);
    TEST_ASSERT_EQUAL_INT(1, queue_front(q));
    TEST_ASSERT_EQUAL_UINT64(2, queue_len(q));
    queue_free(q);
}

void test_pop_works_on_empty() {
    struct Queue* q = queue_new();
    TEST_ASSERT_EQUAL_UINT64(0, queue_len(q));
    queue_pop(q);
    TEST_ASSERT_EQUAL_UINT64(0, queue_len(q));
    queue_free(q);
}

void test_pop_removes_front_element() {
    struct Queue* q = queue_new();
    queue_push(q, 5);
    queue_push(q, 10);
    queue_push(q, 15);
    TEST_ASSERT_EQUAL_INT(5, queue_front(q));
    queue_pop(q);
    TEST_ASSERT_EQUAL_INT(10, queue_front(q));
    queue_pop(q);
    TEST_ASSERT_EQUAL_INT(15, queue_front(q));
    
    queue_free(q);
}

