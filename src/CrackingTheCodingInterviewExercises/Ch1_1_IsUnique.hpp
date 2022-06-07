#pragma once
#include <string>
#include "TestClassBase.hpp"

class Ch1_1_IsUnique
{
public:
	Ch1_1_IsUnique()
	{}

	~Ch1_1_IsUnique()
	{}

	bool Solution(std::string str) 
	{
		bool isUnique = false;

		long long int flags = 0;
		size_t len = str.size();
		for(int i = 0; i < len; i++){
			int index = (int)(str[i] - 'A');
			if(true == GetBit(flags, index)){
				isUnique = false;
				break;
			}
			else{
				flags = SetBit(flags, index);
				isUnique = true;
			}
		}

		return isUnique;
	}

private:

	bool GetBit(long long int num, int bit)
	{
		return num & ((long long int)1 << bit);
	}

	long long int SetBit(long long int num, int bit)
	{
		return num | ((long long int)1 << bit);
	}
};

class Ch1_1_IsUnique_Test: public TestClassBase
{
public:
	Ch1_1_IsUnique_Test()
	{}

	~Ch1_1_IsUnique_Test()
	{}

	void Test() override
	{
		Test_UniqueStr_abcdefghABCDE();

		Test_NotUniqueStr_abcbadeffgh();
	}

private:
	Ch1_1_IsUnique mAlgorithm;

	void Test_UniqueStr_abcdefghABCDE()
	{
		PrintfTestTitle("Test unique string \"abcdefghABCDE\"");
		std::string input = "abcdefghABCDE";

		bool result = mAlgorithm.Solution(input);
		Assert(result);
	}

	void Test_NotUniqueStr_abcbadeffgh()
	{
		PrintfTestTitle("Test unique string \"abcbadeffgh\"");
		std::string input = "abcbadeffgh";

		bool result = mAlgorithm.Solution(input);
		Assert(!result);
	}
};