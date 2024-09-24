#include "linked-list.h"
#include <stdlib.h>
#include <stdio.h>

#include "unity.h"


void test_infallible() {
    struct List l = (struct List){0, NULL};
    printf("data: %d", l.data);
    TEST_PASS();
}
