#ifndef SHIFT_H
#define SHIFT_H
#include <avr/io.h>

/* Pin and port values for the shift registers */
#define CFG_SHIFT_DDR   DDRB
#define CFG_SHIFT_SER   PB0
#define CFG_SHIFT_RCLK  PB1
#define CFG_SHIFT_SRCLK PB2
#define CFG_SHIFT_PORT  PORTB

/* Initialize the pins used for the shift registers. */
#define SHIFT_INIT() \
    CFG_SHIFT_DDR |= _BV(CFG_SHIFT_RCLK) \
                  |  _BV(CFG_SHIFT_SRCLK) \
                  |  _BV(CFG_SHIFT_SER)

/* Shift a bit state out to the shift registers */
#define SHIFT_OUT(bit) \
    do { \
        CFG_SHIFT_PORT &= ~_BV(CFG_SHIFT_SRCLK); \
        if (bit) \
            CFG_SHIFT_PORT |= _BV(CFG_SHIFT_SER); \
        else \
            CFG_SHIFT_PORT &= ~_BV(CFG_SHIFT_SER); \
        CFG_SHIFT_PORT |= _BV(CFG_SHIFT_SRCLK); \
    } while (0)

/* Begin a shift out process.
 * Run this before using shift_bit_out.
 */
#define SHIFT_BEGIN() (CFG_SHIFT_PORT &= ~_BV(CFG_SHIFT_RCLK))

/* End a shift out process.
 * Run this after the last call of shift_bit_out.
 */
#define SHIFT_END()    (CFG_SHIFT_PORT |= _BV(CFG_SHIFT_RCLK))

#endif
