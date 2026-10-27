#pragma once

#include <cstddef>
#include <iostream>

class SinglyLinkedList {
private:
    struct Node {
        int value;
        Node* next;

        Node(int value, Node* next = nullptr)
            : value(value), next(next) {}
    };

    Node* head;
    Node* tail;
    size_t size;
public:
    SinglyLinkedList();
    SinglyLinkedList(std::initializer_list<int> values);
    ~SinglyLinkedList();
    
    int get(size_t index) const;
    int get_first() const;
    int get_last() const; 

    void add(int value);
    void add(int value, size_t index);
    void add_first(int value);
    void add_last(int value);

    void remove();
    void remove(size_t index);
    void remove_first();
    void remove_last();

    size_t get_size() const;
    bool empty() const;
    void clear();

    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list);
};