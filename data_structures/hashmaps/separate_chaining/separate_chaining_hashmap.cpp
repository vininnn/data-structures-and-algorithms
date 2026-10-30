#include "separate_chaining_hashmap.hpp"

#include <stdexcept>

SeparateChainingHashMap::SeparateChainingHashMap(size_t capacity)
    : buckets(nullptr),
    capacity(capacity),
    size(0)
{
    if (capacity == 0) {
        throw std::invalid_argument("SeparateChainingHashMap::SeparateChainingHashMap: invalid argument 'capacity'");
    }

    buckets = new Node*[capacity]{};
}

SeparateChainingHashMap::~SeparateChainingHashMap() {
    clear();
    delete[] buckets;
}

int& SeparateChainingHashMap::operator[](int key) {
    size_t index = hash(key);

    Node* current = buckets[index];

    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }

        current = current->next;
    }

    buckets[index] = new Node(key, 0, buckets[index]);
    ++size;

    return buckets[index]->value;
}

size_t SeparateChainingHashMap::hash(int value) const {
    return value % capacity;
}

void SeparateChainingHashMap::insert(int key, int value) {
    size_t index = hash(key);

    Node* current = buckets[index];
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value;
            return;
        }

        current = current->next;
    }

    buckets[index] = new Node(key, value, buckets[index]);
    size++;
}

bool SeparateChainingHashMap::remove(int key) {
    size_t index = hash(key);

    Node** link = &buckets[index];
    while (*link != nullptr) {
        Node* current = *link;

        if (current->key == key) {
            *link = current->next;
            delete current;
            --size;
            return true;
        }

        link = &current->next;
    }

    return false;
}

bool SeparateChainingHashMap::replace(int key, int value) {
    size_t index = hash(key);

    Node* current = buckets[index];
    while (current != nullptr) {
        if (current->key == key) {
            current->value = value;
            return true;
        }

        current = current->next;
    }

    return false;
}

bool SeparateChainingHashMap::contains_key(int key) const {
    size_t index = hash(key);

    Node* current = buckets[index];
    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }

        current = current->next;
    }

    return false;
}

bool SeparateChainingHashMap::contains_value(int value) const {
    for (size_t i = 0; i < capacity; i++) {
        Node* current = buckets[i];
        while (current != nullptr) {
            if (current->value == value) {
                return true;
            }
    
            current = current->next;
        }
    }

    return false;
}

int SeparateChainingHashMap::get(int key) const {
    size_t index = hash(key);

    Node* current = buckets[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }

        current = current->next;
    }

    throw std::out_of_range("SeparateChainingHashMap::get: key not exists");
}

size_t SeparateChainingHashMap::get_size() const {
    return size;
}

bool SeparateChainingHashMap::empty() const {
    return size == 0;
}

void SeparateChainingHashMap::clear() {
    for (size_t i = 0; i < capacity; i++) {
        Node* current = buckets[i];
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }

        buckets[i] = nullptr;
    }

    size = 0;
}

std::ostream& operator<<(
    std::ostream& os,
    const SeparateChainingHashMap& map
) {
    os << "{";

    bool first = true;

    for (size_t i = 0; i < map.capacity; ++i) {
        auto* current = map.buckets[i];

        while (current != nullptr) {
            if (!first) {
                os << ", ";
            }

            os << current->key << ": " << current->value;

            first = false;
            current = current->next;
        }
    }

    os << "}";

    return os;
}