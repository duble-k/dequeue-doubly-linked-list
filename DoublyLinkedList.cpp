#include <iostream>

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{

    int current_size = 0;
    Node *ref_head = NULL;
    Node *ref_tail = NULL;
}

void DoublyLinkedList::InsertFront(std::string new_key, std::string new_value)
{

    Node *newNode = new Node();

    newNode->key = new_key;
    newNode->value = new_value;

    if (this->current_size == 0)
    {
        (this->ref_head) = (this->ref_tail) = newNode;
    }
    else
    {
        // Size is 1 or more
        (this->ref_head)->prev = newNode;
        newNode->next = (this->ref_head);
        newNode->prev = NULL;
        (this->ref_head) = newNode;
    }

    this->current_size++;
}

void DoublyLinkedList::InsertBack(std::string new_key, std::string new_value)
{

    Node *newNode = new Node();

    newNode->key = new_key;
    newNode->value = new_value;

    if (this->current_size == 0)
    {
        (this->ref_head) = (this->ref_tail) = newNode;
    }
    else
    {
        // Size is 1 or more
        (this->ref_tail)->next = newNode;
        newNode->prev = (this->ref_tail);
        newNode->next = NULL;
        (this->ref_tail) = newNode;
    }

    this->current_size++;
}

bool DoublyLinkedList::PopFront()
{
    if (this->current_size != 0)
    {
        if (this->current_size == 1)
        {
            delete (this->ref_head);                    // To prevent memory leak / Equivalent to: delete (this->ref_tail);
            (this->ref_head) = (this->ref_tail) = NULL; // To prevent dangling pointers which may cause program crash.
        }
        else
        {
            Node *newHead = (this->ref_head)->next; // Store address of head's previous node because head's node is going to destryoyed.
            delete this->ref_head;                  // To prevent memory leak.
            this->ref_head = newHead;
        }

        this->current_size--;
        return true;
    }
    return false;
}

bool DoublyLinkedList::PopBack()
{
    if (this->current_size != 0)
    {
        if (this->current_size == 1)
        {
            delete (this->ref_head);                    // To prevent memory leak / Equivalent to: delete (this->ref_tail);
            (this->ref_head) = (this->ref_tail) = NULL; // To prevent dangling pointers which may cause program crash.
        }
        else
        {
            Node *newTail = (this->ref_tail)->prev; // Store address of tail's next node because tail's node is going to destryoyed.
            delete this->ref_tail;                  // To prevent memory leak.
            this->ref_tail = newTail;
        }

        this->current_size--;
        return true;
    }
    return false;
}

void DoublyLinkedList::Clear()
{
    if (this->current_size != 0)
    {
        while (this->ref_head != NULL)
        {
            PopFront();
        }
    }
}

int DoublyLinkedList::Size()
{
    return this->current_size;
}

Node *DoublyLinkedList::Front()
{
    return this->ref_head;
}

Node *DoublyLinkedList::Back()
{
    return this->ref_tail;
}

bool DoublyLinkedList::Empty()
{
    return this->current_size == 0 ? true : false;
}

std::string DoublyLinkedList::Find(std::string url_name)
{
    Node *temp = this->ref_head;

    while (temp->next != NULL)
    {
        if (temp->key == url_name)
        {
            return temp->value;
        }

        temp = temp->next;
    }

    return "none";
}

void DoublyLinkedList::Print()
{

    if (this->current_size == 0)
    {
        std::cout << "deque is empty" << std::endl;
    }
    else
    {

        int index = 0;

        Node *temp = ref_tail;

        while (index < current_size)
        {

            std::cout << temp->key << " " << temp->value << std::endl;
            temp = temp->prev;

            index++;
        }
    }
}

DoublyLinkedList::~DoublyLinkedList()
{
    Clear();
}