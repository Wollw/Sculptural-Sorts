#include <stdio.h>
#include <avr/io.h>
#include "serial.h"

void serial_init(uint32_t baudrate) {
    // Set Baudrate
    UBRR0H = (UBRR_ASYNC_NORMAL(baudrate) >> 8);
    UBRR0L = UBRR_ASYNC_NORMAL(baudrate);
    
    // Enable RX and TX
    UCSR0B |= _BV(RXEN0) | _BV(TXEN0);

    // Set 8N1 Framing
    UCSR0C |= _BV(UCSZ00) | _BV(UCSZ01);
    
    fdevopen(serial_write, serial_read);
}

int serial_write(char c, FILE *fp) {
    (void)*fp;
    while ( !(UCSR0A & (1 << UDRE0)) );
    UDR0 = c;
    return 0;
}

int serial_read(FILE *fp) {
    (void)*fp;
    while ( !(UCSR0A & (1 << RXC0)) );
    return UDR0;
}
