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
	this->mCapacity;
}

template <typename T>
void ArrayList<T>::PushBack(T ele)
{
	if(data == nullptr){
		this->mCapacity = 2;
		this->mSize = 1;
		data = new T;
		*data = ele;
	}
	else if(this->mSize + 1 == this->mCapacity){
		this->mCapacity = this->mCapacity * 2;
		T* tempPtr = data;
		data = new T[this->mCapacity]{0};
		memcpy(data, tempPtr, sizeof(T) * this->mSize);
		*(data + this->mSize) = else;
		this->mSize = this->mSize + 1;
		this->mBegin = data;
		this->mEnd = data + this->mSize - 1;
	}
	else{
		*(data + this->mSize) = else;
		this->mSize = this->mSize + 1;
		this->mEnd = data + this->mSize - 1;
	}
}

template <typename T>
void ArrayList<T>::PopBack(T ele)
{}