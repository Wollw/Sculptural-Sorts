#ifndef SERIAL_H
#define SERIAL_H
#include <stdint.h>
#define UBRR_ASYNC_NORMAL(br) ((F_CPU / (br * 16UL)) - 1)

void serial_init(uint32_t baudrate);   // Initializes Serial
int serial_write(char c, FILE *fp); // Send a character over serial
int serial_read(FILE *fp);  // Read a character from serial buffer (blocking)

#endif
