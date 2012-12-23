#include <stdbool.h>
#include "sort.h"

void bubble_sort_apply(int a[], size_t len, apply_fn fn) {
    bool swapped;
    int temp;
    size_t pos;
    for (size_t i = 0; i < len; i++) {
        swapped = false;
        for (pos = len - 1; pos > i; pos--) {
            fn(a, len, pos);
            if (a[pos] < a[pos-1]) {
                temp = a[pos];
                a[pos] = a[pos-1];
                a[pos-1] = temp;
                swapped = true;
            }
        }
        fn(a, len, pos);
        if (!swapped) {
            break;
        }
    }
}
