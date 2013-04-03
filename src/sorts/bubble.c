#include "sorts.h"
#include "../util.h"

void bubble_sort_apply(
        uint8_t a[], uint8_t len, apply_fn fn) {

    uint8_t swapped;
    uint8_t i, tmp;
    for (;;) {
        swapped = 0;
        for (i = 0; i < len-1; i++) {
            fn(a, len, i);
            if (a[i+1] < a[i]) {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
                swapped = 1;
            }
        }
        fn(a, len, i);
        if (!swapped)
            break;
    }
}

