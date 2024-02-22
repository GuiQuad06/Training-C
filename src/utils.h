#ifndef UTILS_H_
#define UTILS_H_

#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define alloc_nr(x) (((x)+16)*3/2)

#define bitsizeof(x)  (CHAR_BIT * sizeof(x))

#define maximum_unsigned_value_of_type(a) \
    (UINTMAX_MAX >> (bitsizeof(uintmax_t) - bitsizeof(a)))

#define unsigned_mult_overflows(a, b) \
    ((a) && (b) > maximum_unsigned_value_of_type(a) / (a))

#define REALLOC_ARRAY(x, alloc) (x) = realloc((x), st_mult(sizeof(*(x)), (alloc)))

#define ALLOC_GROW(x, nr, alloc) \
	do { \
		if ((nr) > alloc) { \
			if (alloc_nr(alloc) < (nr)) \
				alloc = (nr); \
			else \
				alloc = alloc_nr(alloc); \
			REALLOC_ARRAY(x, alloc); \
		} \
	} while (0)

static inline size_t st_mult(size_t a, size_t b)
{
	if (unsigned_mult_overflows(a, b))
		fprintf(stderr, "size_t overflow: %lu * %lu", (uintmax_t)a, (uintmax_t)b);
	return a * b;
}

#endif // UTILS_H_
