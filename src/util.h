#ifndef UTIL_H
#define UTIL_H

#define BUBBLE    0
#define SELECTION 1

/* Length macro for integer arrays */
#define LENGTH(a) (sizeof(a)/sizeof(int))

/* Expands to a sort function name with an apply function.
 *     NAME -- the sort's name (ie. bubble or selection).
 *     A    -- the array to sort.
 *     FN   -- the function to apply. */
#define SORT_APPLY(NAME, A, FN) (SORT_FN(NAME)(A, LENGTH(a), FN) )
#define SORT_FN(str) str ## _sort_apply

/* Simple swap utility function */
void swap(int *x, int *y);

#endif

