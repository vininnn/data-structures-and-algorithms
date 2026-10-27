#pragma once

#include <cstddef>

class SeparateChainingHashMap {
private:
    struct Node {
        int key;
        int value;
        Node* next;

        Node(int key, int value, Node* next = nullptr)
            : key(key), value(value), next(next) {}
    };

    Node** buckets;
    size_t capacity;
    size_t size;

    size_t hash(int key) const;

public:
    explicit SeparateChainingHashMap(size_t capacity = 16);
    ~SeparateChainingHashMap();

    void insert(int key, int value);
    bool remove(int key);
    bool replace(int key, int value);
    bool contains_key(int key);
    bool contains_value(int value);
    int get(int key);

    size_t get_size() const;
    bool empty() const;
    void clear();
};