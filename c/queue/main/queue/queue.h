#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

struct Queue;

struct Queue* queue_new();
void queue_free(struct Queue*);
void queue_push(struct Queue*, int);
void queue_pop(struct Queue*);
int queue_top(const struct Queue*);
size_t queue_len(const struct Queue*);

#endif
