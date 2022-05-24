#pragma once
#include <iostream>

template<class T>
class Node
{
public:
	Node(T data)
	{
		this->Data = data;
		this->Previous = nullptr;
		this->Next = nullptr;
	}

	Node(T data, Node<T>* pre)
	{
		this->Data = data;
		this->Previous = pre;
		this->Next = nullptr;
	}

	Node(T data, Node<T>* pre, Node<T>* next)
	{
		this->Data = data;
		this->Previous = pre;
		this->Next = next;
	}

	~Node()
	{}

	T Data;
	Node<T>* Next;
	Node<T>* Previous;
};

template<class T>
class LinkList
{
public:
	LinkList()
	{
		this->mHead = nullptr;
		this->mTail = nullptr;
	}

	~LinkList()
	{
		if(this->mHead){
			Node<T>* temp;
			while(!this->mHead->Next){
				temp = this->mHead->Next;
				delete this->mHead;
				this->mHead = temp;
			}
			delete this->mHead;

			this->mHead = nullptr;
			this->mTail = nullptr;
		}
	}


	void PushBack(T data)
	{
		if(!this->mHead){
			this->mHead = new Node<T>(data);
			this->mTail = this->mHead;
		}
		else{
			this->mTail->Next = new Node<T>(data);
			this->mTail = this->mTail->Next;
		}
	}

	void PushFront(T data)
	{
		this->mHead = new Node<T>(data, this->mHead);
	}

	void PopBack(T data)
	{
		T ret;
		ret = this->mTail->Data;
	}

	void PopFront(T data)
	{

	}

	bool IsEmpty()
	{}

	void Reverse()
	{}

	T operator[](unsigned int index)
	{}

	size_t Length() { return this->mLength; }


private:
	Node<T>* mHead;
	Node<T>* mTail;
	Node<T>* mCurrent;
	size_t mLength;
};