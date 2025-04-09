#pragma once

#include<algorithm>

class IntegerStaticArray
{
private:
	static constexpr int MAX_CAPACITY = 5;
	int listOfNumbers[MAX_CAPACITY]; //make space for 5 elements of type INT 


};

template<typename T> 
class GenericStaticArray
{
private: 
	static constexpr int MAX_CAPACITY = 5;
	T listOfThangs[MAX_CAPACITY]; //make space for 5 elements of type "T"

public: 
	GenericStaticArray() = default; 

	GenericStaticArray(const T& anInputValue)
	{
		for (int i = 0; i < MAX_CAPACITY; ++i)
			listOfThangs[i] = anInputValue + i; //beware! this will BREAK for <string>!

	}

	GenericStaticArray<T> operator + (const GenericStaticArray<T>& otherArray)
	{
		GenericStaticArray<T> theResult; 
		//to be continued...
		for (int i = 0; i < MAX_CAPACITY; ++i)
			theResult.listOfThangs[i] = this->listOfThangs[i] + otherArray.listOfThangs[i]; 


		return theResult; 
	}
	
	//GenericStaticArray<T> operator - (const GenericStaticArray<T>& otherArray) //prolly NOT a good idea !

	void naiveSort()
	{
		//to be continued 
	}

	/*@return the LAST element in the array*/
	T back()
	{
		return listOfThangs[MAX_CAPACITY - 1];
	}


	void print()
	{
		for (int i = 0; i < MAX_CAPACITY; ++i)
			std::cout << listOfThangs[i] << " ";

		std::cout << "\n";
	}
};



