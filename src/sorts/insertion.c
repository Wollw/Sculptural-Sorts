#include <stdbool.h>
#include "sorts.h"
#include "../util.h"

void insertion_sort_apply(uint8_t a[], uint8_t len, apply_fn fn) {
    uint8_t i, j;
    for (i = 1; i < len; i++) {
        fn(a, len, i);
        for (j = i; j > 0 && a[j] < a[j-1]; j--) {
            uint8_t t = a[j];
            a[j] = a[j-1];
            a[j-1] = t;
            fn(a, len, j-1);
        }
    }
}

