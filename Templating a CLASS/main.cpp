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

void demoSortingRandomNumbers()
{
	constexpr int NUMBER_OF_ELEMENTS = 10;

	MySpace::GenericStaticArray<int, NUMBER_OF_ELEMENTS> oneThousandRandomNumbers;

	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<> randomDistributionFrom0To100(0, NUMBER_OF_ELEMENTS);

	for (int i = 0; i < NUMBER_OF_ELEMENTS; ++i)
	{
		auto currentRandomNumber = randomDistributionFrom0To100(rng);
		oneThousandRandomNumbers.modifyElementAtIndex(currentRandomNumber, i);
	}

	oneThousandRandomNumbers.print();

	oneThousandRandomNumbers.naiveSort();
	std::cout << "\n\n\nAfter sorting\n";
	oneThousandRandomNumbers.print();
}

int main()
{
	
	try
	{
		constexpr int N = 20; 

		MySpace::GenericStaticArray<std::string, N> listOfNames("Alice");

		listOfNames.modifyElementAtIndex("Bob", 1);
		listOfNames.modifyElementAtIndex("Carol", 2);
		listOfNames.modifyElementAtIndex("David", 3);
		listOfNames.modifyElementAtIndex("Eve", 4);
		listOfNames.modifyElementAtIndex("Frank", 5);
		listOfNames.modifyElementAtIndex("Grace", 6);
		listOfNames.modifyElementAtIndex("Heidi", 7);
		listOfNames.modifyElementAtIndex("Ivan", 8);
		listOfNames.modifyElementAtIndex("Judy", 9);
		listOfNames.modifyElementAtIndex("Karl", 10);
		listOfNames.modifyElementAtIndex("Liam", 11);
		listOfNames.modifyElementAtIndex("Mallory", 12);
		listOfNames.modifyElementAtIndex("Niaj", 13);
		listOfNames.modifyElementAtIndex("Olivia", 14);
		listOfNames.modifyElementAtIndex("Peggy", 15);
		listOfNames.modifyElementAtIndex("Quentin", 16);
		listOfNames.modifyElementAtIndex("Rupert", 17);
		listOfNames.modifyElementAtIndex("Sybil", 18);
		listOfNames.modifyElementAtIndex("Trent", 19);

		listOfNames.print(); 

		//pick a random number between 0 and the number of names in the list: 
		std::mt19937 rng(std::random_device{}());
		std::uniform_int_distribution<> randomDistributionFrom0ToN(0, N - 1);

		int randomIndexChosen = randomDistributionFrom0ToN(rng);

		const std::string randomNameToSearchFor = listOfNames.getElementAtGivenIndex(randomIndexChosen);

		std::cout << "Searching for " << randomNameToSearchFor << "...\n";

		listOfNames.binarySearch(randomNameToSearchFor, 0, listOfNames.getN());

	}

	catch (MySpace::MyCustomException& e)
	{
		std::cout << e.what() << "\n";
	}


}

