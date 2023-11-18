#include <iostream>

class Node
{
public:
    std::string key;
    std::string value;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
private:
    Node *ref_head;
    Node *ref_tail;
protected:
    int current_size;
    void InsertFront(std::string new_key, std::string new_vlaue);
    void InsertBack(std::string new_key, std::string new_vlaue);
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    bool PopFront();
    bool PopBack();
    void Clear();
    int Size();
    Node *Front();
    Node *Back();
    bool Empty();
    std::string Find(std::string url_name);
    void Print();
};