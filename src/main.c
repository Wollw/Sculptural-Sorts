#include <stdio.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "serial.h"
#include "sort.h"

#define LENGTH(a) (sizeof(a)/sizeof(int))

inline void swap(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}

void display_sort_state(int a[], size_t len, size_t pos) {
    for (size_t i = 0; i < len; i++)
        printf(i < len - 1 ? "%5s  " : "%5s\r\n", i == pos? "v" : "");
    for (size_t i = 0; i < len; i++)
        printf(i < len - 1 ? "%5d, " : "%5d\r\n", a[i]);
    printf("\r\n");
    _delay_ms(1000);
}

int main(void) {
    serial_init(19200);
    int a[] = {1,2,3,4,5};
    for(;;) {
        printf("===RANDOMIZING===\r\n");
        for (size_t i = 0; i < 5; i++) {
            swap(&a[i], &a[rand()%5]);
        }
        bubble_sort_apply(a, LENGTH(a), display_sort_state);
    }
}
