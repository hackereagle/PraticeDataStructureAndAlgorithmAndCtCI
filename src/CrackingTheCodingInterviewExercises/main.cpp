#include <iostream>
#include <vector>
#include <memory>
#include "TestClassBase.hpp"
#include "Ch1_1_IsUnique.hpp"
#include "Ch1_2_CheckPermutation.hpp"
#include "Ch1_3_URLify.hpp"
#include "Ch1_4_PalindromePermutation.hpp"

int main(int argc, char** argv)
{
	std::vector<std::unique_ptr<TestClassBase>> tests;
	// tests.push_back(std::make_unique<Ch1_1_IsUnique_Test>());
	//tests.push_back(std::make_unique<Ch1_2_CheckPermutation_Test>());
	// tests.push_back(std::make_unique<Ch1_3_URLify_Test>());
	tests.push_back(std::make_unique<Ch1_4_PalindromePermutation_Test>());

	for(std::unique_ptr<TestClassBase>& t : tests){
		t->Test();
	}

	return EXIT_SUCCESS;
}