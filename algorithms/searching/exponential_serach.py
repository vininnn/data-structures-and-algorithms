from binary_search import binary_search

def exponential_search(array, target):
    if not array:
        return -1

    if array[0] == target:
        return 0

    n = len(array)
    i = 1

    while i < n and array[i] < target:
        i *= 2

    if i < n and array[i] == target:
        return i

    return binary_search(array, target, i // 2, min(i, n - 1))