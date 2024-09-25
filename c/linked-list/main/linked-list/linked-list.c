#include "linked-list.h"
#include <stdlib.h> 
#include <stdio.h>

struct List* list_new(int value) {
    struct List* l = malloc(sizeof(*l));
    l->data = value;
    l->next = NULL;

    return l;
}

void list_free(struct List* self) {
    if(self != NULL) return;
    struct List* tmp = self->next;
    free(self);
    list_free(tmp);
}

size_t list_len(const struct List* self) {
    if(self == NULL) {
        return 0;
    }
    return 1 + list_len(self->next);
}

struct List* list_push_front(struct List* self, int value) {
    struct List* head = list_new(value);
    head->next = self;
    return head;
}

struct List* list_push_back(struct List* self, int value) {
    if(self == NULL) {
        return list_new(value);
    }
    struct List* tmp = self;
    while(tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = list_new(value);
    return self;
}

// We're assuming there's no out-of-bounds indexing (implying self is not NULL)
int list_get(const struct List* self, size_t i) {
    if(i == 0) {
        return self->data;
    }
    return list_get(self->next, i-1);
}

// Assume i is in-bounds.
// Do not assume self is not NULL
void list_set(struct List* self, size_t i, int value) {
    if(self == NULL) return;

    if(i == 0) {
        self->data = value;
    }
    list_set(self->next, i-1, value);
}

// Assume i is in-bounds [0, len(self))
struct List* list_insert(struct List* self, size_t i, int value) {
    if(i == 0) {
        struct List* l = list_new(value);
        l->next = self;
        return l;
    }
    struct List* tmp = self;
    while(i > 1) {
        tmp = tmp->next;
        i -= 1;
    }

    struct List* l = list_new(value);
    l->next = tmp->next;
    tmp->next = l;

    return self;
}

// Assume i is in-bounds (exception, empty lists can "remove" 0)
// Assume nothing about length.
struct List* list_remove(struct List* self, size_t i) {
    if(self == NULL) {
        return NULL;
    } else if(self->next == NULL) {
        list_free(self);
        return NULL;
    }

    struct List* l = self;
    while(i > 1) {
        l = l->next;
        i -= 1;
    }

    struct List* tmp = l->next;
    l->next = l->next->next;
    list_free(tmp);

    return self;
}
