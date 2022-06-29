#pragma once

#include <iostream>
#include "AssertClass.hpp"
#include "LinkList.hpp"

#define TEST_DATA_LEN (10)

class TestLinkList
{
public:
	TestLinkList()
	{
		InitializeTestData(this->mTestData, TEST_DATA_LEN);
	}

	~TestLinkList()
	{}

	void TestPushBack()
	{
		std::cout << "\n\n===== Testing PushBack =====" << std::endl;
		LinkList<int> linkList;
		
		for(int i = 0; i < 5; i++)
			linkList.PushBack(this->mTestData[i]);

		AssertClass::GetInstance().Assert(linkList.IsEmpty() == false, "Link list has element");
		AssertClass::GetInstance().Assert(linkList.Length() == 5, "Link list length");
		for(int i = 0; i < 5; i++)
			AssertClass::GetInstance().Assert(linkList[i] == this->mTestData[i], "%d-th element value = %d", i, linkList[i]);
	}

	void TestPushFront()
	{
		std::cout << "\n\n===== Testing PushFront =====" << std::endl;
		LinkList<int> linkList;

		int i = 0;
		for(; i < 5; i++)
			linkList.PushBack(this->mTestData[i]);
		
		linkList.PushFront(this->mTestData[i]);

		AssertClass::GetInstance().Assert(linkList.IsEmpty() == false, "Link list has element");
		AssertClass::GetInstance().Assert(linkList.Length() == 6, "Link list length");
		AssertClass::GetInstance().Assert(linkList[0] == this->mTestData[i], "%d-th element value = %d", 0, linkList[0]);
		for(int j = 0; j < 5; j++)
			AssertClass::GetInstance().Assert(linkList[j + 1] == this->mTestData[j], "%d-th element value = %d", j + 1, linkList[j + 1]);
	}

	void TestPopBack()
	{
		std::cout << "\n\n===== Testing PopBack =====" << std::endl;
		LinkList<int> linkList;
		
		for(int i = 0; i < 5; i++)
			linkList.PushBack(this->mTestData[i]);
		AssertClass::GetInstance().Assert(linkList.Length() == 5, "After initialized, length = %d", linkList.Length());
		
		linkList.PopBack();
		AssertClass::GetInstance().Assert(linkList.Length() == 4, "After PopBack, length = %d", linkList.Length());
		for(int i = 0; i < linkList.Length(); i++)
			AssertClass::GetInstance().Assert(linkList[i] == this->mTestData[i], "%d-th element value = %d", i, linkList[i]);
	}

	void TestPopFront()
	{
		std::cout << "\n\n===== Testing PopFront =====" << std::endl;
		LinkList<int> linkList;
		
		for(int i = 0; i < 5; i++)
			linkList.PushBack(this->mTestData[i]);
		AssertClass::GetInstance().Assert(linkList.Length() == 5, "After initialized, length = %d", linkList.Length());
		
		linkList.PopFront();
		AssertClass::GetInstance().Assert(linkList.Length() == 4, "After PopBack, length = %d", linkList.Length());
		for(int i = 0; i < linkList.Length(); i++)
			AssertClass::GetInstance().Assert(linkList[i] == this->mTestData[i + 1], "%d-th element value = %d", i, linkList[i]);
	}

private:
	int mTestData[TEST_DATA_LEN];

	void InitializeTestData(int *arr, int count)
	{
		for(int i = 0; i < count; i++){
			*(arr + i) = i + 5;
		}
	}
};