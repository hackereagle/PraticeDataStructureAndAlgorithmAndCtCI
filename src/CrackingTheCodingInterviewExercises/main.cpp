#include <iostream>
#include <vector>
#include <memory>
#include "TestClassBase.hpp"
#include "Ch1_1_IsUnique.hpp"

int main(int argc, char** argv)
{
	std::vector<std::unique_ptr<TestClassBase>> tests;
	tests.push_back(std::make_unique<Ch1_1_IsUnique_Test>());

	for(std::unique_ptr<TestClassBase>& t : tests){
		t->Test();
	}

	return EXIT_SUCCESS;
}