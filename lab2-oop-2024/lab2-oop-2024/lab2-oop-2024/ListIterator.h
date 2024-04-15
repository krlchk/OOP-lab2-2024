#pragma once
#include "Iterator.h"
#include "Node.h"
template <typename T>
class ListIterator :
    public Iterator<T>
{
public:
    ListIterator(Node<T>* current = nullptr) : Iterator<T>(current) {}
    Node<T>* getNext() override
    {
        if (!hasMore())
            return nullptr;
        Node<T>* result = Iterator<T>::current;
        Iterator<T>::current = Iterator<T>::current->getNext();
        return result;
    }
    bool hasMore() const override
    {
        return Iterator<T>::current != nullptr;
    }
};

