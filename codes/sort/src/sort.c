#include "sort.h"

/**
 * @brief Swap two elements of an array.
 * Complexity: O(1)
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
 * @brief Support function for build_max_heap. Fix a node in a max heap.
 * Compexity: O(log n).
 *
 * @param a array containing the heap
 * @param i index of the node to fix
 * @param len length of the array
 */
void max_heapify(int *a, int i, int len)
{
  // left and right children of the node
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  // largest child of the node
  int max = i;

  // check if the childern are larger than the node
  if (left < len && a[left] > a[i])
    max = left;
  if (right < len && a[right] > a[max])
    max = right;

  // if the node is not the largest, swap it with the largest child
  if (max != i)
  {
    swap(a, i, max);
    // apply the same procedure to the child
    max_heapify(a, max, len);
  }
}

/**
 * @brief Create a max heap from an array.
 * Complexity: O(n log n).
 *
 * @param sequence array to be converted
 * @param len length of the array
 */
void build_max_heap(int *sequence, int len)
{
  // iterate over the internal nodes, as the leaves
  // are already in the correct order
  for (int i = len / 2 - 1; i >= 0; i--)
    max_heapify(sequence, i, len);
}

/**
 * @brief Heap sort.
 * Complexity: O(n log n).
 *
 * @param sequence array to be ordered
 * @param len length of the array
 */
void heap_sort(int *sequence, int len)
{
  // in a max heap, the root is the largest element
  build_max_heap(sequence, len);
  for (int i = len - 1; i > 0; i--)
  {
    // take root (first element) and put it in the last position
    swap(sequence, 0, i);
    // fix the heap discarding the last element
    max_heapify(sequence, 0, i);
  }
}

/**
 * @brief Insertion sort.
 * Complexity: O(n^2).
 *
 * @param sequence array to sort
 * @param len length of the array
 */
void insertion_sort(int *sequence, int len)
{
  // iterate over each element of the array
  for (int j = 1; j < len; j++)
  {
    int key = sequence[j];
    int i = j - 1;

    // find the first element that is smaller than the key
    while (i >= 0 && sequence[i] > key)
    {
      sequence[i + 1] = sequence[i];
      i--;
    }

    // insert the key in the correct position
    sequence[i + 1] = key;
  }
}

/**
 * @brief Selection sort.
 * Complexity: O(n^2).
 *
 * @param sequence array to sort
 * @param len length of the array
 */
void selection_sort(int *sequence, int len)
{
  // iterate over the array
  for (int i = 0; i < len - 1; i++)
  {
    int min = i;

    for (int j = i + 1; j < len; j++)
    {
      // find the first place where the element is smaller than the current
      if (sequence[j] < sequence[min])
        min = j;
    }
    swap(sequence, i, min);
  }
}

/**
 * @brief Bubble sort.
 * Complexity: O(n^2).
 *
 * @param sequence array to order
 * @param len length of the array
 */
void bubble_sort(int *sequence, int len)
{
  // iterate over the array
  for (int i = 0; i < len - 1; i++)
  {
    // compare each element with the next one
    for (int j = 0; j < len - i - 1; j++)
    {
      // if the current element is larger than the next one, swap them
      if (sequence[j] > sequence[j + 1])
        swap(sequence, j, j + 1);
    }
  }
}

/**
 * @brief Support function for the merge sort.
 * Complexity: O(n).
 *
 * @param sequence array to order
 * @param p index of the first element
 * @param q index of the middle element
 * @param r index of the last element
 */
void merge(int *sequence, int p, int q, int r)
{
  // left and right portions of the array
  int n1 = q - p + 1;
  int n2 = r - q;

  // create two temporary arrays
  int L[n1 + 1], R[n2 + 1];

  // copy the elements to the temporary arrays
  for (int i = 0; i < n1; i++)
    L[i] = sequence[p + i];

  for (int i = 0; i < n2; i++)
    R[i] = sequence[q + 1 + i];

  // insert the sentinel element
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  // initialize the two pointers
  int i = 0;
  int j = 0;

  // merge the two arrays
  for (int k = p; k <= r; k++)
  {
    if (L[i] <= R[j])
    {
      // the item on the left is smaller
      sequence[k] = L[i];
      // increase the position of the left pointer
      i++;
    }
    else
    {
      // the item on the right is smaller
      sequence[k] = R[j];
      // increase the position of the right pointer
      j++;
    }
  }
}

/**
 * @brief Merge sort.
 * Complexity: O(n log n).
 *
 * @param sequence array to order
 * @param p index of the first element
 * @param r index of the last element
 */
void merge_sort(int *sequence, int p, int r)
{
  if (p < r)
  {
    // find the middle element
    int q = (p + r) / 2;
    // sort the two poetions
    merge_sort(sequence, p, q);
    merge_sort(sequence, q + 1, r);
    // merge the two sorted portions
    merge(sequence, p, q, r);
  }
}

/**
 * @brief Support function of the quick sort.
 * Complexity: O(n).
 *
 * @param sequence array to order
 * @param p index of the first element
 * @param r index of the last element
 * @return pivot position
 */
int partition(int *sequence, int p, int r)
{
  // choose the last element as the pivot
  int x = sequence[r];
  // initialize the pointer for the biggest element
  int i = p - 1;
  for (int j = p; j < r; j++)
  {
    // if the current element is smaller than the pivot
    if (sequence[j] <= x)
    {
      // increase the position of the pointer
      i++;
      // swap the current element with the one on the left
      swap(sequence, i, j);
    }
  }

  swap(sequence, i + 1, r);
  return i + 1;
}

/**
 * @brief Quick sort.
 * Complexity: O(n log n).
 *
 * @param sequence array to order
 * @param p index of the first element
 * @param r index of the last element
 */
void quick_sort(int *sequence, int p, int r)
{
  if (p < r)
  {
    // find the pivot position
    int q = partition(sequence, p, r);
    // sort the left and right portions
    quick_sort(sequence, p, q - 1);
    quick_sort(sequence, q + 1, r);
  }
}

/**
 * @brief Counting sort.
 * Complexity: O(n + k).
 *
 * @param sequence array to order
 * @param len length of the array
 * @param ordered array to store the ordered sequence
 * @param max maximum value of the array
 */
void counting_sort(int *sequence, int len, int *ordered, int max)
{
  int C[max + 1];

  // initialize C
  for (int i = 0; i <= max; i++)
    C[i] = 0;

  // count the elements = i
  for (int j = 0; j < len; j++)
    C[sequence[j]]++;

  // count the elements <= i
  for (int i = 1; i <= max; i++)
    C[i] += C[i - 1];

  for (int j = len; j >= 0; j--)
  {
    // order the elements according to the position stored in C
    ordered[C[sequence[j - 1]] - 1] = sequence[j - 1];
    // decrease the position of the element
    C[sequence[j - 1]]--;
  }
}