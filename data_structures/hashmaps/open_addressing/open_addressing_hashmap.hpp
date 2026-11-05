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
        new_capacity = validate_capacity(new_capacity);

        std::vector<Slot> new_buckets(new_capacity);

        for (size_t i = 0; i < capacity; ++i) {
            if (buckets[i].state == State::Occupied) {
                new_buckets[i] = buckets[i];
            } else if (buckets[i].state == State::Deleted) {
                new_buckets[i].state = State::Deleted;
            }
        }

        buckets = newBuckets;
        capacity = new_capacity;
    }

    static size_t validate_capacity(size_t capacity) {
        if (capacity == 0) {
            throw std::invalid_argument("OpenAddressingHashMap::validate_capacity: invalid argument `capacity` can't be zero");
        }

        return capacity;
    }

public:
    explicit OpenAddressingHashMap(size_t capacity = 16) 
    : buckets(validate_capacity(capacity)),
    num_occupied(0),
    num_deleted(0),
    maxLoadFactor(0.75)
    {       
    }

    ~OpenAddressingHashMap() {

    }

    Value& operator[](const Key& Key) {

    }

    void insert(const Key& key, const Value& value) {
        size_t index = hash(key);
        
        if (buckets[index].state == State::Empty) {
            buckets[index].key = key;
            buckets[index].value = value;
            buckets[index].state = State::Occupied;
        } else {
            // Sondagem
        }
    }

    bool remove(const Key& key) {
        size_t index = hash(key);

        // Sondagem
        buckets[index].state == State::Deleted;
        return true;
    }

    bool replace(const Key& key, const Value& value) {
        size_t index = hash(key);

        if (buckets[index].state == State::Occupied) {
            buckets[index].key = key;
            buckets[index].value = value;
            
            return true;
        } else {
            // Sondagem
        }
        
        return false;
    }
    
    bool contains_key(const Key& key) const {
        size_t index = hash(key);

        //while (Sondagem) state != empty
        if (buckets[index].key == key) return true;

        return false;
    }
    
    bool contains_value(const Value& value) const {
        size_t index = hash(key);

        //while (Sondagem) state != empty
        if (buckets[index].value == value) return true;

        return false;
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
        os << "{";
        
        bool first = true;

        // for (size_t i = 0; i < map.capacity; ++i) {
        //     auto* current = map.buckets[i];

        //     while (current != nullptr) {
        //         if (!first) {
        //             os << ", ";
        //         }

        //         os << current->key << ": " << current->value;

        //         first = false;
        //         current = current->next;
        //     }
        // }

        os << "}";

        return os; 
    }

};