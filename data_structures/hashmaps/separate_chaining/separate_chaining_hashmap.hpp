#pragma once

#include <cstddef>
#include <ostream>

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

    int& operator[](int key);

    void insert(int key, int value);
    bool remove(int key);
    bool replace(int key, int value);
    bool contains_key(int key) const;
    bool contains_value(int value) const;
    int get(int key) const;

    size_t get_size() const;
    bool empty() const;
    void clear();

    friend std::ostream& operator<<(std::ostream& os, const SeparateChainingHashMap& map);
};