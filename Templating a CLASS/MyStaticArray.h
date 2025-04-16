#pragma once

#include<algorithm>

#include<cassert>

namespace MySpace
{


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

		int getIndexOfElement(const T& elementToGetIndexOf)
		{
			for (int i = 0; i < MAX_CAPACITY; ++i)
			{
				if (listOfThangs[i] == elementToGetIndexOf)
				{
					return i; 
				}
			}

			std::cout << elementToGetIndexOf << " was NOT found in the array :(\n";
			return -1; 
		}

		void mySwap(const T& firstElement, const T& secondElement)
		{
			int indexOfFirstElement = getIndexOfElement(firstElement); //this will be 0 for Darth 
			int indexOfSecondElement = getIndexOfElement(secondElement); //this will be 1 for Alice (in the current example)


			T temporaryCopyOfFirstElement = listOfThangs[indexOfFirstElement];

			listOfThangs[indexOfFirstElement] = listOfThangs[indexOfSecondElement];

			listOfThangs[indexOfSecondElement] = temporaryCopyOfFirstElement;


		}

		void modifyElementAtIndex(const T& newValueToPutIn, const int theIndexToPutItAt)
		{
		
			if (theIndexToPutItAt < 0 ) throw std::exception("index was less than 0!");

			listOfThangs[theIndexToPutItAt] = newValueToPutIn;

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
	
		void naiveSort()
		{
			for (int outer = 0; outer < MAX_CAPACITY - 1; ++outer)
			{
				for (int inner = outer + 1; inner < MAX_CAPACITY; ++inner) //previously initialized inner to ONE (1) 
				{
					if (listOfThangs[inner] < listOfThangs[outer])
					{
						mySwap(listOfThangs[inner], listOfThangs[outer]);

						std::cout << "A SWAP happened! Hooray! Here's the UPDATED array (any key to continue):\n";
						print(); 
						std::cin.get(); //requires a single input character before continuing execution
					}
				}
			}
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

}

