// IntoducingTemplates-GenericProgramming-March31.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<cassert>
#include <iostream>
#include <vector>




template <typename T> 
void printStuff(const T& a)
{
	//a = 123; 
	std::cout << "The data type of " << a << " is: " << typeid(a).name() << "\n";

	std::cout << a << "\n";
}

/*My purpose here is to give a nice example of automatic return type*/
//template<typename T> 
//auto returnThing(const T& theInputThing)
//{
//	return theInputThing * 2; 
//}


template<typename T>
auto square(const T& value)
{
	return value * value;
}

template<typename KeyType, typename ValueType> 
auto mapKeysToValues(const std::vector<KeyType>& keys, const std::vector<ValueType>& values)
{
	assert(keys.size() == values.size());

	for (int i = 0; i < keys.size(); ++i)
	{
		std::cout << keys[i] << " corresponds to: " << values[i] << "\n";
	}
}




int main()
{
	std::vector<int> thresholdCatAges = 
	{ 
		1, 
		2, 
		3, 
		7, 
		11, 
		15 
	};
	
	std::vector<std::string> catAgeDescriptors =
	{
		"Kitten", 
		"Junior", 
		"Prime", 
		"Mature", 
		"Senior", 
		"Not long for this world :(", 
		//"how is this kitty still alive?"
	};


	mapKeysToValues(thresholdCatAges, catAgeDescriptors);
	std::cout << "\n\n\n";
	//mapKeysToValues(catAgeDescriptors, thresholdCatAges);

	//std::vector<int> nums = { 1, 2, 3 , "adsfasdf"};

	//int a = 12; 
	//std::string b = "1239383aasdfsdf";
	//float c = 2.31f; 

	//printStuff(a);
	//printStuff(b); 

	//printStuff(c); 

	//auto result = square("sdfasdf"); //Doesn't work! -> binary * not defined for character array!
	auto result = square(2); 
	result = square(2.2); //also fine
	result = square(2.2f); //f-> float (also fine)
	//std::cout << result << "\n";


}

