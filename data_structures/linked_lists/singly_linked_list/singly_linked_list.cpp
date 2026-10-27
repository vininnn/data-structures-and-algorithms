#include "singly_linked_list.hpp"

#include <stdexcept>
#include <ostream>

SinglyLinkedList::SinglyLinkedList()
    : head(nullptr),
    tail(nullptr),
    size(0)
{
}

SinglyLinkedList::SinglyLinkedList(std::initializer_list<int> values) 
    : SinglyLinkedList() 
{
    for (int value : values) {
        add_last(value);
    }
}

SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

int SinglyLinkedList::get(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("SinglyLinkedList::get: index out of range");
    }

    if (index == 0) {
        return get_first();
    }    
    
    if (index == size - 1) {
        return get_last();
    }   

    Node* current = head;
    for (size_t current_index = 0; current_index < index; current_index++) {
        current = current->next;
    }

    return current->value;
}

int SinglyLinkedList::get_first() const {
    if (empty()) {
        throw std::logic_error("SinglyLinkedList::get_first: list is empty");
    }

    return head->value;
}

int SinglyLinkedList::get_last() const {
    if (empty()) {
        throw std::logic_error("SinglyLinkedList::get_last: list is empty");
    }

    return tail->value;
}

void SinglyLinkedList::add(int value) {
    add_last(value);
}

void SinglyLinkedList::add(int value, size_t index) {
    if (index > size) {
        throw std::out_of_range("SinglyLinkedList::add: index out of range");
    }
    
    if (index == 0) {
        add_first(value);
        return;
    }    
    
    if (index == size) {
        add_last(value);
        return;
    }    

    Node* current = head;
    for (size_t current_index = 0; current_index < index - 1; current_index++) {
        current = current->next;
    }

    Node* node = new Node(value);
    node->next = current->next;
    current->next = node;

    size++;
}

void SinglyLinkedList::add_first(int value) {
    Node* node = new Node(value);

    if (empty()) {
        head = node;
        tail = node;
    } else {
        node->next = head;
        head = node;
    }

    size++;
}

void SinglyLinkedList::add_last(int value) {
    Node* node = new Node(value);

    if (empty()) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }

    size++;
}

void SinglyLinkedList::remove() {
    remove_last();
}

void SinglyLinkedList::remove(size_t index) {
    if (empty()) {
        throw std::logic_error("SinglyLinkedList::remove_first: list is empty"
        );
    }
    
    if (index >= size) {
        throw std::out_of_range("SinglyLinkedList::remove: index out of range");
    }
    
    if (index == 0) {
        remove_first();
        return;
    }    
    
    if (index == size - 1) {
        remove_last();
        return;
    }    

    Node* current = head;
    for (size_t current_index = 0; current_index < index - 1; current_index++) {
        current = current->next;
    }

    Node* toDelete = current->next;
    current->next = current->next->next;
    delete toDelete;

    size--;
}

void SinglyLinkedList::remove_first() {
    if (empty()) {
        throw std::logic_error("SinglyLinkedList::remove_first: list is empty"
        );
    }

    Node* current = head;
    head = head->next;

    delete current;
    size--;

    if (head == nullptr) {
        tail = nullptr;
    }
}

void SinglyLinkedList::remove_last() {
    if (empty()) {
        throw std::logic_error("SinglyLinkedList::remove_last: list is empty"
        );
    }

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }

    Node* current = head;

    while (current->next != tail) {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr;
    
    size--;
}

size_t SinglyLinkedList::get_size() const {
    return size;
}

bool SinglyLinkedList::empty() const {
    return size == 0;
}

void SinglyLinkedList::clear() {
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}

std::ostream& operator<<(
    std::ostream& os,
    const SinglyLinkedList& list
) {
    os << "[";

    SinglyLinkedList::Node* current = list.head;

    while (current != nullptr) {
        os << current->value;
        current = current->next;

        if (current != nullptr) {
            os << ", ";
        }
    }

    os << "]";
    return os;
}