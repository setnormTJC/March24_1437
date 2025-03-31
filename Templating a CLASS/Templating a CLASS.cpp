// Templating a CLASS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "MyStaticArray.h"

int main()
{

/*	std::vector<std::vector<int>> twoDArrayOfNums;*/ //Templates allow this!
	
	IntegerStaticArray intArray;


	GenericStaticArray<int> numsArray(5); 

	numsArray.print(); 

	GenericStaticArray<std::string> stringArray("asdfasdfsd");
	stringArray.print(); 

	//MyStaticArray<std::string> stringArray; 
}

