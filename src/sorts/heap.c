#include "sorts.h"

/* Implemented based on the CLRS recursive algorithm.
 * This should really probably be reimplemented using a
 * non-recursive algorithm. */

#define PARENT(i) (i/2-1)
#define LEFT(i)   (2*i+1)
#define RIGHT(i)  (2*i+2)

void max_heapify(uint8_t a[], uint8_t i, uint8_t len, uint8_t heap_size, apply_fn fn) {
    uint8_t l = LEFT(i);
    uint8_t r = RIGHT(i);
    uint8_t largest;
    fn(a, len, i);

    if (l < heap_size && a[l] > a[i])
        largest = l;
    else
        largest = i;

    if (r < heap_size && a[r] > a[largest])
        largest = r;
    
    if (largest != i) {
        uint8_t tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;
        max_heapify(a, largest, len, heap_size, fn);
    }
}

void build_max_heap(uint8_t a[], uint8_t len, apply_fn fn) {
    uint8_t i; 
    for (i = len / 2 ; i > 0; i--) {
        max_heapify(a, i, len, len, fn);
    }
    max_heapify(a, i, len, len, fn);
}

void heap_sort_apply(uint8_t a[], uint8_t len, apply_fn fn) {
    build_max_heap(a, len, fn);
    uint8_t i;
    for (i = len - 1; i > 0; i--) {
        fn(a, len, i);
        uint8_t tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        max_heapify(a, 0, len, i, fn);
    }
}
