#include "generators.hpp"
#include <random>

std::vector<int> generate_random_vector(size_t size, int min_val, int max_val) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(min_val, max_val);

    std::vector<int> vec(size);
    for (size_t i = 0; i < size; ++i) {
        vec[i] = dist(rng);
    }
    return vec;
}
