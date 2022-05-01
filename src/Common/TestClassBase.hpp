#pragma once
#include <iostream>
#include <string>

class TestClassBase
{
public:
	virtual void Test() = 0;

protected:
	void PrintfTestTitle(std::string title)
	{
		std::cout << "\n\n========= " << title << " ==========" << std::endl;
	}

	void Assert(bool condition, std::string msg = "")
	{
		if(condition){
			std::cout << GRN << "OK:\t" << msg << std::endl;
		}
		else{
			std::cout << RED << "NG:\t" << msg << std::endl;
		}
		std::cout << NC << std::endl;
	}

private:
	const char* NC = "\e[0m";
	const char* RED = "\e[0;31m";
	const char* GRN = "\e[0;32m";
	const char* CYN = "\e[0;36m";
	const char* REDB = "\e[41m";
};