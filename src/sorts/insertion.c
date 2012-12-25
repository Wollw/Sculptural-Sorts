#include <stdbool.h>
#include "sorts.h"
#include "../util.h"

void insertion_sort_apply(int a[], size_t len, apply_fn fn) {
    size_t i, j;
    for (i = 1; i < len; i++) {
        fn(a, len, i);
        for (j = i; j > 0 && a[j] < a[j-1]; j--) {
            swap(&a[j], &a[j-1]);
            fn(a, len, j-1);
        }
    }
}

