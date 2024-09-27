#include "stack.h"
#include "unity.h"

#include <stdlib.h>

void test_new_stack_is_empty() {
    struct Stack* s = stack_new();
    TEST_ASSERT_EQUAL_UINT64(0, stack_len(s));
    stack_free(s);
}

void test_push_adds_element() {
    struct Stack* s = stack_new();
    stack_push(s, 2);
    TEST_ASSERT_EQUAL_UINT64(1, stack_len(s));
    stack_free(s);
}

void test_can_push_multiple_elements() {
    struct Stack* s = stack_new();
    stack_push(s, 1);
    stack_push(s, 2);
    TEST_ASSERT_EQUAL_UINT64(2, stack_len(s));
    stack_free(s);
}

void test_push_adds_to_top() {
    struct Stack* s = stack_new();
    stack_push(s, 2);
    TEST_ASSERT_EQUAL_INT(2, stack_top(s));
    stack_push(s, 5);
    TEST_ASSERT_EQUAL_INT(5, stack_top(s));
    TEST_ASSERT_EQUAL_UINT64(2, stack_len(s));
    stack_free(s);
}

void test_pop_works_on_empty() {
    struct Stack* s = stack_new();
    TEST_ASSERT_EQUAL_UINT64(0, stack_len(s));
    stack_pop(s);
    TEST_ASSERT_EQUAL_UINT64(0, stack_len(s));
    stack_free(s);
}

void test_pop_removes_top_element() {
    struct Stack* s = stack_new();
    stack_push(s, 5);
    stack_push(s, 10);
    stack_push(s, 15);
    TEST_ASSERT_EQUAL_INT(15, stack_top(s));
    stack_pop(s);
    TEST_ASSERT_EQUAL_INT(10, stack_top(s));
    stack_pop(s);
    TEST_ASSERT_EQUAL_INT(5, stack_top(s));

    stack_free(s);
}
