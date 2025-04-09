// Templating a CLASS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<array>
#include <iostream>
#include <vector>
#include "MyStaticArray.h"

int main()
{
	
	//std::array<int, 4> stdArray = { 1, 2, 3, 5 };

	//std::cout << "Is it 5? " << stdArray.back() << "\n";

/*	std::vector<std::vector<int>> twoDArrayOfNums;*/ //Templates allow this!
	
	//IntegerStaticArray intArray;


	GenericStaticArray<int> numsArray(5); 
	GenericStaticArray<int> OTHERnumsArray(11); 

	numsArray.print(); 
	std::cout << "The BACK (AKA: last) element in that array is: " << numsArray.back();

	//auto theResultOfAddingTwoIntArrays = numsArray + OTHERnumsArray; 
	//theResultOfAddingTwoIntArrays.print(); 


	//GenericStaticArray<std::string> stringArray("Bob");
	//GenericStaticArray<std::string> OTHERstringArray("Boblaw's law blog");
	//
	//auto resultOfAddingTwoStringArrays = OTHERstringArray + stringArray;
	//resultOfAddingTwoStringArrays.print(); 

	//stringArray.print(); 

	//MyStaticArray<std::string> stringArray; 
}

