#include <stdbool.h>
#include "sorts.h"
#include "../util.h"

void bubble_sort_apply(uint8_t a[], uint8_t len, apply_fn fn) {
    bool swapped;
    uint8_t i;
    for (;;) {
        swapped = false;
        for (i = 0; i < len-1; i++) {
            fn(a, len, i);
            if (a[i+1] < a[i]) {
                uint8_t t = a[i+1];
                a[i+1] = a[i];
                a[i] = t;
                swapped = true;
            }
        }
        fn(a, len, i);
        if (!swapped) {
            break;
        }
    }
}

