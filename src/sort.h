#ifndef SORT_H_
#define SORT_H_

#include <stddef.h>

/*
 * @brief Function pointer for merge sorting
 */
typedef int (*merge_sort)(int*, size_t);

/*
 * @brief Bottom up approach of Merge sorting
 * @param data : int data array to be sorted
 * @param size : array size
 * @return status.
 */
int bottom_up(int data[], size_t size);

/*
 * @brief Top down approach of Merge sorting
 * @param data : int data array to be sorted
 * @param size : array size
 * @return status.
 */
int top_down(int data[], size_t size);

/*
 * @brief Selection Sort Algo
 * @param data : int data array to be sorted
 * @param size : array size
 * @return status.
 */
int selection_sort(int data[], size_t size);

/*
 * @brief Bubble Sort Algo
 * @param data : int data array to be sorted
 * @param size : array size
 * @return status.
 */
int bubble_sort(int data[], size_t size);
/*
 * @brief Swapping Sort Algo
 * @param data : int data array to be sorted
 * @param size : array size
 * @return status.
 */
int swapping_sort(int data[], size_t size);

#endif // SORT_H_
