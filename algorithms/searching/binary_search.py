def binary_search(array, target, lo=0, hi=None):
    if hi is None:
        hi = len(array) - 1

    while lo <= hi:
        mid = (hi + lo) // 2       

        if array[mid] == target:
            return mid
        elif array[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1

    return -1