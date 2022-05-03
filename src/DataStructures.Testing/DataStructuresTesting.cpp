#include <iostream>
#include "TestArrayList.hpp"

int main(int argc, char** argv)
{
	TestArrayList testArrayList;
	testArrayList.TestPushBackElements();
	testArrayList.TestPopBackElements();
	getchar();
	return EXIT_SUCCESS;
}