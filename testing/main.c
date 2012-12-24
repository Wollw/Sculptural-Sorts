#include <stdio.h>
#include <stdlib.h>
#include "../src/sorts/sorts.h"
#include "../src/util.h"

/* Function executed for each step of the sorting algorithm.
 * Prints to stdout for testing.
 *      int a[]    -- The current state of the array being sorted.
 *      size_t len -- The length of the array.
 *      size_t pos -- The position of the sorting cursor in the array. */
void display_sort_state(int a[], size_t len, size_t pos) {
    size_t i;
    for (i = 0; i < len; i++)
        printf("%5s  ", i == pos ? "v" : " ");
    puts("");
    for (i = 0; i < len; i++) {
        printf(i == len - 1? "%5d" : "%5d, ", a[i]);
    }
    puts("");

}

int main(void) {

    int a[] = {
        4, 1, 34,
        92, 4, 1,
        5, 232, 1
    };

    SORT_APPLY(ALGORITHM, a, display_sort_state);

    return 0;
}
