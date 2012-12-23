#ifndef SHIFT_H
#define SHIFT_H
#include <stdlib.h>
#include <stdbool.h>
typedef uint64_t bits_type;

#define CFG_SHIFT_DDR   DDRB
#define CFG_SHIFT_SER   PB0
#define CFG_SHIFT_RCLK  PB1
#define CFG_SHIFT_SRCLK PB2
#define CFG_SHIFT_PORT  PORTB

/* Setup the pins needed for shifting bits.
 * The pins used can be configured in _config.h */
void shift_bits_init(void);

void shift_bit_out(bool b);

void shift_bits_begin(void);
void shift_bits_end(void);

#endif
