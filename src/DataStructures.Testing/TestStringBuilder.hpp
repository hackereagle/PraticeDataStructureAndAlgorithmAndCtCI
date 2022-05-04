#pragma once
#include <iostream>
#include "StringBuilder.hpp"
#include "AssertClass.hpp"

class TestStringBuilder
{
public:
	TestStringBuilder(/* args */)
	{
		std::cout << "\n\n<<<<< Test StringBuilder >>>>>" << std::endl;
	}

	~TestStringBuilder()
	{}

	void TestAppend()
	{
		StringBuilder strBuilder;
		strBuilder.Append("append string, ");
		strBuilder.Append("pi = ");
		strBuilder.Append(3.141592);
		strBuilder.Append(", append int: ");
		strBuilder.Append(123);
		strBuilder.Append(", append float: ");
		strBuilder.Append((float)3.333333);
		strBuilder.Append(", append bool: ");
		strBuilder.Append(true);

		AssertClass::GetInstance().Assert(strBuilder.String() == "append string, pi = 3.141592, append int: 123, append float: 3.333333, append bool: true", strBuilder.String());
	}
	
private:
};
