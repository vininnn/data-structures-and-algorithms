#include "bubble_sort.hpp"
#include "../../../utils/generators.hpp"

#include <iostream>
#include <chrono>

int main(){
    constexpr size_t SIZE = 10000;

    auto arr = generate_random_vector(SIZE);
    auto start = std::chrono::high_resolution_clock::now();

    bubble_sort(arr);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    // for (int val : arr) {
    //     std::cout << val << ", ";
    // }
    // std::cout << "\n";

    std::cout << duration.count() << " ms (" 
              << duration.count() / 1000.0 << " s)\n";
    
    return 0;
}