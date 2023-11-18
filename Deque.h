#include "DoublyLinkedList.h"

class Deque: public DoublyLinkedList {
    private:
        int max_size;
    public:
        Deque(int size);
        void PushFront(std::string key, std::string value);
        void PushBack(std::string key, std::string value);

};