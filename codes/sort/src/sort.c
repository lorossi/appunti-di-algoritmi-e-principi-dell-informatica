#include "sort.h"

/**
 * @brief Swap two elements of an array
 *
 * @param a array containing the elements to swap
 * @param p index of the first element
 * @param q index of the second element
 */
void swap(int *a, int p, int q)
{
  if (p == q)
    return;

  int t = a[p];
  a[p] = a[q];
  a[q] = t;
}

/**
 * @brief Support function for build_max_heap. Fix a node in a max heap
 *
 * @param a array containing the heap
 * @param i index of the node to fix
 * @param len length of the array
 */
void max_heapify(int *a, int i, int len)
{
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int max = i;

  if (left < len && a[left] > a[i])
    max = left;
  if (right < len && a[right] > a[max])
    max = right;

  if (max != i)
  {
    swap(a, i, max);
    max_heapify(a, max, len);
  }
}

/**
 * @brief Create a max heap from an array
 *
 * @param sequence array to be converted
 * @param len length of the array
 */
void build_max_heap(int *sequence, int len)
{
  for (int i = len / 2 - 1; i >= 0; i--)
    max_heapify(sequence, i, len);
}

/**
 * @brief Heap sort
 *
 * @param sequence array to be ordered
 * @param len length of the array
 */
void heap_sort(int *sequence, int len)
{
  build_max_heap(sequence, len);
  for (int i = len - 1; i > 0; i--)
  {
    swap(sequence, 0, i);
    max_heapify(sequence, 0, i);
  }
}

/**
 * @brief Insertion sort
 *
 * @param sequence array to sort
 * @param len length of the array
 */
void insertion_sort(int *sequence, int len)
{
  for (int j = 1; j < len; j++)
  {
    int key = sequence[j];
    int i = j - 1;

    while (i >= 0 && sequence[i] > key)
    {
      sequence[i + 1] = sequence[i];
      i--;
    }

    sequence[i + 1] = key;
  }
}

/**
 * @brief Selection sort
 *
 * @param sequence array to sort
 * @param len length of the array
 */
void selection_sort(int *sequence, int len)
{
  for (int i = 0; i < len - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < len; j++)
    {
      if (sequence[j] < sequence[min])
        min = j;
    }
    swap(sequence, i, min);
  }
}

/**
 * @brief Bubble sort
 *
 * @param sequence array to order
 * @param len length of the array
 */
void bubble_sort(int *sequence, int len)
{
  for (int i = 0; i < len - 1; i++)
  {
    for (int j = 0; j < len - i - 1; j++)
    {
      if (sequence[j] > sequence[j + 1])
        swap(sequence, j, j + 1);
    }
  }
}

/**
 * @brief Support function for the merge sort
 *
 * @param sequence array to order
 * @param p index of the first element
 * @param q index of the middle element
 * @param r index of the last element
 */
void merge(int *sequence, int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1 + 1], R[n2 + 1];

  for (int i = 0; i < n1; i++)
    L[i] = sequence[p + i];

  for (int i = 0; i < n2; i++)
    R[i] = sequence[q + 1 + i];

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  int i = 0;
  int j = 0;

  for (int k = p; k <= r; k++)
  {
    if (L[i] <= R[j])
    {
      sequence[k] = L[i];
      i++;
    }
    else
    {
      sequence[k] = R[j];
      j++;
    }
  }
}

/**
 * @brief Merge sort
 *
 * @param sequence array to order
 * @param p index of the first element
 * @param r index of the last element
 */
void merge_sort(int *sequence, int p, int r)
{
  if (p < r)
  {
    int q = (p + r) / 2;
    merge_sort(sequence, p, q);
    merge_sort(sequence, q + 1, r);
    merge(sequence, p, q, r);
  }
}

/**
 * @brief Support function of the quick sort
 *
 * @param sequence array to order
 * @param p index of the first element
 * @param r index of the last element
 * @return pivot position
 */
int partition(int *sequence, int p, int r)
{
  int x = sequence[r];
  int i = p - 1;
  for (int j = p; j < r; j++)
  {
    if (sequence[j] <= x)
    {
      i++;
      swap(sequence, i, j);
    }
  }

  swap(sequence, i + 1, r);
  return i + 1;
}

/**
 * @brief Quick sort
 *
 * @param sequence array to order
 * @param p index of the first element
 * @param r index of the last element
 */
void quick_sort(int *sequence, int p, int r)
{
  if (p < r)
  {
    int q = partition(sequence, p, r);
    quick_sort(sequence, p, q - 1);
    quick_sort(sequence, q + 1, r);
  }
}