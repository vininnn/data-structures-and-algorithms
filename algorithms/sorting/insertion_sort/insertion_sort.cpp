#include "insertion_sort.hpp"

// #include <iostream>

void insertion_sort(std::vector<int>& arr){
    size_t n = arr.size();
    
    for (size_t i = 1; i < n; i++){
        int j = i - 1;
        int key = arr[i];

        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;

            // for (int val : arr) {
            //     std::cout << val << " ";
            // }
            // std::cout << "\n";
        }

        arr[j+1] = key;
    }
}