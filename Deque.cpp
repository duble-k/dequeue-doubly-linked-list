#include <iostream>

#include "Deque.h"

Deque::Deque(int size) {
    max_size = size;
}

void Deque::PushFront(std::string new_key, std::string new_value) {
    if (this->current_size == this->max_size)
    {
        PopBack();
    }
    InsertFront(new_key, new_value);
}

void Deque::PushBack(std::string new_key, std::string new_value) {
    if (this->current_size == this->max_size)
    {
        PopFront();
    }
    InsertBack(new_key, new_value);
}