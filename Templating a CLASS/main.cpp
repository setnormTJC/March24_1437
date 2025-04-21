// Templating a CLASS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<array> //this is the C++ standard library implementation of a static array
#include <iostream>
#include<random> 
#include <vector>
#include "MyStaticArray.h"


void demoSomeStaticOfStringFunctionality()
{
	using namespace MySpace;
	GenericStaticArray<std::string, 6> names("mouse?");



	names.modifyElementAtIndex("Darth", 0);
	names.modifyElementAtIndex("Alice", 1);
	names.modifyElementAtIndex("Bob", 2);
	names.modifyElementAtIndex("Aaaah", 3);
	names.modifyElementAtIndex("Carol", 4);
	names.modifyElementAtIndex("Eve", 5);

	/*testing swap*/
	//names.mySwap("Darth", "Alice"); 

	names.naiveSort();

	names.print();
}

int main()
{
	
	try
	{
		constexpr int NUMBER_OF_ELEMENTS = 1000; 

		MySpace::GenericStaticArray<int, NUMBER_OF_ELEMENTS> oneHundredRandomNumbers(99);

		std::mt19937 rng(std::random_device{}());
		std::uniform_int_distribution<> randomDistributionFrom0To100(0, NUMBER_OF_ELEMENTS); 

		for (int i = 0; i < NUMBER_OF_ELEMENTS; ++i)
		{
			auto currentRandomNumber = randomDistributionFrom0To100(rng);
			oneHundredRandomNumbers.modifyElementAtIndex(currentRandomNumber, i);
		}

		oneHundredRandomNumbers.print(); 

		oneHundredRandomNumbers.naiveSort();
		std::cout << "\n\n\nAfter sorting\n";
		oneHundredRandomNumbers.print(); 

	}

	catch (MySpace::MyCustomException& e)
	{
		std::cout << e.what() << "\n";
	}


}

