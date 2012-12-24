#include <stdbool.h>
#include "sorts.h"
#include "../util.h"

void bubble_sort_apply(int a[], size_t len, apply_fn fn) {
    bool swapped;
    size_t i, j;
    for (i = 0; i < len; i++) {
        swapped = false;
        for (j = len - 1; j > i; j--) {
            fn(a, len, j);
            if (a[j] < a[j-1]) {
                swap(&a[j], &a[j-1]);
                swapped = true;
            }
        }
        fn(a, len, j);
        if (!swapped) {
            break;
        }
    }
}

