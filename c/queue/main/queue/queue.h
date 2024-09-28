#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* head;
    size_t size;
};

struct Queue* queue_new();
void queue_free(struct Queue*);
void queue_push(struct Queue*, int);
void queue_pop(struct Queue*);
int queue_front(const struct Queue*);
size_t queue_len(const struct Queue*);

#endif
