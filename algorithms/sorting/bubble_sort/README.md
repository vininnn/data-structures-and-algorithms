# Bubble Sort

An implementation of the Bubble Sort algorithm.

## Features

* In-place sorting algorithm (requires $O(1)$ auxiliary space)
* Stable sort (preserves the relative order of equal elements)
* Early-exit optimization (terminates early if no swaps occur during a pass)

## Complexity

Let $n$ be the number of elements in the collection.

| Case          |      Time Complexity | Space Complexity |
| ------------- | -------------------: | ---------------: |
| Best Case     |               $O(n)$ |           $O(1)$ |
| Average Case  |             $O(n^2)$ |           $O(1)$ |
| Worst Case    |             $O(n^2)$ |           $O(1)$ |

* **Best Case ($O(n)$):** Occurs when the array is already sorted. The algorithm makes a single pass of $n - 1$ comparisons, detects zero swaps, and terminates early.
* **Worst Case ($O(n^2)$):** Occurs when the array is sorted in reverse order, requiring the maximum number of iterations and swaps.

---

> **Note on Complexity:** The exact number of comparisons in the worst case is given by the sum $1 + 2 + \dots + (n-1)$, which evaluates to $\frac{n(n-1)}{2}$ (often approximated using $\frac{n(n+1)}{2}$). Since asymptotic notation ($O$) ignores constant factors ($\frac{1}{2}$) and lower-order terms ($-n$), the operational cost simplifies directly to $O(n^2)$.

## How It Works

The algorithm repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process causes larger values to "bubble up" to their correct positions at the end of the collection.

```text
Pass 1:
[ 5 │ 3 │ 8 │ 1 ]  -> Compare 5 & 3 -> Swap
[ 3 │ 5 │ 8 │ 1 ]  -> Compare 5 & 8 -> No swap
[ 3 │ 5 │ 8 │ 1 ]  -> Compare 8 & 1 -> Swap
[ 3 │ 5 │ 1 │ 8* ] -> '8' is now in its final position

Pass 2:
[ 3 │ 5 │ 1 │ 8* ] -> Compare 3 & 5 -> No swap
[ 3 │ 5 │ 1 │ 8* ] -> Compare 5 & 1 -> Swap
[ 3 │ 1 │ 5*│ 8* ] -> '5' is now in its final position

Pass 3:
[ 3 │ 1 │ 5*│ 8* ] -> Compare 3 & 1 -> Swap
[ 1*│ 3*│ 5*│ 8* ] -> Completely sorted
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