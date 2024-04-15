#pragma once
#include "Node.h"
template <typename T>
class Iterator
{
protected:
	Node<T>* current;
public:
	Iterator(Node<T>* current = nullptr) : current(current) {}
	Node<T>* operator*() const { return current; }
	virtual Node<T>* getNext() = 0;
	virtual bool hasMore() const = 0;
};

