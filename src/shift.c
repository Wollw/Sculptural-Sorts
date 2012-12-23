#include <avr/io.h>
#include "shift.h"

void shift_bits_init(void) {
    CFG_SHIFT_DDR |= _BV(CFG_SHIFT_RCLK)
                  |  _BV(CFG_SHIFT_SRCLK)
                  |  _BV(CFG_SHIFT_SER);
}

void shift_bit_out(bool bit) {
    CFG_SHIFT_PORT &= ~_BV(CFG_SHIFT_SRCLK);
    if (bit)
        CFG_SHIFT_PORT |= _BV(CFG_SHIFT_SER);
    else
        CFG_SHIFT_PORT &= ~_BV(CFG_SHIFT_SER);
    CFG_SHIFT_PORT |= _BV(CFG_SHIFT_SRCLK);
}

void shift_bits_begin(void) {
    CFG_SHIFT_PORT &= ~_BV(CFG_SHIFT_RCLK);
}

void shift_bits_end(void) {
    CFG_SHIFT_PORT |= _BV(CFG_SHIFT_RCLK);
}
