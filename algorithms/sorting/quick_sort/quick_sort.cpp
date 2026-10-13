#include "quick_sort.hpp"

#include <utility>

static size_t partition(std::vector<int>& arr, size_t left, size_t right){
    int pivot = arr[right];
    size_t i = left;

    for (size_t j = left; j < right; j++){
        if (arr[j] < pivot){
            std::swap(arr[i], arr[j]);
            i++;
        }
    }

    std::swap(arr[i], arr[right]);

    return i;
}

void quick_sort(std::vector<int>& arr, size_t left, size_t right){
    if (left >= right) return;

    size_t pivot = partition(arr, left, right);

    if (pivot > left){
        quick_sort(arr, left, pivot - 1);
    }
    quick_sort(arr, pivot + 1, right);
}

void quick_sort(std::vector<int>& arr){
    size_t n = arr.size();
    if (n <= 1) return;
    
    quick_sort(arr, 0, n-1);
}