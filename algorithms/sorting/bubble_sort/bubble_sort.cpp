#include "bubble_sort.hpp"

// #include <iostream>
#include <utility>

void bubble_sort(std::vector<int>& arr){
    size_t n = arr.size();

    for (size_t i = 0; i < n - 1; i++){
        bool swapped = false;

        // for (int val : arr) {
        //     std::cout << val << " ";
        // }
        // std::cout << "\n";

        for (size_t j = 0; j < n - 1; j++){
            if (arr[j] > arr[j+1]){
                swapped = true;
                std::swap(arr[j], arr[j+1]);
            }
        }

        if (!swapped){
           break;     
        }
    }
}