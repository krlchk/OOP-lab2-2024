#pragma once
#include "List.h"
#include "ListIterator.h"
#include "Prototype.h"

template <typename T> class SinglyLinkedList;

template <typename T>
class SinglyLinkedList :
    public List<T>,
	public Prototype<SinglyLinkedList<T>>
{
public:
	void pushBack(T item) override
	{
		if (List<T>::head == nullptr)
		{
			List<T>::head = new Node<T>(item);
		}
		else
		{
			Node<T>* temp = List<T>::head;
			while (temp->getNext() != nullptr)
			{
				temp = temp->getNext();
			}
			temp->setNext(new Node<T>(item));
		}
		List<T>::length++;
		Publisher::notify();
	}
	void pushFront(T item) override
	{
		if (List<T>::head == nullptr)
		{
			List<T>::head = new Node<T>(item);
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
			List<T>::head = nullptr;
		}
		else
		{
			Node<T>* prev = List<T>::head;
			Node<T>* curr = List<T>::head->getNext();
			while (curr->getNext() != nullptr)
			{
				prev = curr;
				curr = curr->getNext();
			}
			item = curr->getData();
			delete curr;
			prev->setNext(nullptr);
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
			List<T>::head = nullptr;
		}
		else
		{
			item = List<T>::head->getData();
			Node<T>* next = List<T>::head->getNext();
			delete List<T>::head;
			List<T>::head = next;
		}
		List<T>::length--;
		Publisher::notify();
		return item;
	}
	ListIterator<T> createIterator() const
	{
		return ListIterator<T>(List<T>::head);
	}
	SinglyLinkedList<T> clone() const override
	{
		SinglyLinkedList<T> result;
		for (ListIterator<T> iter = this->createIterator(); iter.hasMore(); iter.getNext())
		{
			result.pushBack((*iter)->getData());
		}
		return result;
	}
};

