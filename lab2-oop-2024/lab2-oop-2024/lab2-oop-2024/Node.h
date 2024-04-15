#pragma once
#include <concepts>

template <typename T> requires std::default_initializable<T>
class Node
{
private:
	T data;
	Node* prev;
	Node* next;
public:
	Node(T data) : data(data), prev(nullptr), next(nullptr) {}
	T getData() { return data; }
	Node* getPrev() { return prev; }
	Node* getNext() { return next; }
	void setData(T value) { data = value; }
	void setPrev(Node* value) { prev = value; }
	void setNext(Node* value) { next = value; }
};

