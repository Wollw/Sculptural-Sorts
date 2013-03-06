#ifndef UTIL_H
#define UTIL_H
#include <stdint.h>

/* Length macro for uint8_t arrays */
#define LENGTH(a) (sizeof(a)/sizeof(uint8_t))

/* Expands to a sort function name with an apply function.
 *     NAME -- the sort's name (ie. bubble or selection).
 *     A    -- the array to sort.
 *     FN   -- the function to apply. */
#define SORT_APPLY(NAME, A, FN) (SORT_FN(NAME)(A, LENGTH(a), FN))
#define SORT_FN(str) (str ## _sort_apply)

#endif

