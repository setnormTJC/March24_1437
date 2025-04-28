// Intro to DSA - on April 28.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector> 

#include<forward_list>
#include<list> //there is an "invisible" word in front here:
				//doubly-linked_list

#include<map> 


int main()
{
	std::vector<int> vNums = { 1, 2, 34 };

	std::list<std::string> lNames =
	{
		"Alice", "Bob", "Carol"
	};

	lNames.pop_back(); 

	lNames.push_front("Zebra"); 
	//who is in the list of names now? 
	//for (const auto& currentName : lNames)
	//	std::cout << currentName << "\n";

	std::map<std::string, std::string> englishToSpanish =
	{
		{"Hello", "Hola"},
		{"world", "mundo"}
	};




	std::cout << "The SIZE of the map, immediately after initializing:\n"
		<< englishToSpanish.size() << "\n";

	std::cout << "enter some word to translate to SPANISH (espanol).\n"; 
	std::string someWordInEnglish; 
	std::cin >> someWordInEnglish;

	std::cout << "That word in SPANISH is: " << englishToSpanish[someWordInEnglish] 
	<< "\n";


	std::cout << "The SIZE of the map, after you searched for that translation:\n"
		<< englishToSpanish.size() << "\n";

	//std::cout << "That word in SPANISH is: " << englishToSpanish.at(someWordInEnglish)
	//	<< "\n";
	//the AT method differs from [] in that it is "CHECKED ACCESS"

}
