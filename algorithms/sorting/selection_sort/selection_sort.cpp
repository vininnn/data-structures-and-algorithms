#include "selection_sort.hpp"

#include <iostream>

void selection_sort(std::vector<int>& arr){
    size_t n = arr.size();

    if (n <= 1) return;

    for (size_t i = 0; i < n - 1; i++){
        size_t min = i;

        // for (int val : arr) {
        //     std::cout << val << " ";
        // }
        // std::cout << "\n";

        for (size_t j = i + 1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }    
        }

        if (min != i){
            std::swap(arr[i], arr[min]);
        }
    }
}