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
	{
		std::cout << "\n\n<<<<< Test ArrayList >>>>>" << std::endl;
	}

	~TestArrayList()
	{}

	void TestPushBackElements()
	{
		std::cout << "===== Testing PushBack method =====" << std::endl;

		// begin testing
		for(int i = 0; i < 5; i++){
			this->mArrayList.PushBack(this->mNums[i]);
		}

		// assert
		AssertClass::GetInstance().Assert(this->mArrayList.Capacity() == 8, "Capacity");
		AssertClass::GetInstance().Assert(this->mArrayList.Size() == 5, "size");
		for(int i = 0; i < 5; i++){
			std::ostringstream ss;
			ss << i << "-th element equal!";
			AssertClass::GetInstance().Assert(this->mArrayList[i] == this->mNums[i], ss.str());
		}
	}

	void TestPopBackElements()
	{
		std::cout << "\n\n===== Testing PopBack method =====" << std::endl;

		// begin testing
		int ele1 = this->mArrayList.PopBack();
		int ele2 = this->mArrayList.PopBack();

		// assert
		AssertClass::GetInstance().Assert(this->mArrayList.Capacity() == 8, "Capacity");
		AssertClass::GetInstance().Assert(this->mArrayList.Size() == 3, "size");
		AssertClass::GetInstance().Assert(ele1 == this->mNums[4], "pop first element, it equal to array last element");
		AssertClass::GetInstance().Assert(ele2 == this->mNums[3], "pop second element, it equal to array second last element");
	}

private:
	ArrayList<int> mArrayList;
	int mNums[5]{1, 6, 8, 5, 9};
};
