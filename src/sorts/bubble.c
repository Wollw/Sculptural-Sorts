#include <stdbool.h>
#include "sorts.h"
#include "../util.h"

void bubble_sort_apply(uint8_t a[], uint8_t len, apply_fn fn) {
    bool swapped;
    uint8_t i, j;
    for (i = 0; i < len; i++) {
        swapped = false;
        for (j = len - 1; j > i; j--) {
            fn(a, len, j);
            if (a[j] < a[j-1]) {
                uint8_t t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
                swapped = true;
            }
        }
        fn(a, len, j);
        if (!swapped) {
            break;
        }
    }
}

