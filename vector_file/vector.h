#ifndef VECTOR_H
#define VECTOR_H

typedef struct item_ {
    int key;
    char *value;
    size_t length;
    size_t offset;
} item;

typedef struct vector_ {
    item** items;
    int cap;
    int len;
} vector;

void vector_init(vector*);
int vector_count(vector*);
void vector_add(vector*, item*);
void vector_set(vector*, int, item*);
item* vector_get(vector*, int);
void vector_delete(vector*, int);
void vector_free(vector*);

#endif