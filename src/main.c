#include <stdlib.h>
#include <util/delay.h>
#include <stdbool.h>
#include "sorts/sorts.h"
#include "shift.h"
#include "util.h"

/* Available color states */
enum color_type {
    GREEN,
    CYAN,
    BLUE
};

/* Function executed for each step of the sorting algorithm.
 * This is used to change the state of the LEDs of the sculpture.
 *      uint8_t a[]    -- The current state of the array being sorted.
 *      uint8_t len -- The length of the array.
 *      uint8_t pos -- The position of the sorting cursor in the array. */
void display_sort_state(uint8_t a[], uint8_t len, uint8_t pos) {
    SHIFT_BEGIN();

    uint8_t i;
    for (i = 0; i < len; i++) {
        switch (a[i]) {
            case GREEN:
                SHIFT_OUT(true);
                SHIFT_OUT(false);
                break;
            case CYAN:
                SHIFT_OUT(true);
                SHIFT_OUT(true);
                break;
            case BLUE:
                SHIFT_OUT(false);
                SHIFT_OUT(true);
                break;
        }
    }

    for (i = 0; i < len; i++)
        SHIFT_OUT(i == pos ? true : false);

    SHIFT_END();
    _delay_ms(1000);
}

int main(void) {

    uint8_t a[8];

    SHIFT_INIT();
    for(;;) {
        for (uint8_t i = 0; i < LENGTH(a); i++) {
            a[i] = rand() % 3;
        }
        SORT_APPLY(ALGORITHM, a, display_sort_state);
    }
}
