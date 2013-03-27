#include <stdlib.h>

//#include <util/delay.h>

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
    
    // Shift out the color array state.
    for (uint8_t i = 0; i < len; i++) {
        switch (a[i]) {
            case GREEN:
                SHIFT_OUT(ON);
                SHIFT_OUT(OFF);
                break;
            case CYAN:
                SHIFT_OUT(ON);
                SHIFT_OUT(ON);
                break;
            case BLUE:
                SHIFT_OUT(OFF);
                SHIFT_OUT(ON);
                break;
        }
    }

    // Shift out the cursor position.
    for (uint8_t i = 0; i < len; i++)
        SHIFT_OUT(i == pos ? ON : OFF);

    SHIFT_END();
    for (uint32_t i = 0; i < 1000000000UL; i++);
}

uint8_t a[8];
int main(void) {
    SHIFT_INIT();
    for(;;) {       // Randomize and sort forever.
        for (uint8_t i = 0; i < LENGTH(a); i++) {
            a[i] = random() % 3;
        }
        SORT_APPLY(ALGORITHM, a, display_sort_state);
    }
}
