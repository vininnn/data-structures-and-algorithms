#pragma once

#include <functional>
#include <stdexcept>
#include <vector>

#include "probing.hpp"

template <typename Key, typename Value,
    typename Probing = LinearProbing,
    typename Hash = std::hash<Key>, 
    typename KeyEqual = std::equal_to<Key>
>
class OpenAddressingHashMap {
private:
    enum class State : unsigned char { Empty, Occupied, Deleted };

    struct Slot {
        Key key;
        Value value;
        State state = State::Empty;
    };

    static constexpr size_t npos = static_cast<size_t>(-1);

    std::vector<Slot> buckets;
    size_t num_occupied;
    size_t num_deleted;
    double maxLoadFactor;

    Probing probing_;
    Hash hash_;
    KeyEqual equal_to_;
    
    // size_t hash(const Key& key) const {
    //     return hash_(key) % buckets.size();
    // }
    
    bool needs_resize() const {
        return (num_occupied + num_deleted + 1) > static_cast<size_t>(buckets.size() * maxLoadFactor);
    }

    void resize(size_t new_capacity) {
        new_capacity = validate_capacity(new_capacity);

        std::vector<Slot> new_buckets(new_capacity);
        std::swap(buckets, new_buckets);

        num_occupied = 0;
        num_deleted = 0;

        for (Slot& slot : new_buckets) {
            if (slot.state != State::Occupied) continue;

            bool found;
            size_t index = find_slot(slot.key, found);
            
            buckets[index].key = std::move(slot.key);
            buckets[index].value = std::move(slot.value);
            buckets[index].state = State::Occupied;
            num_occupied++;
        }
    }

    static size_t validate_capacity(size_t capacity) {
        if (capacity == 0) {
            throw std::invalid_argument("OpenAddressingHashMap::validate_capacity: invalid argument `capacity` can't be zero");
        }

        return capacity;
    }

    size_t find_index(const Key& key) const {
        const size_t index = hash_(key);

        for (size_t attempt = 0; attempt < buckets.size(); ++attempt) {
            size_t probe_index = probing_(index, attempt, buckets.size());
            const Slot& slot = buckets[probe_index];

            if (slot.state == State::Empty) return npos;
            if (slot.state == State::Occupied && equal_to_(slot.key, key)) return probe_index;
        }

        return npos;
    }

    size_t find_slot(const Key& key, bool& found) const {
        const size_t index = hash_(key);
        size_t deleted = npos;

        for (size_t attempt = 0; attempt < buckets.size(); ++attempt) {
            size_t probe_index = probing_(index, attempt, buckets.size());
            const Slot& slot = buckets[probe_index];

            if (slot.state == State::Empty) {
                found = false;
                return deleted != npos ? deleted : probe_index;
            }

            if (slot.state == State::Deleted) {
                if (deleted == npos) deleted = probe_index;
                continue;
            }

            if (equal_to_(slot.key, key)) {
                found = true;
                return probe_index;
            }
        }

        found = false;
        return deleted;
    }

public:
    explicit OpenAddressingHashMap(size_t capacity = 16) 
    : buckets(validate_capacity(capacity)),
    num_occupied(0),
    num_deleted(0),
    maxLoadFactor(0.75)
    {       
    }

    Value& operator[](const Key& key) {
        size_t index = find_index(key);
        
        if (index != npos) return buckets[index].value;

        insert(key, Value());
        return buckets[find_index(key)].value;
    }

    void insert(const Key& key, const Value& value) {
        bool found;
        size_t index = find_slot(key, found);
        
        if (found) {
            buckets[index].value = value;
            return;
        }

        if (index == npos || needs_resize()) {
            resize(buckets.size() * 2);
            index = find_slot(key, found);
        }

        Slot& slot = buckets[index];
        if (slot.state == State::Deleted) --num_deleted;

        slot.key = key;
        slot.value = value;
        slot.state = State::Occupied;
        num_occupied++;
    }

    bool remove(const Key& key) {
        bool found;
        size_t index = find_slot(key, found);
        
        if (found) {
            buckets[index].state = State::Deleted;
            num_occupied--;
            num_deleted++;
            return true;
        }

        return false;
    }

    bool replace(const Key& key, const Value& value) {
        bool found;
        size_t index = find_slot(key, found);
        
        if (found) {
            buckets[index].value = value;
            return true;
        }
        
        return false;
    }
    
    bool contains_key(const Key& key) const {
        bool found;
        find_slot(key, found);

        return found;
    }
    
    bool contains_value(const Value& value) const {
        for (const Slot& slot : buckets) {
            if (slot.state == State::Occupied && slot.value == value) {
                return true;
            }
        }

        return false;
    }
    
    const Value& get(const Key& key) const {
        bool found;
        size_t index = find_slot(key, found);
        
        if (found) {
            return buckets[index].value;
        }

        throw std::out_of_range("OpenAddressingHashMap::get: key not exists");
    }

    size_t get_size() const { 
        return num_occupied; 
    }

    bool empty() const { 
        return num_occupied == 0; 
    }
    
    void clear() {
        for (Slot& slot : buckets) {
            slot.state = State::Empty;
        }

        num_occupied = 0;
        num_deleted = 0;
    }

    double load_factor() const {
        return static_cast<double>(num_occupied + num_deleted) / buckets.size();
    }

    double max_load_factor() const { 
        return maxLoadFactor; 
    }
    
    void max_load_factor(double value) { 
        if (value <= 0.0 || value >= 1.0) {
            throw std::invalid_argument("OpenAddressingHashMap::max_load_factor: invalid argument `value` must be in the range (0.0, 1.0)");
        }
        
        maxLoadFactor = value; 
    }

    friend std::ostream& operator<<(std::ostream& os, const OpenAddressingHashMap& map) {
        os << "{";
 
        bool first = true;
 
        for (const Slot& slot : map.buckets) {
            if (slot.state != State::Occupied) continue;
 
            if (!first) {
                os << ", ";
            }
 
            os << slot.key << ": " << slot.value;
 
            first = false;
        }
 
        os << "}";
 
        return os;
    }

};

template <typename K, typename V,
    typename H = std::hash<K>, typename E = std::equal_to<K>>
using LinearProbingHashMap = OpenAddressingHashMap<K, V, LinearProbing, H, E>;

template <typename K, typename V,
    typename H = std::hash<K>, typename E = std::equal_to<K>>
using QuadraticProbingHashMap = OpenAddressingHashMap<K, V, QuadraticProbing, H, E>;
