#pragma once
#include <iostream>
#include <string>
#include <stdarg.h>
#include "AssertClass.hpp"

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
		AssertClass::GetInstance().Assert(condition, msg);
	}

	void Assert(bool condition, const char* fmt, ...)
	{
		va_list ap, *args_dig;
		va_start(ap, fmt);
		args_dig = va_arg(ap, va_list*);
		AssertClass::GetInstance().Assert(condition, fmt, *args_dig);
		va_end(ap);
	}

private:
	const char* NC = "\e[0m";
	const char* RED = "\e[0;31m";
	const char* GRN = "\e[0;32m";
	const char* CYN = "\e[0;36m";
	const char* REDB = "\e[41m";
};