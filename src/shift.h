#ifndef SHIFT_H
#define SHIFT_H
#include <stdbool.h>

#define CFG_SHIFT_DDR   DDRB
#define CFG_SHIFT_SER   PB0
#define CFG_SHIFT_RCLK  PB1
#define CFG_SHIFT_SRCLK PB2
#define CFG_SHIFT_PORT  PORTB

void shift_bits_init(void);
void shift_bit_out(bool b);
void shift_bits_begin(void);
void shift_bits_end(void);

#endif
