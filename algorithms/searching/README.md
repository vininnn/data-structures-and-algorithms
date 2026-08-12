# Searching Algorithms

This directory contains implementations of different searching algorithms.

- [Binary Search](#binary-search)
- [Exponential Search](#exponential-search)

## Binary Search

Binary Search is a searching algorithm for **sorted arrays**. It works by repeatedly dividing the search range in half.

At each step:

1. Compare the target with the middle element.
2. If they are equal, return the index.
3. If the target is greater, search the right half.
4. Otherwise, search the left half.

For example:

```text
[2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
                  ↑
                middle
```

If the target is greater than the middle element, everything to its left can be discarded.

### Complexity

- Best case: O(1)
- Average case: O(log n)
- Worst case: O(log n)
- Space: O(1)

Binary Search is generally the simplest choice when searching a sorted array with a known range.


## Exponential Search

Exponential Search is also designed for sorted arrays. It first finds a suitable search range by repeatedly doubling an index:

```text
1 → 2 → 4 → 8 → 16 → 32 → ...
```

Once the target is within the discovered range, Binary Search is used to find it.

For example:

```text
[2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
      ↑     ↑           ↑
      1 --- 4 --------- 8
```

The algorithm keeps doubling the index until it reaches or passes the target, then performs Binary Search on the resulting range.

### Complexity

- Best case: O(1)
- Average case: O(log n)
- Worst case: O(log n)
- Space: O(1)

Exponential Search can be preferable when the target is likely to be near the beginning of the array, since it can find a small search range quickly.

It is also useful when the upper bound of the search range is unknown, as the exponential phase discovers it dynamically.

For a normal sorted array where the entire range is already known, Binary Search is usually the more straightforward choice.

### Implementation Details

The Exponential Search implementation reuses the Binary Search implementation by allowing it to receive custom search boundaries:

```text
binary_search(array, target, lo, hi)
```

This avoids duplicating the Binary Search logic and allows Exponential Search to search only within the range it discovered.