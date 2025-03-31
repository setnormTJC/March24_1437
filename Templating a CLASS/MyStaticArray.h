#pragma once


class IntegerStaticArray
{
private:
	static constexpr int MAX_CAPACITY = 5;
	int listOfData[MAX_CAPACITY]; //make space for 5 elements of type "T"


};

template<typename T> 
class GenericStaticArray
{
private: 
	static constexpr int MAX_CAPACITY = 5;
	T listOfData[MAX_CAPACITY]; //make space for 5 elements of type "T"


public: 
	GenericStaticArray() = default; 

	GenericStaticArray(const T& theInitialValueOfAll5Elements)
	{
		for (int i = 0; i < MAX_CAPACITY; ++i)
			listOfData[i] = theInitialValueOfAll5Elements;

	}

	void print()
	{
		for (int i = 0; i < MAX_CAPACITY; ++i)
			std::cout << listOfData[i] << " ";

		std::cout << "\n";
	}
};



