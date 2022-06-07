#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include "TestClassBase.hpp"

class Ch1_2_CheckPermutation
{
public:
	Ch1_2_CheckPermutation()
	{}

	~Ch1_2_CheckPermutation()
	{}

	bool Solution(std::string S1, std::string S2)
	{
		bool isPermutation = false;
		std::unordered_map<char, int> S1_charCountTable; 
		std::unordered_map<char, int> S2_charCountTable; 

		if(S1.size() == S2.size()){
			size_t len = S1.size();
			for(int i = 0; i < len; i++){
				S1_charCountTable[S1[i]]++;
				S2_charCountTable[S2[i]]++;
			}

			for(auto it = S1_charCountTable.begin(); it != S1_charCountTable.end(); it++){
				std::unordered_map<char, int>::iterator it2 = S2_charCountTable.find(it->first);
				if(it2 != S2_charCountTable.end()){
					if(it2->second == it->second){
						isPermutation = true;
					}
					else{
						isPermutation = false;
						break;
					}
				}
				else{
					isPermutation = false;
					break;
				}
			}
		}

		return isPermutation;
	}

private:
};

class Ch1_2_CheckPermutation_Test: public TestClassBase
{
public:
	Ch1_2_CheckPermutation_Test()
	{
		mSolution = std::make_unique<Ch1_2_CheckPermutation>();
	}

	~Ch1_2_CheckPermutation_Test()
	{}

	void Test() override
	{
		Test_abcdefg_defabcg_true();

		Test_abcDAfg_defabcg_false();
	}

private:
	std::unique_ptr<Ch1_2_CheckPermutation> mSolution;

	void Test_abcdefg_defabcg_true()
	{
		PrintfTestTitle("Check  \"abcdefg\" and  \"defabcg\" result is true.");
		std::string S1 = "abcdefg";
		std::string S2 = "defabcg";
	
		bool result = this->mSolution->Solution(S1, S2);
		Assert(result);
	}

	void Test_abcDAfg_defabcg_false()
	{
		PrintfTestTitle("Check  \"abcDAfg\" and  \"defabcg\" result is false.");
		std::string S1 = "abcDAfg";
		std::string S2 = "defabcg";
	
		bool result = this->mSolution->Solution(S1, S2);
		Assert(!result);

	}

};