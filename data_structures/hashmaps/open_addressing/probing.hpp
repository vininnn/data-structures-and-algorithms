#pragma once
 
#include <cstddef>

struct LinearProbing {
    size_t operator()(size_t hash, size_t attempt, size_t capacity) const {
        return (hash % capacity + attempt) % capacity;
    }
};

struct QuadraticProbing {
    size_t operator()(size_t hash, size_t attempt, size_t capacity) const {
        return (hash % capacity + (attempt * attempt + attempt) / 2) % capacity;
    }
};
