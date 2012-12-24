#include <stdlib.h>
#include <util/delay.h>
#include "sort.h"
#include "shift.h"

#define LENGTH(a) (sizeof(a)/sizeof(int))

/* Available color states */
enum color_type {
    GREEN,
    CYAN,
    BLUE
};

/* Function executed for each step of the sorting algorithm.
 * This is used to change the state of the LEDs of the sculpture.
 *      int a[]    -- The current state of the array being sorted.
 *      size_t len -- The length of the array.
 *      size_t pos -- The position of the sorting cursor in the array. */
void display_sort_state(int a[], size_t len, size_t pos) {
    shift_bits_begin();

    for (size_t i = 0; i < len; i++) {
        switch (a[i]) {
            case GREEN:
                shift_bit_out(true);
                shift_bit_out(false);
                break;
            case CYAN:
                shift_bit_out(true);
                shift_bit_out(false);
                break;
            case BLUE:
                shift_bit_out(false);
                shift_bit_out(true);
                break;
        }
    }

    for (size_t i = 0; i < len; i++)
        shift_bit_out(i == pos ? true : false);

    shift_bits_end();
    _delay_ms(1000);
}

/* Simple swap utility function */
inline void swap(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}

int main(void) {

    int a[] = {
        BLUE, CYAN,
        GREEN, BLUE,
        CYAN, GREEN,
        CYAN, GREEN
    };

    shift_bits_init();
    for(;;) {
        for (size_t i = 0; i < LENGTH(a); i++) {
            swap(&a[i], &a[rand()%LENGTH(a)]);
        }
        bubble_sort_apply(a, LENGTH(a), display_sort_state);
    }
}
