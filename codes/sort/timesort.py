from threading import Timer, active_count, Lock
from random import shuffle
from time import perf_counter_ns


def check_sort(a: list[int]) -> bool:
    for i in range(len(a) - 1):
        if a[i] > a[i + 1]:
            return False
    return True


def generate_list(n: int = 100) -> list[int]:
    a = list(range(n))
    shuffle(a)
    return a


def counting_sort(a: list[int]) -> list[int]:
    """Counting sort. Complexity: O(n + k)

    Args:
        a (list[int]): unsorted list of integers

    Returns:
        list[int]: sorted list of integers
    """
    b = [0] * (max(a) + 1)
    for x in a:
        b[x] += 1
    return [x for x in b if x > 0]


def merge_sort(a: list[int]) -> list[int]:
    """Merge sort. Complexity: O(n log n)

    Args:
        a (list[int]): unsorted list of integers

    Returns:
        list[int]: sorted list of integers
    """
    if len(a) <= 1:
        return a

    def merge(left: list[int], right: list[int]) -> list[int]:
        """Merge two sorted lists. Complexity: O(n)"""
        result = []
        i, j = 0, 0
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                result.append(left[i])
                i += 1
            else:
                result.append(right[j])
                j += 1
        result += left[i:]
        result += right[j:]
        return result

    mid = len(a) // 2
    left = merge_sort(a[:mid])
    right = merge_sort(a[mid:])

    return merge(left, right)


def quick_sort(a: list[int]) -> list[int]:
    """Quick sort. Complexity: O(n log n)

    Args:
        a (list[int]): unsorted list of integers

    Returns:
        list[int]: sorted list of integers
    """
    if len(a) <= 1:
        return a

    pivot = a[0]
    left = [x for x in a[1:] if x <= pivot]
    right = [x for x in a[1:] if x > pivot]

    return quick_sort(left) + [pivot] + quick_sort(right)


def bubble_sort(a: list[int]) -> list[int]:
    """Bubble sort. Complexity: O(n^2)

    Args:
        a (list[int]): unsorted list of integers

    Returns:
        list[int]: sorted list of integers
    """
    for i in range(len(a)):
        for j in range(len(a) - i - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
    return a


def sleep_sort(a: list[int]) -> list[int]:
    """Sleep sort. Complexity: O(n).

    Args:
        a (list[int]): unsorted list of integers

    Returns:
        list[int]: sorted list of integers
    """
    b = []
    lock = Lock()

    def safe_append(x):
        with lock:
            b.append(x)

    for x in a:
        Timer(x / 10e9, lambda x: safe_append, args=[x]).start()

    while active_count() > 1:
        pass

    return b


def main():
    # number of tests
    test_num = 1000
    # number of elements in each test
    elements_num = 100

    algorithms = [
        counting_sort,
        quick_sort,
        bubble_sort,
        sleep_sort,
    ]

    elapsed = {a: 0 for a in algorithms}

    for _ in range(test_num):
        # generate list of elements
        unsorted_list = generate_list(elements_num)
        for a in algorithms:
            # start timer
            start = perf_counter_ns()
            # sort list
            sorted_list = a(unsorted_list)
            # stop timer and calculate elapsed time (in ms)
            end = perf_counter_ns()
            elapsed[a] += (end - start) / 10e3
            # check if sorted
            if not check_sort(sorted_list):
                raise Exception(f"List is not sorted. Algorithm {a.__name__} failed.")

    # Sleep sort should be the fastest algorithm, with a complexity of O(n).
    # Or is it?
    # All algorithms sort the same list of elements at each test iteration.
    print(f"Results for {test_num} tests:")
    for algorithm, elapsed_ms in elapsed.items():
        print(
            f"\t{algorithm.__name__}: "
            f"{elapsed_ms} ms, {elapsed_ms / test_num} ms per sort"
        )

    print(f"Fastest algorithm: {min(elapsed, key=lambda x: elapsed[x]).__name__}")
    print(f"Slowest algorithm: {max(elapsed, key=lambda x: elapsed[x]).__name__}")


if __name__ == "__main__":
    main()
