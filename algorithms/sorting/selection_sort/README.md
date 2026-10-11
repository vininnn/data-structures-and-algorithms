# Selection Sort

An implementation of the Selection Sort algorithm.

## Features

* In-place sorting algorithm (requires $O(1)$ auxiliary space)
* Minimal memory writes (performs at most $n - 1$ swaps)
* Unstable sort by default (swapping non-adjacent elements may alter relative order of duplicates)
* Deterministic performance (always executes the same number of comparisons)

## Complexity

Let $n$ be the number of elements in the collection.

| Case          |      Time Complexity | Space Complexity |
| ------------- | -------------------: | ---------------: |
| Best Case     |             $O(n^2)$ |           $O(1)$ |
| Average Case  |             $O(n^2)$ |           $O(1)$ |
| Worst Case    |             $O(n^2)$ |           $O(1)$ |

* **All Cases ($O(n^2)$):** Selection Sort always scans the remaining unsublist entirely to find the minimum element, regardless of whether the array is already sorted, reversed, or random.

---

> **Note on Complexity:** The exact number of comparisons in all cases is given by the sum $1 + 2 + \dots + (n-1)$, which evaluates to $\frac{n(n-1)}{2}$ (often approximated using $\frac{n(n+1)}{2}$). Since asymptotic notation ($O$) ignores constant factors ($\frac{1}{2}$) and lower-order terms ($-n$), the operational cost simplifies directly to $O(n^2)$. However, unlike Bubble Sort or Insertion Sort, Selection Sort makes at most $O(n)$ total memory writes (swaps).

## How It Works

The algorithm divides the array into a sorted sublist (left) and an unsorted sublist (right). In each iteration, it finds the smallest element in the unsorted sublist and swaps it with the leftmost unsorted element, growing the sorted sublist by one position.

```text
Initial Array:
[ 64 │ 25 │ 12 │ 22 │ 11 ]  -> Min in unsorted [64..11] is 11 -> Swap 64 & 11

Pass 1:
[ 11* │ 25 │ 12 │ 22 │ 64 ] -> Min in unsorted [25..64] is 12 -> Swap 25 & 12

Pass 2:
[ 11* │ 12* │ 25 │ 22 │ 64 ] -> Min in unsorted [25..64] is 22 -> Swap 25 & 22

Pass 3:
[ 11* │ 12* │ 22* │ 25 │ 64 ] -> Min in unsorted [25..64] is 25 -> Already in place

Until:
[ 11* │ 12* │ 22* │ 25* │ 64* ] -> Complete sorted
```

---

## Build and Run

The folder includes a `Makefile` configured to link utility files and compile the executable.

Compile the project:

```bash
make
```

Run the program:

```bash
./main
```

Build and execute directly:

```bash
make run
```

Build, run, and measure execution time with OS `time`:

```bash
make run-time
```

Clean build artifacts:

```bash
make clean
```