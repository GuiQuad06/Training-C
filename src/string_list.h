#ifndef STRING_LIST_H_
#define STRING_LIST_H_

#include <stddef.h>

// Create a new type called item which is actually a string
typedef char * item_t;

/*
 * Public structure which contains a string list
 */
typedef struct {
    item_t * item;
    size_t nb;
    size_t alloc;
    unsigned int dup_strings:1;
} string_list_t;

// INIT Constants
#define STRING_LIST_INIT_NODUP    { 0 }
#define STRING_LIST_INIT          { .dup_strings = 1 }

// Exported function prototypes
void string_list_init(string_list_t *list);
void string_list_init_nodup(string_list_t *list);

#endif // STRING_LIST_H_