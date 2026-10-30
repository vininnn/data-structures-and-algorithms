#include "separate_chaining_hashmap.hpp"

#include <iostream>

int main() {
    SeparateChainingHashMap map;

    map.insert(1, 100);
    map.insert(2, 200);
    map.insert(3, 300);

    std::cout << "Initial map: " << map << '\n';

    map.insert(4, 400);
    std::cout << "After insert(4, 400): " << map << '\n';

    map[5] = 500;
    std::cout << "After map[5] = 500: " << map << '\n';

    map[1] = 150;
    std::cout << "After map[1] = 150: " << map << '\n';

    std::cout << "Value of key 2: " << map.get(2) << '\n';
    std::cout << "Value of key 3: " << map[3] << '\n';

    std::cout << "Contains key 4: "
              << std::boolalpha << map.contains_key(4) << '\n';

    std::cout << "Contains value 500: "
              << map.contains_value(500) << '\n';

    map.replace(2, 250);
    std::cout << "After replace(2, 250): " << map << '\n';

    map.remove(3);
    std::cout << "After remove(3): " << map << '\n';

    std::cout << "Size: " << map.get_size() << '\n';

    map.clear();
    std::cout << "After clear(): " << map << '\n';
    std::cout << "Empty: " << map.empty() << '\n';

    map[10] = 1000;
    std::cout << "After adding to empty map: " << map << '\n';

    return 0;
}