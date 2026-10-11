#include "bubble_sort.hpp"

// #include <iostream>

void bubble_sort(std::vector<int>& arr){
    size_t n = arr.size();
    int temp;

    for (size_t i = 0; i < n; i++){
        bool swapped = false;

        // for (int val : arr) {
        //     std::cout << val << " ";
        // }
        // std::cout << "\n";

        for (size_t j = 0; j < n-1; j++){
            if (arr[j] > arr[j+1]){
                swapped = true;
                
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

        if (!swapped){
           break;     
        }
    }
}