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
			AssertClass::GetInstance().Assert(linkList[i] == this->mTestData[i]);
	}

	void TestPushFront()
	{
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