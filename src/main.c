#include <stdio.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "serial.h"
#include "sort.h"

#define LENGTH(a) (sizeof(a)/sizeof(int))

void display_sort_state(int a[], size_t len, size_t pos) {
    for (size_t i = 0; i < len; i++)
        printf("%5s ", i == pos? "v" : "");
    printf("\r\n");
    for (size_t i = 0; i < len; i++)
        printf(i < len - 1? "%5d, " : "%5d\r\n", a[i]);
    printf("\r\n");
    _delay_ms(1000);
}

int main(void) {
    for(size_t i = 0;; i ^= 1) {
        int a[5];
        for (size_t i = 0; i < 5; i++) {
            a[i] = rand();
        }
        bubble_sort_apply(a, LENGTH(a), display_sort_state);
    }
}
