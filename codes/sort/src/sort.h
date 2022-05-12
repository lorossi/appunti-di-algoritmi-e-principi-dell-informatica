#ifndef _SORT
#define _SORT

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <limits.h>

// TESTING FUNCTIONS
void populate_array(int *sequence, int len);
void shuffle_array(int *sequence, int len);
void test_array(int *sequence, int len);
void print_array(int *sequence, int len);

// HEAP FUNCTION
void build_max_heap(int *sequence, int len);

// SORT FUNCTIONS
void insertion_sort(int *sequence, int len);
void selection_sort(int *sequence, int len);
void bubble_sort(int *sequence, int len);
void merge_sort(int *sequence, int p, int r);
void quick_sort(int *sequence, int p, int r);
void heap_sort(int *sequence, int len);
void counting_sort(int *sequence, int len, int *ordered, int max);

#endif