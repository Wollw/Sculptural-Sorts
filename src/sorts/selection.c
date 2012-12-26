#include <stdbool.h>
#include "sorts.h"
#include "../util.h"

void selection_sort_apply(uint8_t a[], uint8_t len, apply_fn fn) {
    uint8_t i, j, k;
    for (i = 0; i < len; i++) {
        k = i;
        fn(a, len, i);
        for (j = i + 1; j < len; j++) {
            fn(a, len, j);
            if (a[j] < a[k]) {
                k = j;
            }
        }
        uint8_t t = a[i];
        a[i] = a[k];
        a[k] = t;
        fn(a, len, i);
    }
}

