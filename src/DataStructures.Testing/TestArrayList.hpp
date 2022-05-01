#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "ArrayList.hpp"
#include "AssertClass.hpp"

class TestArrayList
{
public:
	TestArrayList()
	{}

	~TestArrayList()
	{}

	void TestPushElements()
	{
		// created testing data
		int nums[5]{1, 6, 8, 5, 9}; 

		// begin testing
		for(int i = 0; i < 5; i++){
			this->mArrayList.PushBack(nums[i]);
		}

		// assert
		for(int i = 0; i < 5; i++){
			std::ostringstream ss;
			ss << i << "-th element equal!";
			AssertClass::GetInstance().Assert(this->mArrayList[i] == nums[0], ss.str());
		}
	}

private:
	ArrayList<int> mArrayList;
};