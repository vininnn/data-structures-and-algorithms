# Insertion Sort

An implementation of the Insertion Sort algorithm.

## Features

* In-place sorting algorithm (requires $O(1)$ auxiliary space)
* Stable sort (preserves the relative order of equal elements)
* Adaptive (highly efficient for small or nearly sorted datasets)

## Complexity

Let $n$ be the number of elements in the collection.

| Case          |      Time Complexity | Space Complexity |
| ------------- | -------------------: | ---------------: |
| Best Case     |               $O(n)$ |           $O(1)$ |
| Average Case  |             $O(n^2)$ |           $O(1)$ |
| Worst Case    |             $O(n^2)$ |           $O(1)$ |

* **Best Case ($O(n)$):** Occurs when the array is already sorted. The algorithm makes $n - 1$ comparisons and $0$ element shifts.
* **Worst Case ($O(n^2)$):** Occurs when the array is sorted in reverse order, requiring the maximum number of comparisons and shifts at each iteration.

---

> **Note on Complexity:** The exact number of comparisons/shifts in the worst case is given by the sum $1 + 2 + \dots + (n-1)$, which evaluates to $\frac{n(n-1)}{2}$ (often approximated using $\frac{n(n+1)}{2}$). Since asymptotic notation ($O$) ignores constant factors ($\frac{1}{2}$) and lower-order terms ($-n$), the operational cost simplifies directly to $O(n^2)$.

## How It Works

The algorithm builds the final sorted array one item at a time. It iterates through the input list, taking one element per iteration (the `key`) and inserting it into its correct position within the already sorted left portion of the array by shifting larger elements to the right.

```text
Initial Array:
[ 5* │ 2 │ 4 │ 1 ]  -> Key = 2, shift 5 -> Insert 2
[ 2 │ 5* │ 4 │ 1 ]  -> Sorted sublist: [ 2, 5 ]

Pass 2:
[ 2 │ 5* │ 4 │ 1 ]  -> Key = 4, shift 5 -> Insert 4
[ 2 │ 4 │ 5* │ 1 ]  -> Sorted sublist: [ 2, 4, 5 ]

Pass 3:
[ 2 │ 4 │ 5* │ 1 ]  -> Key = 1, shift 5, 4, 2 -> Insert 1
[ 1 │ 2 │ 4 │ 5* ]  -> Complete sorted
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