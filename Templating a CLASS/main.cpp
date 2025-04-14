// Templating a CLASS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<array> //this is the C++ standard library implementation of a static array
#include <iostream>
#include <vector>
#include "MyStaticArray.h"

int main()
{
	
	//int nums[4] = { 1, 2, 3, 4 }; //this is the C (not C++) language way to make a static array

	//std::cout << nums. //doesn't work! nums is not an object of a class! (it's a pointer)
 
	//std::cout << nums << "\n";

	//int nums[-1]
	
	//std::array<std::string, -2> negativeNames; 


	std::array<int, 4> stdArray = { 1, 2, 3, 5 }; 

	

	//std::cout << "Is it 5? " << stdArray.back() << "\n";

/*	std::vector<std::vector<int>> twoDArrayOfNums;*/ //Templates allow this!
	
	//IntegerStaticArray intArray;


	GenericStaticArray<int, 7> numsArray(5); //a single template parameter (int)
	//GenericStaticArray<int, 5> OTHERnumsArray(11); 

	const int index = -123; 

	try
	{
		numsArray.modifyElementAtIndex(3735635, index); //throws!
	}

	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}


	numsArray.print(); 
	std::cout << "The BACK (AKA: last) element in that array is: " << numsArray.back();

	int valueToSearchFor = 12333; 

	std::cout << "Index of " << valueToSearchFor << " is: " << numsArray.linearSearch(valueToSearchFor) << "\n";


}

