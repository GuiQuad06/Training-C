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

/**
 * @brief Add a node in a dynamic linked list
 * The node will be added to the head
 * @param[in] n : the integer data to add at the head list
 * @return linked_list_t* a pointer to the outcome linked list
 */
linked_list_t *add_node(int n);

/**
 * @brief Clear all nodes of a dynamic linked list
 * by performing free() on the elements
 * @param[in] list : a pointer to the head of linked list
 * @return none.
 */
void clear_list(linked_list_t *list);

/**
 * @brief Display all node's data of a dynamic linked list
 * @param[in] list : a pointer to the head of linked list
 * @return none.
 */
void print_list(linked_list_t *list);


linked_list_t *remove_node(int n);
linked_list_t *insert_node(int n, int pos);

#endif // LINKED_LIST_H_
