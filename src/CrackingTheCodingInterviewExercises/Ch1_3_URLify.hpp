#pragma once
#include <string>
#include <iostream>
#include <cstring>
#include "TestClassBase.hpp"

class Ch1_3_URLify
{
public:
	Ch1_3_URLify()
	{
		this->REPLACE_STR_LEN = this->REPLACE_STR.size();
	}

	~Ch1_3_URLify()
	{}

	std::string Solution(std::string str, unsigned int trueStrLen) 
	{
		if(trueStrLen > str.size())
			return str;

		std::string ret;

		char* buffer = new char[trueStrLen];
		memset(buffer, 0, trueStrLen);
		int index = 0;
		for(int i = 0; i < trueStrLen; i++){
			if(str[i] == TARGET_CHAR){
				memcpy(buffer + index, this->REPLACE_STR.c_str(), this->REPLACE_STR_LEN);
				index = index + this->REPLACE_STR_LEN;
			}
			else{
				*(buffer + index) = str[i];
				index = index + 1;
			}
		}
		ret = buffer;
		delete [] buffer;
		std::cout << ret << std::endl;

		return ret;
	}

private:
	const std::string REPLACE_STR = "\%20";
	int REPLACE_STR_LEN = 0;
	const char TARGET_CHAR = ' ';
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

		this->TestInput_StrShorterThanTrueStrLenAndReturnSameStr();
	}

private:
	Ch1_3_URLify mAlgorithm;

	void TestInput_MrJohnSmith()
	{
		std::string input = "Mr John Smith     ";

		std::string result = this->mAlgorithm.Solution(input, 13);
		Assert(result == "Mr\%20John\%20Smith", result);
	}

	void TestInput_StrShorterThanTrueStrLenAndReturnSameStr()
	{
		std::string input = "Mr John Smith     ";

		std::string result = this->mAlgorithm.Solution(input, 30);
		Assert(result == input, result);
	}
};