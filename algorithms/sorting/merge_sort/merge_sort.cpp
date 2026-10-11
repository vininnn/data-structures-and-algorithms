#include "merge_sort.hpp"

#include <iostream>

static void merge(std::vector<int>& arr, size_t left, size_t middle, size_t right){
    size_t left_size = middle - left + 1;
    size_t right_size = right - middle;
    
    // std::vector<int> left_part(left_size);
    // std::vector<int> right_part(right_size);

    // for (size_t i = 0; i < left_size; ++i) left_part[i] = arr[left + i];
    // for (size_t j = 0; j < right_size; ++j) right_part[j] = arr[middle + 1 + j];

    std::vector<int> left_part(arr.begin() + left, arr.begin() + middle + 1);
    std::vector<int> right_part(arr.begin() + middle + 1, arr.begin() + right + 1);

    size_t i = 0;
    size_t j = 0;
    size_t k = left;

    while (i < left_size && j < right_size){
        if (left_part[i] <= right_part[j]){
            arr[k] = left_part[i];
            i++;
        } else {
            arr[k] = right_part[j];
            j++;
        }
        k++;
    }

    while (i < left_size){
        arr[k++] = left_part[i++];
    }

    while (j < right_size){
        arr[k++] = right_part[j++];
    }

}

void merge_sort(std::vector<int>& arr, size_t left, size_t right){
    if (left >= right) return;
    

    size_t middle = left + (right - left) / 2;

    merge_sort(arr, left, middle);
    merge_sort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

void merge_sort(std::vector<int>& arr){
    size_t n = arr.size();
    if (n <= 1) return;
    
    merge_sort(arr, 0, n-1);
}

