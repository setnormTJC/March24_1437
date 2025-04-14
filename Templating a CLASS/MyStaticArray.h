#pragma once

#include<algorithm>

#include<cassert>

class IntegerStaticArray
{
private:
	static constexpr int MAX_CAPACITY = 5;
	int listOfNumbers[MAX_CAPACITY]; //make space for 5 elements of type INT 


};

template<typename T, int MAX_CAPACITY> 
class GenericStaticArray
{
private: 
	//static constexpr int MAX_CAPACITY = 5;
	T listOfThangs[MAX_CAPACITY]; //make space for 5 elements of type "T"

public: 
	GenericStaticArray() = default; 

	GenericStaticArray(const T& anInputValue)
	{
		for (int i = 0; i < MAX_CAPACITY; ++i)
			listOfThangs[i] = anInputValue; 

	}

	GenericStaticArray<T, MAX_CAPACITY> operator + (const GenericStaticArray<T, MAX_CAPACITY>& otherArray)
	{
		GenericStaticArray<T> theResult; 
		//to be continued...
		for (int i = 0; i < MAX_CAPACITY; ++i)
			theResult.listOfThangs[i] = this->listOfThangs[i] + otherArray.listOfThangs[i]; 


		return theResult; 
	}


	void modifyElementAtIndex(const T& newValueToPutIn, const int theIndexToPutItAt)
	{

		//assert(theIndexToPutItAt < 0);

		//assert(theIndexToPutItAt < MAX_CAPACITY);

		if (theIndexToPutItAt < 0 ) throw std::exception("index was less than 0!");

		listOfThangs[theIndexToPutItAt] = newValueToPutIn;

		//return; //nuthin'!
	}

	int linearSearch(const T& thingToSearchFor)
	{
		//this is a "O(N) complexity" algorithm -> much more on this next semester 
		for (int i = 0; i < MAX_CAPACITY; ++i)
		{
			if (listOfThangs[i] == thingToSearchFor)
			{
				return i; 
			}
		}

		std::cout << "The value " << thingToSearchFor << " is NOT in the array\n";
		return -1; 

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



