#include <stdio.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "serial.h"
#include "sort.h"
#define LENGTH(a) (sizeof(a)/sizeof(int))

void print_sort_state(int a[], size_t len, size_t pos) {
    for (size_t i = 0; i < len; i++)
        printf("%5s  ", i == pos? "v" : "");
    printf("\r\n");
    for (size_t i = 0; i < len; i++)
        printf(i < len - 1? "%5d, " : "%5d\r\n", a[i]);
    printf("\r\n");
    _delay_ms(1000);
}

int main(void) {

    serial_init(19200);

    for(size_t i = 0;; i ^= 1) {
        printf("\r\n===Randomizing===\r\n\r\n");
        int a[] = { 5, 2, 4, 1, -2, 4, -5 };
        bubble_sort_apply(a, LENGTH(a), print_sort_state);
    }

}
