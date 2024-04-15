#pragma once
#include "List.h"
#include "ListIterator.h"
#include "ReverseListIterator.h"
#include "Prototype.h"

template <typename T>
class DoublyLinkedList :
    public List<T>,
	public Prototype<DoublyLinkedList<T>>
{
private:
	Node<T>* tail;
public:
	DoublyLinkedList() : tail(nullptr) {}
	void pushBack(T item) override
	{
		if (List<T>::head == nullptr)
		{
			List<T>::head = tail = new Node<T>(item);
		}
		else
		{
			tail->setNext(new Node<T>(item));
			tail->getNext()->setPrev(tail);
			tail = tail->getNext();
		}
		List<T>::length++;
		Publisher::notify();
	}
	void pushFront(T item) override
	{
		if (List<T>::head == nullptr)
		{
			List<T>::head = tail = new Node<T>(item);
		}
		else
		{
			List<T>::head->setPrev(new Node<T>(item));
			List<T>::head->getPrev()->setNext(List<T>::head);
			List<T>::head = List<T>::head->getPrev();
		}
		Publisher::notify();
	}
	T popBack() override
	{
		if (List<T>::length == 0)
		{
			throw;
		}
		T item;
		if (List<T>::length == 1)
		{
			item = List<T>::head->getData();
			delete List<T>::head;
			List<T>::head = tail = nullptr;
		}
		else
		{
			item = tail->getData();
			tail = tail->getPrev();
			delete tail->getNext();
			tail->setNext(nullptr);
		}
		List<T>::length--;
		Publisher::notify();
		return item;
	}
	T popFront() override
	{
		if (List<T>::length == 0)
		{
			throw;
		}
		T item;
		if (List<T>::length == 1)
		{
			item = List<T>::head->getData();
			delete List<T>::head;
			List<T>::head = tail = nullptr;
		}
		else
		{
			item = List<T>::head->getData();
			List<T>::head = List<T>::head->getNext();
			delete List<T>::head->getPrev();
			List<T>::head->setPrev(nullptr);
		}
		List<T>::length--;
		Publisher::notify();
		return item;
	}
	ListIterator<T> createIterator() const
	{
		return ListIterator<T>(List<T>::head);
	}
	ReverseListIterator<T> createReverseIterator() const
	{
		return ReverseListIterator<T>(tail);
	}
	DoublyLinkedList clone() const override
	{
		DoublyLinkedList<T> result;
		for (ListIterator<T> iter = this->createIterator(); iter.hasMore(); iter.getNext())
		{
			result.pushBack((*iter)->getData());
		}
		return result;
	}
};

