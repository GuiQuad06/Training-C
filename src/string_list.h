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

/*
 * Function pointer to allow implement a specific callback, for the clear
 */
typedef void (*cb_clear_function_t)(const char *str);

// Exported function prototypes
char *my_strdup(const char *str);
void *my_memdup(const void *data, size_t len);
void string_list_init(string_list_t *list);
void string_list_init_nodup(string_list_t *list);
void string_list_clear_fct(string_list_t *list, cb_clear_function_t clearfunc);
void string_list_clear(string_list_t *list);
item_t *string_list_append(string_list_t *list, const char * str);
item_t *string_list_append_nodup(string_list_t *list, const char * str);
int string_list_split(string_list_t *list, const char *str, int delim, int maxsplit);

#endif // STRING_LIST_H_
