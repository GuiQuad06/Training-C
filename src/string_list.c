#include "string_list.h"

#include <string.h>

void string_list_init(string_list_t *list)
{
    string_list_t empty = STRING_LIST_INIT;

    memcpy(list, &empty, sizeof(*list));
}

void string_list_init_nodup(string_list_t *list)
{
    string_list_t empty = STRING_LIST_INIT_NODUP;

    memcpy(list, &empty, sizeof(*list));
}
