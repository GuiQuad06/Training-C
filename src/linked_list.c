#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

linked_list_t *head = NULL;

linked_list_t *add_node(int n)
{
    linked_list_t *node = NULL;

    node = malloc(sizeof(linked_list_t));

    // Return if the previous malloc failed
    if (node == NULL)
        return NULL;
    
    // List is empty
    if (head == NULL)
    {
        node->data = n;

        // In our case linked list is filled by the head
        // which means very first element will be the tail
        // So its next element will points to NULL
        node->next = NULL;
        head = node;
    }
    else // List already has nodes
    {
        node->data = n;

        // Link the previous HEAD list
        // and created node becomes the HEAD
        // Add to the head is O(1)
        node->next = head;
        head = node;
    }
    return node;
}

void clear_list(linked_list_t *list)
{
    linked_list_t *current = list;

    while(current != NULL)
    {
        // Make head list points to next element 
        if (current == list)
        {
            list = current->next;
        }
        else // current is no more pointed by list
        {
            free(current);
            // current will point to the next element
            // so at the tail, it will be current = NULL
            current = list;
        }
    }
    return;
}

void print_list(linked_list_t *list)
{
    while(list != NULL)
    {
        printf("data:%d\n", list->data);
        list = list->next;
    }
    return;
}

linked_list_t *remove_node(int n)
{

}

linked_list_t *insert_node(int n, int pos)
{

}
