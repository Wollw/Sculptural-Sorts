#include "sorts.h"

volatile int8_t cursor_last = -1;

void sift_down(uint8_t a[], uint8_t len, uint8_t start, uint8_t end, apply_fn fn) {
    uint8_t root = start;
    uint8_t tmp, child, swap;
    if (start != cursor_last) {
        fn(a, len, start);
        cursor_last = start;
    }

    while ((root << 1) + 1 <= end) {
        child = (root << 1) + 1;
        swap = root;
        if (a[swap] < a[child])
            swap = child;
        if (child + 1 <= end && a[swap] < a[child+1]) 
            swap = child + 1;
        if (swap != root) {
            tmp = a[swap];
            a[swap] = a[root];
            a[root] = tmp;
            if (swap != cursor_last) {
                fn(a, len, swap);
                cursor_last = swap;
            }
            root = swap;
        } else
            return;
    }
}

void heap_sort_apply(uint8_t a[], uint8_t len, apply_fn fn) {
    uint8_t end, tmp, start;
    start = (len - 2) >> 1;
    while (start > 0) {
        sift_down(a, len, start--, len - 1, fn);
    }
    sift_down(a, len, start, len - 1, fn);

    end = len - 1;
    while (end > 0) {
        if (cursor_last != 0) {
            fn(a, len, 0);
            cursor_last = 0;
        }
        tmp = a[end];
        a[end] = a[0];
        a[0] = tmp;
        if (cursor_last != end) {
            fn(a, len, end);
            cursor_last = end;
        }
        sift_down(a, len, 0, --end, fn);
    }
}
