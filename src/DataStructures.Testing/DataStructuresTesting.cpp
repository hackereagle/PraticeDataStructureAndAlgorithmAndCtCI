#include <iostream>
#include "TestArrayList.hpp"
#include "TestStringBuilder.hpp"
#include "TestLinkList.hpp"

int main(int argc, char** argv)
{
	// TestArrayList testArrayList;
	// testArrayList.TestPushBackElements();
	// testArrayList.TestPopBackElements();

	// TestStringBuilder testStringBuilder;
	// testStringBuilder.TestAppend();

	TestLinkList testLinkList;
	testLinkList.TestPushBack();
	testLinkList.TestPopBack();
	testLinkList.TestPushFront();
	testLinkList.TestPopFront();

	getchar();
	return EXIT_SUCCESS;
}