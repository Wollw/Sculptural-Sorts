#include <stdlib.h>
#include <util/delay.h>

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
 *      uint8_t a[] -- The current state of the array.
 *      uint8_t len -- The length of the array.
 *      uint8_t pos -- The position of the sorting cursor.
 */
void display_sort_state(
        uint8_t a[], uint8_t len, uint8_t pos) {

    SHIFT_BEGIN();

    // Shift out the cursor position.
    for (uint8_t i = 0; i < len; i++)
        SHIFT_OUT(i == pos ? ON : OFF);
    
    // Shift out the elements.
    for (uint8_t i = 0; i < len; i++)
        SHIFT_OUT(a[i]);
    
    // Shift out filler bits.
    for (uint8_t i = 0; i < len; i++)
        SHIFT_OUT(OFF);
    
    SHIFT_END();

    PORTB |= _BV(4);
    _delay_ms(1000);
    PORTB &= ~_BV(4);

}

int main(void) {
    uint8_t a[8];
    SHIFT_INIT();
    for(;;) {       // Randomize and sort forever.
        for (uint8_t i = 0; i < LENGTH(a); i++) {
            a[i] = random() % 2;
        }
        SORT_APPLY(ALGORITHM, a, display_sort_state);
        display_sort_state(a, LENGTH(a), 255);
    }
}
