#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "../src/sorts/sorts.h"
#include "../src/util.h"

/* Function executed for each step of the sorting algorithm.
 * Prints to stdout for testing.
 *      int a[]    -- The current state of the array being sorted.
 *      size_t len -- The length of the array.
 *      size_t pos -- The position of the sorting cursor in the array. */
void display_sort_state(uint8_t a[], uint8_t len, uint8_t pos) {
    uint8_t i;
    for (i = 0; i < len; i++)
        printf("%5s  ", i == pos ? "v" : " ");
    puts("");
    for (i = 0; i < len; i++) {
        printf(i == len - 1? "%5d" : "%5d, ", a[i]);
    }
    puts("");
    sleep(1);

}

int main(void) {

    uint8_t a[] = {
        9,8,7,6,5,4,3,2,1,0
    };

    SORT_APPLY(ALGORITHM, a, display_sort_state);

    return 0;
}
