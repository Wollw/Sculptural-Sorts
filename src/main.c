#include <stdlib.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

#define DELAY_MS    750
#define COLOR_COUNT 3

#define SHFT_DDR    DDRB
#define SHFT_PORT   PORTB
#define SHFT_SER_IN PIN0
#define SHFT_RCK    PIN1
#define SHFT_SRCK   PIN2
#define SHFT_G      PIN3
#define SHFT_SRCLR  PIN4

enum { LED_GREEN
     , LED_CYAN
     , LED_BLUE
     };

void sort(uint8_t*, uint8_t);

void shift_init(void);
void shift_begin(void);
void shift_end(void);
void shift_bit(bool);

int main(void) {
    shift_init();
    srandom(0);
    uint8_t a[8];
    for(;;) {
        for (int i = 0; i < 8; i++)
            a[i] = ((uint8_t)random()) % COLOR_COUNT;
        sort(a, 8);
    }
}

void shift_init(void) {
    SHFT_DDR |= _BV(SHFT_SER_IN)
             |  _BV(SHFT_RCK)
             |  _BV(SHFT_SRCK)
             |  _BV(SHFT_G)
             |  _BV(SHFT_SRCK);
    _delay_us(100);
}

void shift_begin(void) {
    SHFT_PORT |= _BV(SHFT_G)
              |  _BV(SHFT_SRCLR);
    _delay_us(100);
}

void shift_end(void) {
    SHFT_PORT |= _BV(SHFT_RCK);
    _delay_us(100);
    SHFT_PORT &= ~_BV(SHFT_RCK);
    _delay_us(100);
    SHFT_PORT &= ~_BV(SHFT_G);
    _delay_us(100);
}

void shift_bit(bool bit) {
    if (bit)
        SHFT_PORT |= _BV(SHFT_SER_IN);
    else
        SHFT_PORT &= ~_BV(SHFT_SER_IN);
    _delay_us(100);
    SHFT_PORT |= _BV(SHFT_SRCK);
    _delay_us(100);
    SHFT_PORT &= ~_BV(SHFT_SRCK);
    _delay_us(100);
}

void show_state(uint8_t a[], uint8_t len, uint8_t pos) {
    shift_begin();
    for (int8_t i = len - 1; i >= 0; i--) {
        switch (a[i]) {
            case LED_GREEN: shift_bit(true); break;
            case LED_CYAN:  shift_bit(false);  break;
            case LED_BLUE:  shift_bit(false);  break;
        }
    }
    for (int8_t i = len - 1; i >= 0; i--) {
        switch (a[i]) {
            case LED_GREEN: shift_bit(false);  break;
            case LED_CYAN:  shift_bit(false);  break;
            case LED_BLUE:  shift_bit(true); break;
        }
    }
    for (int8_t i = len - 1; i >= 0; i--) {
            shift_bit(i != pos);
    }
    shift_end();
    _delay_ms(DELAY_MS/3);
    _delay_ms(DELAY_MS/3);
    _delay_ms(DELAY_MS/3);
}

/* BUBBLE SORT */
/*
void sort(uint8_t a[], uint8_t len) {
    uint8_t swapped;
    uint8_t i, tmp;
    for (;;) {
        swapped = 0;
        for (i = 0; i < len-1; i++) {
            show_state(a, len, i);
            if (a[i+1] < a[i]) {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                swapped = 1;
            }
        }
        show_state(a, len, i);
        if (!swapped)
            break;
    }
}
*/

/* INSERTION SORT */
void sort(uint8_t a[], uint8_t len) {
    uint8_t i, j, t;
    for (i = 1; i < len; i++) {
        show_state(a, len, i);
        for (j = i; j > 0 && a[j] < a[j-1]; j--) {
            t = a[j];
            a[j] = a[j-1];
            a[j-1] = t;
            show_state(a, len, j-1);
        }
    }
}

/* SELECTION SORT */
/*
void sort(uint8_t a[], uint8_t len) {
    uint8_t i, j, k, t;
    for (i = 0; i < len; i++) {
        k = i;
        show_state(a, len, i);
        for (j = i + 1; j < len; j++) {
            show_state(a, len, j);
            if (a[j] < a[k]) {
                k = j;
            }
        }
        if (k != i) {
            if (k != j-1)
                show_state(a, len, k);
            t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
        if (i+1 != len)
            show_state(a, len, i);
        else
            show_state(a, len, -1);
    }
}
*/
