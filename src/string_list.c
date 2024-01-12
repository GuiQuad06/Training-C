#include "string_list.h"

#include <string.h>
#include <stdlib.h>
#include "utils.h"

char *my_strdup(const char *str)
{
    size_t len = strlen(str) + 1;
    char * res = malloc(len);

    if(res)
        memcpy(res, str, len);
    return res;
}

void *my_memdup(const void *data, size_t len)
{
    return memcpy(malloc(len), data, len);
}

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

item_t *string_list_append(string_list_t *list, const char * str)
{
    return string_list_append_nodup(list, \
            list->dup_strings ? my_strdup((char *)str) : (char *)str);
}

item_t *string_list_append_nodup(string_list_t *list, const char * str)
{
    item_t * retval;
    ALLOC_GROW(list->item, list->nb + 1, list->alloc);

    retval = &list->item[list->nb++];
    *retval = (char *)str;

    return retval;
}

int string_list_split(string_list_t *list, const char *str, int delim, int maxsplit)
{
    if (!list->dup_strings)
    {
        fprintf(stderr, "the dup_strings list member must be set to 1");
        return -1;
    }
    else
    {
        unsigned int cpt = 0;
        char * end;
        const char * p;
        p = str;

        while(*p != '\0')
        {
            cpt++;

            if (maxsplit >= 0 && cpt > maxsplit)
            {
                //Append the string
                string_list_append(list, p);
                return cpt;
            }
            else
            {
                end = strchr(p, delim);

                if(end)
                {
                    //Append the string we should not use the one with dup 
                    //Because we want to adapt the lenth according to the delimiter
                    string_list_append_nodup(list, my_memdup(p, end - p));
                    //Place the p pointer after the delimiter
                    p = end + 1;
                }
                else
                {
                    //Append the string
                    string_list_append(list, p);
                    return cpt;
                }
            }
        }
    }
}
