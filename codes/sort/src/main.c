#include "sort.h"

#define MAX_LEN 1000
#define MAX_TEST 1000
int sequence[MAX_LEN];

int main()
{
  srand(time(NULL));
  clock_t started, ended;
  started = clock();

  printf("Testing insertion sort.\n%d tests with array of %d elements.\n", MAX_TEST, MAX_LEN);
  for (int i = 0; i < MAX_TEST; i++)
  {
    populate_array(sequence, MAX_LEN);
    shuffle_array(sequence, MAX_LEN);
    insertion_sort(sequence, MAX_LEN);
    test_array(sequence, MAX_LEN);
  }

  printf("Testing selection sort.\n%d tests with array of %d elements.\n", MAX_TEST, MAX_LEN);
  for (int i = 0; i < MAX_TEST; i++)
  {
    populate_array(sequence, MAX_LEN);
    shuffle_array(sequence, MAX_LEN);
    selection_sort(sequence, MAX_LEN);
    test_array(sequence, MAX_LEN);
  }

  printf("Testing bubble sort.\n%d tests with array of %d elements.\n", MAX_TEST, MAX_LEN);
  for (int i = 0; i < MAX_TEST; i++)
  {
    populate_array(sequence, MAX_LEN);
    shuffle_array(sequence, MAX_LEN);
    bubble_sort(sequence, MAX_LEN);
    test_array(sequence, MAX_LEN);
  }

  printf("Testing heap sort.\n%d tests with array of %d elements.\n", MAX_TEST, MAX_LEN);
  for (int i = 0; i < MAX_TEST; i++)
  {
    populate_array(sequence, MAX_LEN);
    shuffle_array(sequence, MAX_LEN);
    heap_sort(sequence, MAX_LEN);
    test_array(sequence, MAX_LEN);
  }

  printf("Testing merge sort.\n%d tests with array of %d elements.\n", MAX_TEST, MAX_LEN);
  for (int i = 0; i < MAX_TEST; i++)
  {
    populate_array(sequence, MAX_LEN);
    shuffle_array(sequence, MAX_LEN);
    merge_sort(sequence, 0, MAX_LEN - 1);
    test_array(sequence, MAX_LEN);
  }

  printf("Testing quick sort.\n%d tests with array of %d elements.\n", MAX_TEST, MAX_LEN);
  for (int i = 0; i < MAX_TEST; i++)
  {
    populate_array(sequence, MAX_LEN);
    shuffle_array(sequence, MAX_LEN);
    quick_sort(sequence, 0, MAX_LEN - 1);
    test_array(sequence, MAX_LEN);
  }

  ended = clock();
  float duration = (ended - started) / (float)CLOCKS_PER_SEC;

  printf("All tests passed\n");
  printf("Time taken: %f s\n", duration);

  return 0;
}
