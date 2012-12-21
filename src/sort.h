#ifndef SORT_H
#define SORT_H

typedef void (*apply_fn)(int*, size_t, size_t);

void bubble_sort_apply(int a[], size_t len, apply_fn fn);

#endif
