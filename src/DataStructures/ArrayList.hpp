#pragma once
#include <iostream>

template <class T>
class ArrayList
{
public:
	ArrayList();
	~ArrayList();
	size_t Size() const;
	size_t Capacity() const;
	void PushBack(T ele);
	void PopBack(T ele);
	T operator[](size_t i);

private:
	T* mData = nullptr;
	T* mBegin = nullptr;
	T* mEnd = nullptr;
	size_t mSize;
	size_t mCapacity;
};