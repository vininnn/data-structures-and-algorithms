#include "dynamic_array.hpp"

#include <stdexcept>

DynamicArray::DynamicArray()
    : data(nullptr),
    size(0),
    capacity(0)
{
}

DynamicArray::DynamicArray(std::initializer_list<int> values)
    : data(values.size() == 0 ? nullptr : new int[values.size()]),
    size(values.size()),
    capacity(values.size())
{
    size_t i = 0;
    for (int value: values){
        data[i++] = value;
    } 
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

int& DynamicArray::operator[](size_t index)
{
    if (index >= size) {
        throw std::out_of_range("DynamicArray::operator[]: index out of range");
    }
    
    return data[index];
}

void DynamicArray::double_capacity() {
    if (capacity == 0){
        capacity = 1;
        data = new int[capacity];
    } else {
        capacity *= 2;
        
        int* new_data = new int[capacity];

        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
    }
}
    
void DynamicArray::insert_bacK(int value) {
    if (size == capacity) {
        double_capacity();
    }

    data[size] = value;
    size++;
}

int DynamicArray::remove_back() {
    size--;
    return data[size];
}

bool DynamicArray::empty() {
    return size == 0;
}

size_t DynamicArray::get_size() const {
    return size;
}

size_t DynamicArray::get_capacity() const {
    return capacity;
}

void DynamicArray::insert(int value) {
    insert_bacK(value);
}

void DynamicArray::insert(int value, size_t index) {
    if (index > size) {
        throw std::out_of_range("DynamicArray::insert: index out of range");
    }
    
    if (size == capacity) {
        double_capacity();
    }

    for (size_t i = size; i > index; i--) {
        data[i] = data[i-1];
    }

    data[index] = value;
    size++;
}

int DynamicArray::remove() {
    if (empty()){
        throw std::logic_error("DynamicArray::remove: array is empty");
    }

    return remove_back();
}

int DynamicArray::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("DynamicArray::remove: index out of range");
    }

    int res = data[index];
    for (size_t i = index; i < size-1; ++i) {
        data[i] = data[i+1];
    }

    size--;
    return res;
}

std::ostream& operator<<(
    std::ostream& os,
    const DynamicArray& arr
)
{
    os << "[";

    for (size_t i = 0; i < arr.size; ++i) {
        os << arr.data[i];

        if (i + 1 < arr.size) {
            os << ", ";
        }
    }

    os << "]";

    return os;
}