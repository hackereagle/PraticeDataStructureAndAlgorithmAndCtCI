#include <cstring>
#include "ArrayList.hpp"

template <typename T>
ArrayList<T>::ArrayList()
{
	this->mCapacity = 1;
	this->mSize = 0;
}

template <typename T>
ArrayList<T>::~ArrayList()
{}

template <typename T>
size_t ArrayList<T>::Size() const
{
	return this->mSize;
}

template <typename T>
size_t ArrayList<T>::Capacity() const
{
	return this->mCapacity;
}

template <typename T>
void ArrayList<T>::PushBack(T ele)
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

template <typename T>
void ArrayList<T>::PopBack(T ele)
{}

template <typename T>
T ArrayList<T>::operator[](size_t i)
{
	if(i > this->mSize)
		throw std::out_of_range("ArrayList");
	return *(this->mData + i)
}