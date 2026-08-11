#pragma once

#include <cstddef>
#include <initializer_list>
#include <iostream>

class DynamicArray {
private:
    int* data;
    size_t size;
    size_t capacity;

    void double_capacity();
    
    void insert_bacK(int value);
    int remove_back();

public:
    DynamicArray();
    DynamicArray(std::initializer_list<int> values);
    ~DynamicArray();

    int& operator[](size_t index);

    size_t get_size() const;
    size_t get_capacity() const;
    bool empty();

    void insert(int value);
    void insert(int value, size_t index);
    int remove();
    int remove(size_t index);

    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& arr);
};