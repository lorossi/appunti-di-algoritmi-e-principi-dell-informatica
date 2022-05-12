#include "sort.h"

/**
 * @brief Populate an array of length len with all numbers from 0 to len-1
 *
 * @param sequence array to fill
 * @param len length of the array
 */
void populate_array(int *sequence, int len)
{
  for (int i = 0; i < len; i++)
    sequence[i] = i;
}

/**
 * @brief Shuffle an array of length len
 *
 * @param sequence array to shuffle
 * @param len length of the array
 */
void shuffle_array(int *sequence, int len)
{
  if (len == 1)
    return;

  for (int i = 0; i < len - 1; i++)
  {
    size_t j = i + rand() / (RAND_MAX / (len - i) + 1);
    int t = sequence[j];
    sequence[j] = sequence[i];
    sequence[i] = t;
  }
}

/**
 * @brief Test that the array is ordered
 *
 * @param sequence array to test
 * @param len length of the array
 */
void test_array(int *sequence, int len)
{
  for (int i = 0; i < len; i++)
    assert(sequence[i] == i);
}

/**
 * @brief Print the array
 *
 * @param sequence array to print
 * @param len length of the array
 */
void print_array(int *sequence, int len)
{
  for (int i = 0; i < len; i++)
    printf("%d ", sequence[i]);
  printf("\n");
}