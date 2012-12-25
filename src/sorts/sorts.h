#ifndef SORT_H
#define SORT_H
#include <string.h>

/* Type signature for functions that can be applied to the sort. */
typedef void (*apply_fn)(int*, size_t, size_t);

/* Sort functions with an applied function that will run
 * for each step of the sort.
 *      int a[]     -- The array to sort.
 *      size_t len  -- the length of the array.
 *      apply_fn fn -- The function to run for each step of the sort. */
void bubble_sort_apply(int a[], size_t len, apply_fn fn);
void selection_sort_apply(int a[], size_t len, apply_fn fn);
void insertion_sort_apply(int a[], size_t len, apply_fn fn);

#endif
