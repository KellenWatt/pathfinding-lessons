#include "queue.h"

struct QueueNode* node_new(int value) {
    struct QueueNode* n = malloc(sizeof(*n));
    n->data = value;
    n->next = NULL;
    return n;
}

void node_free(struct QueueNode* self) {
    free(self);
}


struct Queue* queue_new() {
    struct Queue* q = malloc(sizeof(*q));
    q->head = NULL;
    q->size = 0;
    return q;
}

void queue_free(struct Queue* self) {
    struct QueueNode* head = self->head;
    while(head != NULL) {
        struct QueueNode* tmp = head;
        head = head->next;
        node_free(tmp);
    }
    free(self);
}

void queue_push(struct Queue* self, int value) {
    struct QueueNode* new_node = node_new(value);
    if(self->head == NULL) {
        self->head = new_node;
        return;
    }

    struct QueueNode* end = self->head;
    while(end->next != NULL) {
        end = end->next;
    }

    end->next = new_node;
}

void queue_pop(struct Queue* self) {
    if(self->head == NULL) return;
    struct QueueNode* tmp = self->head;
    self->head = self->head->next;

    node_free(tmp);
}

int queue_front(const struct Queue* self) {
    return self->head->data;
}

size_t queue_len(const struct Queue* self) {
    size_t i = 0;
    struct QueueNode* tmp = self->head;
    while(tmp != NULL) {
        i += 1;
        tmp = tmp->next;
    }
    return i;
}


