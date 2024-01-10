#include "string_list.h"

#include <string.h>
#include <stdlib.h>

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

void string_list_clear_fct(string_list_t *list, cb_clear_function_t clearfunc)
{
    if(list->item)
    {
        int i;
        if (clearfunc)
        {
            for(i = 0; i < list->nb; i++)
                clearfunc(list->item[i]);
        }
        if (list->dup_strings)
        {
            for(i = 0; i < list->nb; i++)
                free(list->item[i]);
        }
        free(list->item);
    }
    
    list->item = NULL;
    list->nb = 0;
    list->alloc = 0;
}

void string_list_clear(string_list_t *list)
{
    if (list->item)
    {
        if (list->dup_strings)
        {
            for(int i = 0; i < list->nb ; i++)
                free(list->item[i]);
        }
        free(list->item);
    }

    list->item = NULL;
    list->nb = 0;
    list->alloc = 0;
}
