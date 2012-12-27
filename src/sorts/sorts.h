#ifndef SORT_H
#define SORT_H
#include <stdint.h>

/* Type signature for functions that can be applied to the sort. */
typedef void (*apply_fn)(uint8_t*, uint8_t, uint8_t);

/* Sort functions with an applied function that will run
 * for each step of the sort.
 *      uint8_t a[]     -- The array to sort.
 *      uint8_t len  -- the length of the array.
 *      apply_fn fn -- The function to run for each step of the sort. */
void bubble_sort_apply(uint8_t a[], uint8_t len, apply_fn fn);
void selection_sort_apply(uint8_t a[], uint8_t len, apply_fn fn);
void insertion_sort_apply(uint8_t a[], uint8_t len, apply_fn fn);
void shell_sort_apply(uint8_t a[], uint8_t len, apply_fn fn);
void heap_sort_apply(uint8_t a[], uint8_t len, apply_fn fn);

#endif
