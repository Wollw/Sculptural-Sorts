#ifndef SHIFT_H
#define SHIFT_H
#include <stdbool.h>

/* Pin and port values for the shift registers */
#define CFG_SHIFT_DDR   DDRB
#define CFG_SHIFT_SER   PB0
#define CFG_SHIFT_RCLK  PB1
#define CFG_SHIFT_SRCLK PB2
#define CFG_SHIFT_PORT  PORTB

/* Initialize the pins used for the shift registers. */
void shift_bits_init(void);

/* Begin a shift out process.  Run this before using shift_bit_out. */
void shift_bits_begin(void);

/* Shift a bit state out to the shift registers */
void shift_bit_out(bool b);

/* End a shift out process.  Run this after the last call of shift_bit_out */
void shift_bits_end(void);

#endif
