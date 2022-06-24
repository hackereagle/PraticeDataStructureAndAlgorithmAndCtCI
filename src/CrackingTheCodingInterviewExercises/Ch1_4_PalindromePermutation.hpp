#pragma once

#include <string>
#include "TestClassBase.hpp"

class Ch1_3_URLify
{
public:
	Ch1_3_URLify()
	{}

	~Ch1_3_URLify()
	{}

	bool Solution(std::string str) 
	{
		bool isPalindromePermutation = false;


		return isPalindromePermutation;
	}

private:
};

class Ch1_3_URLify_Test: public TestClassBase
{
public:
	Ch1_3_URLify_Test()
	{}

	~Ch1_3_URLify_Test()
	{}

	void Test() override
	{
		this->TestInput_MrJohnSmith();
	}

private:
	Ch1_3_URLify mAlgorithm;

	void TestInput_MrJohnSmith()
	{
		std::string input = "Mr John Smith     ";

		std::string result = this->mAlgorithm.Solution(input, 13);
		Assert(result == "Mr\%20John\%20Smith", result);
	}
};