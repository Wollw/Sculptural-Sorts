#include "sorts.h"

void shell_sort_apply(uint8_t a[], uint8_t len, apply_fn fn) {
    uint8_t i, j;
    uint8_t h = 1;
    while (h < len / 3)
        h = 3 * h + 1;

    while (h >= 1) {
        for (i = h; i < len; i++) {
            fn(a, len, i);
            for (j = i; j >= h && a[j] < a[j-h]; j -= h) {
                uint8_t tmp = a[j];
                a[j] = a[j-h];
                a[j-h] = tmp;
                fn(a, len, j-h);
            }
        }
        h /= 3;
    }

}
