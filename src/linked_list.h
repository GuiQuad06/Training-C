#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stddef.h>

/*
 * Public structure which contains a linked list
 */
typedef struct {
    int data;
    void* next;
} linked_list_t;

// Exported function prototypes
linked_list_t *add(int n);
linked_list_t *remove(int n);
linked_list_t *insert(int n, int pos);

#endif // LINKED_LIST_H_
