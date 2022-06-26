#pragma once

#include <string>
#include <unordered_map>
#include "TestClassBase.hpp"

class Ch1_4_PalindromePermutation
{
public:
	Ch1_4_PalindromePermutation()
	{}

	~Ch1_4_PalindromePermutation()
	{}

	bool Solution(std::string str) 
	{
		bool canBePalindromePermutation = false;

		std::unordered_map<char, int> charCount;
		unsigned int len = str.size();
		for(int i = 0; i < len; i++){
			bool isCapital = false;
			if(IsLetter(str[i], isCapital)){
				if(isCapital){
					char lowerCase = TransCapital2LowerCase(str[i]);
					charCount[TransCapital2LowerCase(str[i])]++;
				}
				else{
					charCount[str[i]]++;
				}
			}
		}

		int amountOfOnlyNotEqualEven = 0;
		for(const auto& ele : charCount){
			if(ele.second & 1){
				amountOfOnlyNotEqualEven = amountOfOnlyNotEqualEven + 1;
			}
		}

		if(amountOfOnlyNotEqualEven > 1){
			canBePalindromePermutation = false;
		}
		else{
			canBePalindromePermutation = true;
		}

		return canBePalindromePermutation;
	}

private:

	bool IsLetter(char a, bool &isCapital)
	{
		bool isLetter = false;
		isCapital = false;

		if(a >= 65 && a <= 90) {
			isLetter = true;
			isCapital = true;
		}
		else if(a >= 97 && a <= 122){
			isLetter = true;
			isCapital = false;
		}
		else{
			isLetter = false;
			isCapital = false;
		}

		return isLetter;
	}

	char TransCapital2LowerCase(char capital)
	{
		return capital + (char)32;
	}
};

class Ch1_4_PalindromePermutation_Test: public TestClassBase
{
public:
	Ch1_4_PalindromePermutation_Test()
	{}

	~Ch1_4_PalindromePermutation_Test()
	{}

	void Test() override
	{
		this->TestInput_TactCoa_returnTrue();

		this->TestInput_Aaabcd_returnFalse();
	}

private:
	Ch1_4_PalindromePermutation mAlgorithm;

	void TestInput_TactCoa_returnTrue()
	{
		std::string input = "Tact Coa";

		bool result = this->mAlgorithm.Solution(input);
		Assert(result == true, "%s is palindrome after permutaion.", input.c_str());
	}

	void TestInput_Aaabcd_returnFalse()
	{
		std::string input = "Aaabcd";

		bool result = this->mAlgorithm.Solution(input);
		Assert(result == false, "%s is not palindrome after permutaion.", input.c_str());
	}
};