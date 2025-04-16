// Templating a CLASS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<array> //this is the C++ standard library implementation of a static array
#include <iostream>
#include <vector>
#include "MyStaticArray.h"

int main()
{
	
	try
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

	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}


}

