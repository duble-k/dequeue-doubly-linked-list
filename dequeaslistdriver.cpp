#include <iostream>
#include <sstream>
#include <string>

#include "Deque.h"

int main()
{
    std::string inpt;
    inpt = "";

    Deque *deque;

    while (true)
    {
        std::string command;
        std::string url_name;
        std::string url;
        int size;

        std::getline(std::cin, inpt);
        std::stringstream strm(inpt);

        strm >> command;

        if (command == "exit")
        {
            break;
        }
        if (command == "m")
        {
            strm >> size;
            deque = new Deque(size);
            std::cout << "success" << std::endl;
        }
        if (command == "push_front")
        {
            strm >> url_name;
            strm >> url;
            deque->PushFront(url_name, url);
            std::cout << "success" << std::endl;
        }
        if (command == "push_back")
        {
            strm >> url_name;
            strm >> url;
            deque->PushBack(url_name, url);
            std::cout << "success" << std::endl;
        }
        if (command == "pop_front")
        {
            bool result = deque->PopFront();
            if (result)
            {
                std::cout << "success" << std::endl;
            }
            else
            {
                std::cout << "failure" << std::endl;
            }
        }
        if (command == "pop_back")
        {
            bool result = deque->PopBack();
            if (result)
            {
                std::cout << "success" << std::endl;
            }
            else
            {
                std::cout << "failure" << std::endl;
            }
        }
        if (command == "clear")
        {
            deque->Clear();
            std::cout << "success" << std::endl;
        }
        if (command == "size")
        {
            std::cout << "size is " << deque->Size() << std::endl;
        }
        if (command == "front")
        {
            Node *temp = deque->Front();
            if (temp == NULL)
            {
                std::cout << "failure" << std::endl;
            }
            else
            {
                std::cout << "front is " << temp->key << " " << temp->value << std::endl;
            }
        }
        if (command == "back")
        {
            Node *temp = deque->Back();
            if (temp == NULL)
            {
                std::cout << "failure" << std::endl;
            }
            else
            {
                std::cout << "back is " << temp->key << " " << temp->value << std::endl;
            }
        }
        if (command == "empty")
        {
            bool result = deque->Empty();
            if (result)
            {
                std::cout << "empty 1" << std::endl;
            }
            else
            {
                std::cout << "empty 0" << std::endl;
            }
        }
        if (command == "find")
        {
            strm >> url_name;
            std::string result = deque->Find(url_name);
            if (result != "none")
            {
                std::cout << "found " << url_name << " " << result << std::endl;
            }
            else
            {
                std::cout << "not found " << url_name << std::endl;
            }
        }
        if (command == "print")
        {
            deque->Print();
        }
    }

    return 0;
}