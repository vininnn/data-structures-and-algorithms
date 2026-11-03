#pragma once

#include <functional>
#include <vector>

template <typename Key, typename Value,
    typename Hash = std::hash<Key>, 
    typename KeyEqual = std::equal_to<Key>>
class OpenAddressingHashMap {
private:
    enum class State : unsigned char { Empty, Occupied, Deleted };

    struct Slot {
        Key key;
        Value value;
        State state = State::Empty;
    }

    std::vector<Slot> buckets;
    size_t num_occupied;
    size_t num_deleted;
    double maxLoadFactor;

    Hash hash_;
    KeyEqual equal_to_;
    
    size_t hash(const Key& key) const {
        return hash_(key) % buckets.size();
    }

    void resize(size_t new_capacity) {

    }

public:
    explicit OpenAddressingHashMap(size_t capacity = 16) {

    }

    ~OpenAddressingHashMap() {

    }

    Value& operator[](const Key& Key);

    void insert(const Key& key, const Value& value) {

    }

    bool remove(const Key& key) {

    }

    bool replace(const Key& key, const Value& value) {

    }
    
    bool contains_key(const Key& key) const {

    }
    
    bool contains_value(const Value& value) const {

    }
    
    int get(const Key& key) const {

    }

    size_t get_size() const { 
        return num_occupied; 
    }

    bool empty() const { 
        return num_occupied == 0; 
    }
    
    void clear() {

    }

    double load_factor() const {

    }

    double max_load_factor() const { 
        return maxLoadFactor; 
    }
    
    void max_load_factor(double value) { 
        maxLoadFactor = value; 
    }

    friend std::ostream& operator<<(std::ostream& os, const SeparateChainingHashMap& map) {
        
    }

};