#include "sorts.h"

void sift_down(uint8_t a[], uint8_t len, uint8_t start, uint8_t end, apply_fn fn) {
    uint8_t root = start;
    fn(a, len, start);

    while (root * 2 + 1 <= end) {
        uint8_t child = root * 2 + 1;
        uint8_t swap = root;
        if (a[swap] < a[child])
            swap = child;
        if (child + 1 <= end && a[swap] < a[child+1]) 
            swap = child + 1;
        if (swap != root) {
            uint8_t tmp = a[swap];
            a[swap] = a[root];
            a[root] = tmp;
            fn(a, len, swap);
            root = swap;
        } else
            return;
    }
}

void heap_sort_apply(uint8_t a[], uint8_t len, apply_fn fn) {

    uint8_t start = (len - 2) / 2;
    while (start > 0) {
        sift_down(a, len, start--, len - 1, fn);
    }
    sift_down(a, len, start, len - 1, fn);

    uint8_t end = len - 1;
    while (end > 0) {
        fn(a, len, 0);
        uint8_t tmp = a[end];
        a[end] = a[0];
        a[0] = tmp;
        fn(a, len, end);
        sift_down(a, len, 0, --end, fn);
    }
}
