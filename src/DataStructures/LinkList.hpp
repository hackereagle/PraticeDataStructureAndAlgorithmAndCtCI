#pragma once

template<class T>
class Node
{
public:
	Node(T data)
	{}

	~Node()
	{}

private:
	T mData;
	Node<T>* mNext;
};