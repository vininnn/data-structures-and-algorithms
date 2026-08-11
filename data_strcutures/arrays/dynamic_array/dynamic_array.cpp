#include "dynamic_array.hpp"
#include <iostream>

DynamicArray::DynamicArray()
    : data(nullptr),
    size(0),
    capacity(0)
{
}

DynamicArray::DynamicArray(std::initializer_list<int> values)
    : data(new int[values.size()]),
    size(values.size()),
    capacity(values.size())
{
    size_t i = 0;
    for (int value: values){
        data[i++] = value;
    } 
}

void DynamicArray::double_capacity() {

}
    
void DynamicArray::insert_bacK(int value) {

}

int DynamicArray::remove_back() {

}

bool DynamicArray::empty() {
    return size == 0;
}

size_t DynamicArray::get_size() const {

}

size_t DynamicArray::get_capacity() const {

}


void DynamicArray::insert(int value) {
    insert_bacK(value);
}

void DynamicArray::insert(size_t index, int value){

}

int DynamicArray::remove(){
    remove_back();
}

int DynamicArray::remove(size_t index){

}
