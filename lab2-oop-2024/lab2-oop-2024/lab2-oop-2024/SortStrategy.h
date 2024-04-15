#pragma once
#include "Node.h"

template <typename T>
class SortStrategy
{
	template <typename T> friend class List;
protected:
	Node<T>* dataHead;
public:
	virtual void sort() = 0;
};

