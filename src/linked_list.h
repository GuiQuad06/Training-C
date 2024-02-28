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
 * @param head : points the head's address of the list
 * @param[in] n : the integer data to add at the head list
 * @return int : status
 */
int add_node(linked_list_t **head, int n);

/**
 * @brief Clear all nodes of a dynamic linked list
 * by performing free() on the elements
 * @param[in] head : a pointer to the head's address of linked list
 * @return none.
 */
void clear_list(linked_list_t **head);

/**
 * @brief Display all node's data of a dynamic linked list
 * @param[in] head : a pointer to the head of linked list
 * @return none.
 */
void print_list(linked_list_t *head);

/**
 * @brief Remove the wanted node from the list
 * @param head : points the head's address list
 * @param[in] n : data to be removed
 * @return int : status (0 if succeed or n
 * if the parameter n was not found)
 */
int remove_node(linked_list_t **head, int n);

linked_list_t *insert_node(int n, int pos);

#endif // LINKED_LIST_H_
