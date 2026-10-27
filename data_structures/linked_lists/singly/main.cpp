
#include "singly_linked_list.hpp"

#include <iostream>

int main() {
    SinglyLinkedList list = {10, 20, 30};

    std::cout << "Initial list: " << list << '\n';

    list.add_first(5);
    std::cout << "After add_first(5): " << list << '\n';

    list.add(15, 2);
    std::cout << "After add(15, 2): " << list << '\n';

    list.add_last(40);
    std::cout << "After add_last(40): " << list << '\n';

    std::cout << "Element at index 2: " << list.get(2) << '\n';
    std::cout << "First element: " << list.get_first() << '\n';
    std::cout << "Last element: " << list.get_last() << '\n';
    std::cout << "Size: " << list.get_size() << '\n';

    list.remove(2);
    std::cout << "After remove(2): " << list << '\n';

    list.remove_first();
    std::cout << "After remove_first(): " << list << '\n';

    list.remove_last();
    std::cout << "After remove_last(): " << list << '\n';

    list.clear();
    std::cout << "After clear(): " << list << '\n';
    std::cout << "Empty: " << std::boolalpha << list.empty() << '\n';

    list.add(99);
    std::cout << "After adding to empty list: " << list << '\n';

    return 0;
}
