#pragma once
#include <iostream>

#include "Subscriber.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

class Publisher;

template <typename T>
class ListPrinter :
	public Subscriber
{
public:
	void update(const Publisher* publisher) const override
	{
		const SinglyLinkedList<T>* sll = dynamic_cast<const SinglyLinkedList<T>*>(publisher);
		const DoublyLinkedList<T>* dll = dynamic_cast<const DoublyLinkedList<T>*>(publisher);
		if (sll != nullptr)
		{
			for (ListIterator<int> iter = sll->createIterator(); iter.hasMore(); iter.getNext())
			{
				std::cout << (*iter)->getData() << " ";
			}
			std::cout << std::endl;
		}
		else if (dll != nullptr)
		{
			for (ListIterator<int> iter = dll->createIterator(); iter.hasMore(); iter.getNext())
			{
				std::cout << (*iter)->getData() << " ";
			}
			std::cout << std::endl;
		}
	}
};

