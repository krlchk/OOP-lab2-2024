#pragma once
#include "Node.h"
#include "Iterator.h"
#include "Publisher.h"
#include "SortStrategy.h"

template <typename T>
class List :
	public Publisher
{
	template <typename T> friend class SortStrategy;
protected:
	Node<T>* head;
	size_t length;
	SortStrategy<T>* sortStrategy = nullptr;
public:
	List() : head(nullptr), length(0) {}
	virtual void pushBack(T item) = 0;
	virtual void pushFront(T item) = 0;
	virtual T popBack() = 0;
	virtual T popFront() = 0;
	size_t getLength() { return length; }
	void changeSortStrategy(SortStrategy<T>* sortStrategy)
	{
		this->sortStrategy = sortStrategy;
	}
	void sort()
	{
		if (sortStrategy != nullptr)
		{
			sortStrategy->dataHead = head;
			sortStrategy->sort();
			Publisher::notify();
		}
	}
};

