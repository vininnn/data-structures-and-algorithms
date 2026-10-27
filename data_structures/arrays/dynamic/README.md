# Dynamic Array

A dynamic array implementation in C++ built from scratch using manually managed dynamic memory.

The implementation is designed to explore how dynamic arrays work internally, including memory allocation, resizing, element insertion/removal, bounds checking, and operator overloading.

## Features

* Dynamic memory allocation using `new[]` and `delete[]`
* Automatic capacity growth
* Initializer-list construction
* Element access through `operator[]`
* Insertion at the end
* Insertion at a specific index
* Removal from the end
* Removal from a specific index
* Bounds checking with exceptions
* `empty()`, `get_size()`, and `get_capacity()`
* `operator<<` for direct printing with `std::cout`

## Complexity

Let `n` be the number of elements currently stored.

| Operation        |     Complexity |
| ---------------- | -------------: |
| `operator[]`     |           O(1) |
| Insert at end    | O(1) amortized |
| Remove from end  |           O(1) |
| Insert at index  |           O(n) |
| Remove at index  |           O(n) |

Insertion at the end is **O(1) amortized** because the array only needs to allocate and copy its elements when the current capacity is exhausted.

When resizing is necessary, the capacity is increased and the existing elements must be moved to the new memory block. These occasional O(n) operations are spread across many insertions, resulting in an amortized O(1) cost per insertion.

## Memory Layout

The structure maintains three main pieces of information:

```text
data
 ↓
┌────┬────┬────┬────┬────┬────┬────┐
│ 10 │ 20 │ 30 │    │    │    │    │
└────┴────┴────┴────┴────┴────┴────┘
 ↑─────────────↑
     size = 3

 ↑─────────────────────────────────↑
          capacity = 7
```

`size` represents the number of elements currently stored, while `capacity` represents the amount of memory currently allocated.

Elements beyond `size` are allocated but are not considered part of the array.

## Implementation Details

The array starts empty and allocates memory when the first element is inserted.

When the current capacity is reached, the implementation increases the capacity and reallocates the underlying memory.

The class also performs bounds checking for element access, insertion, and removal, throwing `std::out_of_range` when an invalid index is provided.

## Build

The project includes a `Makefile` to simplify compilation.

```bash
make
```

Run the program with:

```bash
./main
```

Build and Run:

```bash
make run
```

To remove compiled files:

```bash
make clean
```