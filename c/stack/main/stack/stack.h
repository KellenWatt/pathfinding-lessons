#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* prev;
};

struct Stack {
    struct StackNode* top;
    size_t size;
};

struct Stack* stack_new();
void stack_free(struct Stack*);
void stack_push(struct Stack*, int);
void stack_pop(struct Stack*);
int stack_top(const struct Stack*);
size_t stack_len(const struct Stack*);

#endif
