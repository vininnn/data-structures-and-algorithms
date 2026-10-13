# Quick Sort

An implementation of the Quick Sort algorithm.

## Features

* In-place sorting algorithm (requires $O(\log n)$ auxiliary stack space on average)
* Unstable sort (swapping non-adjacent elements across the pivot can alter relative order of duplicates)
* Divide and Conquer approach (partitions array around a pivot and recursively sorts sublists)
* Lomuto partitioning scheme (uses the last element of the current range as the pivot)

## Complexity

Let $n$ be the number of elements in the collection.

| Case          |      Time Complexity | Space Complexity |
| ------------- | -------------------: | ---------------: |
| Best Case     |        $O(n \log n)$ |     $O(\log n)$ |
| Average Case  |        $O(n \log n)$ |     $O(\log n)$ |
| Worst Case    |             $O(n^2)$ |           $O(n)$ |

* **Best and Average Cases ($O(n \log n)$):** Occurs when the chosen pivot consistently splits the array into roughly equal halves, resulting in a recursion tree depth of $O(\log n)$.
* **Worst Case ($O(n^2)$):** Occurs when the pivot selection consistently produces completely unbalanced partitions (e.g., when the array is already sorted or reverse-sorted and the last element is picked as the pivot).

---

> **Note on Complexity:** The recursion tree for Quick Sort has an average height of $\log_2 n$ levels. At each level, the algorithm performs $O(n)$ total comparisons and swaps during the partition step. Multiplying the average height by the work done per level yields $O(n \log n)$. Memory space is determined by the maximum call stack depth, which averages $O(\log n)$ but can reach $O(n)$ in the worst case.

## How It Works

The algorithm works in two main phases:
1. **Partition:** Select a pivot element (last item) and rearrange elements so that all items smaller than the pivot precede it, and all items greater than or equal to it follow it.
2. **Divide & Conquer:** Recursively apply the same partitioning strategy to the left and right sublists surrounding the pivot.

```text
Initial Array:
[ 5 │ 2 │ 8 │ 1 │ 4 ]   (Pivot = 4)

Partition Phase (Lomuto):
• Compare 5 & 4 -> No swap
• Compare 2 & 4 -> Swap 5 & 2  --> [ 2 │ 5 │ 8 │ 1 │ 4 ]
• Compare 8 & 4 -> No swap
• Compare 1 & 4 -> Swap 5 & 1  --> [ 2 │ 1 │ 8 │ 5 │ 4 ]
• Swap Pivot (4) with 8        --> [ 2 │ 1 │ 4* │ 5 │ 8 ] ('4' is in its final position)

Recursive Calls:
• Left Subarray  [ 2 │ 1 ]  --> Partition (Pivot = 1) --> [ 1* │ 2* ]
• Right Subarray [ 5 │ 8 ]  --> Partition (Pivot = 8) --> [ 5* │ 8* ]

Final Sorted Array:
[ 1* │ 2* │ 4* │ 5* │ 8* ]
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