#include "sort.h"

#include <time.h>
#include <stdio.h>

#define ARRAY_LEN 1000
#define TESTS_NUM 1000
int sequence[ARRAY_LEN];

void print_time(clock_t started, clock_t ended)
{
  printf("\tCompleted in %f ms.\n", (double)(ended - started) / CLOCKS_PER_SEC * 1000);
  printf("\tAverage sorting time per array: %f ms.\n\n", (double)(ended - started) / CLOCKS_PER_SEC * 1000 / TESTS_NUM);
}

int main()
{
  srand(time(NULL));
  clock_t started, ended;

  printf("Number of tests: %d. Number of items per array: %d.\n\n", TESTS_NUM, ARRAY_LEN);

  started = clock();
  printf("Testing bubble sort.\n");
  for (int i = 0; i < TESTS_NUM; i++)
  {
    populate_array(sequence, ARRAY_LEN);
    shuffle_array(sequence, ARRAY_LEN);
    bubble_sort(sequence, ARRAY_LEN);
    test_array(sequence, ARRAY_LEN);
  }
  ended = clock();
  print_time(started, ended);

  started = clock();
  printf("Testing selection sort.\n");
  for (int i = 0; i < TESTS_NUM; i++)
  {
    populate_array(sequence, ARRAY_LEN);
    shuffle_array(sequence, ARRAY_LEN);
    selection_sort(sequence, ARRAY_LEN);
    test_array(sequence, ARRAY_LEN);
  }
  ended = clock();
  print_time(started, ended);

  started = clock();
  printf("Testing insertion sort.\n");
  for (int i = 0; i < TESTS_NUM; i++)
  {
    populate_array(sequence, ARRAY_LEN);
    shuffle_array(sequence, ARRAY_LEN);
    insertion_sort(sequence, ARRAY_LEN);
    test_array(sequence, ARRAY_LEN);
  }
  ended = clock();
  print_time(started, ended);

  started = clock();
  printf("Testing heap sort.\n");
  for (int i = 0; i < TESTS_NUM; i++)
  {
    populate_array(sequence, ARRAY_LEN);
    shuffle_array(sequence, ARRAY_LEN);
    heap_sort(sequence, ARRAY_LEN);
    test_array(sequence, ARRAY_LEN);
  }
  ended = clock();
  print_time(started, ended);

  started = clock();
  printf("Testing merge sort.\n");
  for (int i = 0; i < TESTS_NUM; i++)
  {
    populate_array(sequence, ARRAY_LEN);
    shuffle_array(sequence, ARRAY_LEN);
    merge_sort(sequence, 0, ARRAY_LEN - 1);
    test_array(sequence, ARRAY_LEN);
  }
  ended = clock();
  print_time(started, ended);

  started = clock();
  printf("Testing quick sort.\n");
  for (int i = 0; i < TESTS_NUM; i++)
  {
    populate_array(sequence, ARRAY_LEN);
    shuffle_array(sequence, ARRAY_LEN);
    quick_sort(sequence, 0, ARRAY_LEN - 1);
    test_array(sequence, ARRAY_LEN);
  }
  ended = clock();
  print_time(started, ended);

  started = clock();
  printf("Testing counting sort.\n");
  for (int i = 0; i < TESTS_NUM; i++)
  {
    int ordered[ARRAY_LEN];
    populate_array(sequence, ARRAY_LEN);
    shuffle_array(sequence, ARRAY_LEN);

    counting_sort(sequence, ARRAY_LEN, ordered, ARRAY_LEN - 1);
    test_array(ordered, ARRAY_LEN);
  }
  ended = clock();
  print_time(started, ended);

  printf("All tests passed\n");

  return 0;
}
