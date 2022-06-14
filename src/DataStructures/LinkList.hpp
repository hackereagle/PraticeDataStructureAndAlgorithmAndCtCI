#pragma once

#include <iostream>
#include "CommonFunction.hpp"

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
		this->mLength = this->mLength + 1;
	}

	void PushFront(T data)
	{
		this->mHead = new Node<T>(data, this->mHead);
		this->mLength = this->mLength + 1;
	}

	void PopBack(T data)
	{
		Node<T> *last = this->mTail;
		this->mTail = this->mTail->Previous;
		delete last;
		this->mLength = this->mLength - 1;
	}

	void PopFront(T data)
	{
		Node<T> *first = this->mHead;
		this->mHead = this->mHead->Next;
		delete first;
		this->mLength = this->mLength - 1;
	}

	bool IsEmpty()
	{
		return mHead == nullptr;
	}

	void Reverse()
	{
		this->mTail = this->mHead;
		SWAP(this->mHead->Previous, this->mHead->Next);
		while(this->mHead->Previous != nullptr){
			this->mHead = this->mHead->Previous;
			SWAP(this->mHead->Previous, this->mHead->Next);
		}
	}

	T operator[](unsigned int index)
	{
		if(index > mLength){
			throw std::out_of_range("ArrayList");
		}

		Node<T> *_head = nullptr;
		int delta = (int)this->mCurIndex - (int)index;
		if(delta > 0){
			int delta2 = index - 0;
			if(delta2 > delta){
				while(delta > 0){
					this->mCurrent = this->mCurrent->Previous;
					delta--;
				}
			}
			else{
				this->mCurrent = mHead;
				while (delta2 > 0) {
					this->mCurrent = this->mCurrent->Next;
					delta2--;
				}
			}
				
		}
		else{
			int delta2 = this->mLength - index - 1;
			delta = Abs(delta);
			if(delta2 > delta){
				while(delta > 0){
					this->mCurrent = this->mCurrent->Previous;
					delta--;
				}
			}
			else{
				this->mCurrent = mTail;
				while (delta2 > 0) {
					this->mCurrent = this->mCurrent->Next;
					delta2--;
				}
			}
		}

		this->mCurIndex = index;
		return this->mCurrent->Data;
	}

	size_t Length() { return this->mLength; }


private:
	Node<T>* mHead = nullptr;
	Node<T>* mTail = nullptr;
	Node<T>* mCurrent = nullptr;
	unsigned int mCurIndex = 0;
	size_t mLength = 0;
};