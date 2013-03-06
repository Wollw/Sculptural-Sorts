#include <stdbool.h>
#include "sorts.h"
#include "../util.h"

void selection_sort_apply(uint8_t a[], uint8_t len, apply_fn fn) {
    uint8_t i, j, k, t;
    for (i = 0; i < len; i++) {
        k = i;
        fn(a, len, i);
        for (j = i + 1; j < len; j++) {
            fn(a, len, j);
            if (a[j] < a[k]) {
                k = j;
            }
        }
        if (k != i) {
            if (k != j-1)
                fn(a, len, k);
            t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
        if (i+1 != len)
            fn(a, len, i);
        else
            fn(a, len, -1);
    }
}

