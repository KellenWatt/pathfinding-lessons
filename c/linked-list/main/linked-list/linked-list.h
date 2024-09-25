#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

// TODO: Provide an actual structure for List
struct List;

struct List* list_new(int value);
void list_free(struct List*);
size_t list_len(const struct List*);
void list_set(struct List*, size_t i, int value);
int list_get(const struct List*, size_t i);
struct List* list_push_front(struct List*, int value);
struct List* list_push_back(struct List*, int value);
struct List* list_insert(struct List*, size_t i, int value);
struct List* list_remove(struct List*, size_t i);

#endif
