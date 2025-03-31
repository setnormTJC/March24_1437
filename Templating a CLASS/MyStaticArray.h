#pragma once

template<typename T> 
class MyStaticArray
{
private: 
	static constexpr int MAX_CAPACITY = 5;
	T listOfData[MAX_CAPACITY]; //make space for 5 elements of type "T"


public: 
	MyStaticArray() = default; 

	MyStaticArray(const T& theInitialValueOfAll5Elements)
	{
		for (int i = 0; i < MAX_CAPACITY; ++i)
			listOfData[i] = theInitialValueOfAll5Elements;
	}

	void print()
	{
		for (int i = 0; i < MAX_CAPACITY; ++i)
			std::cout << listOfData[i] << " ";
	}
};



