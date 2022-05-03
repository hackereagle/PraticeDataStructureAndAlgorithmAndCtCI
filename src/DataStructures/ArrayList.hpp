#pragma once
#include <iostream>
#include <cstring>

template <class T>
class ArrayList
{
public:
	ArrayList()
	{
		this->mCapacity = 1;
		this->mSize = 0;
	}

	~ArrayList()
	{}

	size_t Size() const
	{
		return this->mSize;
	}

	size_t Capacity() const
	{
		return this->mCapacity;
	}

	void PushBack(T ele)
	{
		if(this->mData == nullptr){
			this->mCapacity = 2;
			this->mSize = 1;
			this->mData = new T;
			*this->mData = ele;
		}
		else if(this->mSize + 1 == this->mCapacity){
			this->mCapacity = this->mCapacity * 2;
			T* tempPtr = this->mData;
			this->mData = new T[this->mCapacity]{0};
			memcpy(this->mData, tempPtr, sizeof(T) * this->mSize);
			*(this->mData + this->mSize) = ele;
			this->mSize = this->mSize + 1;
			this->mBegin = this->mData;
			this->mEnd = this->mData + this->mSize - 1;
		}
		else{
			*(this->mData + this->mSize) = ele;
			this->mSize = this->mSize + 1;
			this->mEnd = this->mData + this->mSize - 1;
		}
	}
	
	T PopBack()
	{
		T ret = *(this->mData + this->mSize - 1);
		this->mSize = this->mSize - 1;
		return ret;
	}

	T operator[](size_t i)
	{
		if(i > this->mSize)
			throw std::out_of_range("ArrayList");
		return *(this->mData + i);
	}

private:
	T* mData = nullptr;
	T* mBegin = nullptr;
	T* mEnd = nullptr;
	size_t mSize;
	size_t mCapacity;
};