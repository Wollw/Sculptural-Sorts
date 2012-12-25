#include <stdbool.h>
#include "sorts.h"
#include "../util.h"

void selection_sort_apply(int a[], size_t len, apply_fn fn) {
    size_t i, j, k;
    for (i = 0; i < len; i++) {
        k = i;
        fn(a, len, i);
        for (j = i + 1; j < len; j++) {
            fn(a, len, j);
            if (a[j] < a[k]) {
                k = j;
            }
        }
        swap(&a[i], &a[k]);
        fn(a, len, i);
    }
}

