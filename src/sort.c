#include "sort.h"
#include "basics.h"

#include <stdlib.h>
#include <string.h>

static inline int min(int a, int b)
{
    return (a < b ? a : b);
}

static void bottom_up(int *dst, int *src, int start, int mid, int end)
{
    int j = start;
    int k = mid;

    for (int i = start; i < end; i++)
    {
        if (j < mid && (k >= end || src[j] <= src[k]))
        {
            dst[i] = src[j];
            j++;
        }
        else
        {
            dst[i] = src[k];
            k++;
        }
    }
}

/* Merge sort bottom up */
int merge_sort(int *data, size_t size)
{
    int data_res[size];
    int *data_ptr, *data_res_ptr;

    if (data == NULL || size <= 1)
        return EXIT_FAILURE;

    data_ptr = data;
    data_res_ptr = data_res;

    (void) memset(data_res, 0, size * sizeof(*data));
    
    // Width of the sort scope
    for (int width = 1; width < size; width *= 2)
    {
        // Iterate over each scope
        for (int i = 0; i < size; i += 2*width)
        {
            // Sort the scope
            bottom_up(data_res_ptr, data_ptr, i, min(i + width, (int)size), min(i + 2*width, (int)size));
        }
        // Swapp data_res and data pointers
        data_ptr = (data_ptr == data ? data_res : data);
        data_res_ptr = (data_res_ptr == data_res ? data : data_res);
    }

    // Copy the result in data param pointer so that caller retreive the sorted data
    (void) memcpy(data, data_res, size * sizeof(*data));

    return EXIT_SUCCESS;
}

/* Selection Sort */
int selection_sort(int data[], size_t size)
{
    for (int i = 0 ; i < size-1 ; i++)
    {
        for (int j = i+1 ; j < size ; j++)
        {
            if(data[i] > data[j])
                swap(data+i, data+j);
        }
    }
    return EXIT_SUCCESS;
}

/* Bubble Sort */
int bubble_sort(int data[], size_t size)
{
    for (int i = 1 ; i <= size ; i++)
    {
        for (int j = 0 ; j < size-1 ; j++)
        {
            if(data[j] > data[j+1])
                swap(data+j, data+(j+1));
        }
    }
    return EXIT_SUCCESS;
}

/* Swapping Sort */
int swapping_sort(int data[], size_t size)
{
    int i, j, tmp, k;

    for (i = 1 ; i < size ; i++)
    {
        if(data[i] < data[i-1])
        {
            j = 0;
            while(data[i] > data[j]) j++;

            tmp = data[i];

            for(k = i-1 ; k >= j ; k--)
                data[k+1] = data[k]; // "Shift Reg"
            
            data[j] = tmp;
        }
    }
    return EXIT_SUCCESS;
}

