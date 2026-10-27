#include "dynamic_array.hpp"

#include <iostream>

int main() {
    DynamicArray growth;

    for (int i = 0; i < 20; ++i) {
        growth.insert(i);

        std::cout
            << "size = " << growth.get_size()
            << ", capacity = " << growth.get_capacity()
            << '\n';
    }

    std::cout << growth << "\n";
}