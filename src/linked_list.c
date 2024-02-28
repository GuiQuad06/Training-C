#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int add_node(linked_list_t **head, int n)
{
    linked_list_t *node = NULL;

    node = malloc(sizeof(linked_list_t));

    // Return if the previous malloc failed
    if (node == NULL)
        return EXIT_FAILURE;
    
    // List is empty
    if (*head == NULL)
    {
        node->data = n;

        // In our case linked list is filled by the head
        // which means very first element will be the tail
        // So its next element will points to NULL
        node->next = NULL;
        *head = node;
    }
    else // List already has nodes
    {
        node->data = n;

        // Link the previous HEAD list
        // and created node becomes the HEAD
        // Add to the head is O(1)
        node->next = *head;
        *head = node;
    }
    return EXIT_SUCCESS;
}

void clear_list(linked_list_t **head)
{
    linked_list_t *current = *head;

    while(current != NULL)
    {
        // Make head list points to next element 
        if (current == *head)
        {
            *head = current->next;
        }
        else // current is no more pointed by list
        {
            free(current);
            // current will point to the next element
            // so at the tail, it will be current = NULL
            current = *head;
        }
    }
    return;
}

void print_list(linked_list_t *head)
{
    while(head != NULL)
    {
        printf("data:%d\n", head->data);
        head = head->next;
    }
    return;
}

int remove_node(linked_list_t **head, int n)
{
    linked_list_t *current = *head;
    linked_list_t *prev = *head;

    while(current != NULL)
    {
        // If node was found remove from the list
        if (current->data == n)
        {
            if (current == *head)
            {
                *head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            current = NULL;

            return EXIT_SUCCESS;
        }
        prev = current;
        current = current->next;
    }
    return n;
}

int insert_node(linked_list_t **head, int n, int pos)
{
    linked_list_t *new = NULL;
    linked_list_t *current = *head;
    linked_list_t *prev = *head;
    unsigned int index = 0;

    new = malloc(sizeof(linked_list_t));

    // Check the dynamic memory allocation
    if (new == NULL)
        return EXIT_FAILURE;

    // Iterate over the linked list
    while(current != NULL)
    {
        // When I found the position new node will pouints to the current element
        // and tghe previous element will points to the new inserted one
        if(index == pos)
        {
            new->data = n;
            new->next = current;
            prev->next = new;

            return EXIT_SUCCESS;
        }

        prev = current;
        current = current->next;
        index++;
    }
    return pos;
}
