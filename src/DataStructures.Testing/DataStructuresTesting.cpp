#include <iostream>
#include "TestArrayList.hpp"
#include "TestStringBuilder.hpp"

int main(int argc, char** argv)
{
	TestArrayList testArrayList;
	testArrayList.TestPushBackElements();
	testArrayList.TestPopBackElements();

	TestStringBuilder testStringBuilder;

	getchar();
	return EXIT_SUCCESS;
}