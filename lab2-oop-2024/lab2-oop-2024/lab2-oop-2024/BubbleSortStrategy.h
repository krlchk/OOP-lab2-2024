#pragma once
#include <iostream>
#include "SortStrategy.h"

template <typename T>
class BubbleSortStrategy :
    public SortStrategy<T>
{
public:
    void sort() override
    {
        Node<T>* loopCounter = SortStrategy<T>::dataHead;
        while (loopCounter != nullptr)
        {
            Node<T>* temp = SortStrategy<T>::dataHead;
            while (temp != nullptr && temp->getNext() != nullptr)
            {
                if (temp->getData() > temp->getNext()->getData())
                {
                    T item = temp->getData();
                    temp->setData(temp->getNext()->getData());
                    temp->getNext()->setData(item);
                }
                temp = temp->getNext();
            }
            loopCounter = loopCounter->getNext();
        }
        SortStrategy<T>::dataHead = nullptr;
    }
};

