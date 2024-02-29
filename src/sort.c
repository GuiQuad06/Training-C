#include "sort.h"
#include "basics.h"

#include <stdlib.h>

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

