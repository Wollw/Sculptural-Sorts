#include <stdlib.h>
#include <util/delay.h>
#include "sort.h"
#include "shift.h"

#define LENGTH(a) (sizeof(a)/sizeof(int))

enum color_type {
    GREEN,
    CYAN,
    BLUE
};

inline void swap(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}

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
