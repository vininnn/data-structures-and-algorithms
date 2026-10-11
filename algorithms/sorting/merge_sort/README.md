# Merge Sort

An implementation of the Merge Sort algorithm.

## Features

* Stable sort (preserves the relative order of equal elements)
* Guaranteed $O(n \log n)$ performance across all input distribution cases
* Out-of-place sorting algorithm (requires $O(n)$ auxiliary space for merge buffers)
* Divide and Conquer approach (divides array into halves, sorts recursively, and merges)

## Complexity

Let $n$ be the number of elements in the collection.

| Case          |      Time Complexity | Space Complexity |
| ------------- | -------------------: | ---------------: |
| Best Case     |        $O(n \log n)$ |           $O(n)$ |
| Average Case  |        $O(n \log n)$ |           $O(n)$ |
| Worst Case    |        $O(n \log n)$ |           $O(n)$ |

* **All Cases ($O(n \log n)$):** Regardless of whether the array is sorted, reversed, or random, Merge Sort always performs the full divide step down to single-element arrays and requires linear time to interleave the sublists at each level.

---

> **Note on Complexity:** The recursion tree for Merge Sort has a height of $\log_2 n$ levels (due to halving the input size at each step). At each level of the tree, the algorithm performs $O(n)$ operations across all sublists to merge them. By multiplying the work done per level ($n$) by the height of the tree ($\log_2 n$), we obtain the total operational cost of $O(n \log n)$.

## How It Works

The algorithm works in two main phases:
1. **Divide:** Recursively split the array in half until sublists contain only 1 element (which are trivially sorted).
2. **Merge:** Interleave two sorted adjacent sublists into a single sorted sublist using temporary buffer memory.

```text
Initial Array:
[ 5 │ 2 │ 8 │ 1 ]

Divide Phase:
           [ 5 │ 2 │ 8 │ 1 ]
           /               \
     [ 5 │ 2 ]           [ 8 │ 1 ]
      /     \             /     \
    [ 5 ]   [ 2 ]       [ 8 ]   [ 1 ]

Merge Phase:
[ 5 ]  +  [ 2 ]  -->  [ 2 │ 5 ]
[ 8 ]  +  [ 1 ]  -->  [ 1 │ 8 ]

Final Merge:
[ 2 │ 5 ]  +  [ 1 │ 8 ]  -->  [ 1* │ 2* │ 5* │ 8* ]
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