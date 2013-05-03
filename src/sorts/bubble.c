#include "sorts.h"

void bubble_sort(uint8_t a[], uint8_t len) {
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
