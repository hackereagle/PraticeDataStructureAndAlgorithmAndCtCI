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
		LinkList<int> linkList;

		int i = 0;
		for(; i < 5; i++)
			linkList.PushBack(this->mTestData[i]);
		
		linkList.PushFront(this->mTestData[i]);

		AssertClass::GetInstance().Assert(linkList.IsEmpty() == false, "Link list has element");
		AssertClass::GetInstance().Assert(linkList.Length() == 6, "Link list length");
		AssertClass::GetInstance().Assert(linkList[0] == this->mTestData[i], "%d-th element value = %d", 0, linkList[0]);
		for(int j = 0; j < 5; j++)
			AssertClass::GetInstance().Assert(linkList[j + 1] == this->mTestData[j], "%d-th element value = %d", j + 1, linkList[j]);
	}

	void TestPopBack()
	{

	}

	void TestPopFront()
	{

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