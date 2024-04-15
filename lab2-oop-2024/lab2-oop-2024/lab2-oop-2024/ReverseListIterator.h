#pragma once
#include "Iterator.h"
template <typename T>
class ReverseListIterator :
    public Iterator<T>
{
public:
    ReverseListIterator(Node<T>* current = nullptr) : Iterator<T>(current) {}
    Node<T>* getNext() override
    {
        if (!hasMore())
            return nullptr;
        Node<T>* result = Iterator<T>::current;
        Iterator<T>::current = Iterator<T>::current->getPrev();
        return result;
    }
    bool hasMore() const override
    {
        return Iterator<T>::current != nullptr;
    }
};

