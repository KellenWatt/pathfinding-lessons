#include "stack.h"


struct StackNode {
    int data;
    struct StackNode* prev;
};

struct StackNode* node_new(int data) {
    struct StackNode* node = malloc(sizeof(*node));
    node->data = data;
    node->prev = NULL;
    return node;
}

void node_free(struct StackNode* self) {
    free(self);
}

struct Stack* stack_new() {
   struct Stack* s = malloc(sizeof(*s));
   s->top = NULL;
   s->size = 0;
   return s;
}

void stack_free(struct Stack* self) {
    while(self->top != NULL) {
        struct StackNode* tmp = self->top;
        self->top = self->top->prev;
        node_free(tmp);
    }
    /* free(self); */
}

void stack_push(struct Stack* self, int value) {
    struct StackNode* tmp = node_new(value);
    tmp->prev = self->top;
    self->top = tmp;
    self->size += 1;
}

void stack_pop(struct Stack* self) {
    if(self->size == 0) {
        return;
    }
    struct StackNode* tmp = self->top;
    self->top = self->top->prev;
    node_free(tmp); 
    self->size -= 1;
}

// Assume stack is non-empty
int stack_top(const struct Stack* self) {
    return self->top->data;
}

size_t stack_len(const struct Stack* self) {
    return self->size;
}


