#pragma once

#include<algorithm>

#include<cassert>

#include<sstream>

namespace MySpace
{
	class MyCustomException// : public std::exception
	{
	public: 
		MyCustomException() = delete; 
		MyCustomException(const std::string& partialErrorMessage, const int lineNumber, const std::string& filename)
			:partialErrorMessage(partialErrorMessage), lineNumber(lineNumber), filename(filename)
		{

		}

		/*"what" as in WHAT in the world went wrong*/
		std::string what() 
		{
			std::ostringstream fullErrorMessage;
			fullErrorMessage << "In file named: " << filename << " on line number: " << lineNumber
				<< "\nthe following error message occurs" << partialErrorMessage << "\n";


			return fullErrorMessage.str(); 
		}

	private: 
		std::string partialErrorMessage; 
		int lineNumber; 
		std::string filename; 

	};

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

		int getN()
		{
			return MAX_CAPACITY; 
		}

		T getElementAtGivenIndex(int index)
		{
			//defensive programming FTW!
			if (index < 0) throw MyCustomException("index cannot be less than 0!", __LINE__, __FILE__);

			return listOfThangs[index]; 
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

		void mySwap(const int firstIndex, const int secondIndex)
		{

			T storage = listOfThangs[firstIndex];

			listOfThangs[firstIndex] = listOfThangs[secondIndex];

			listOfThangs[secondIndex] = storage;

		}

		void modifyElementAtIndex(const T& newValueToPutIn, const int theIndexToPutItAt)
		{
			//assert(theIndexToPutItAt >= 0 &&)
			//if (theIndexToPutItAt < 0 ) throw std::exception("index was less than 0!");

			if (theIndexToPutItAt < 0) throw MyCustomException("index was less than 0 in `modifyElementAtIndex`", 
				__LINE__, __FILE__);


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

		bool isSortedInAscendingOrder()
		{
			for (int i = 0; i < MAX_CAPACITY - 1; ++i)
			{
				if (listOfThangs[i + 1] < listOfThangs[i]) //TRUE for this example: {3, 1} since 1 < 3
				{
					return false; 
				}
			}

			return true; //if it is NEVER the case that the next element in the array is less than the current element 
		}

		/*
		* @returns the INDEX of `thingToSearchFor` -> returns -1 if not found
		*/
		int binarySearch(const T& thingToSearchFor, int startingSearchIndex, int lastSearchIndex)
		{
			/*safety check: throw exception if array is not sorted (in ascending order)*/
			static bool safetyCheckDone; //implicitly initialized to false -> note the use of STATIC!
			if (safetyCheckDone == false)
			{
				if (!isSortedInAscendingOrder())
				{
					throw MyCustomException("Cannot call binary search on unsorted array!"
						,__LINE__, __FILE__ );
				}
			}
			safetyCheckDone = true;  //only need to check for "sortedness" once 

			if (startingSearchIndex > lastSearchIndex) //array was "subdivided" 
				return -1;    						//so many times that we have no elements left in search range!

			int middleIndex = startingSearchIndex + (lastSearchIndex  - startingSearchIndex) / 2;

			if (listOfThangs[middleIndex] == thingToSearchFor)
				return middleIndex;

			else if (listOfThangs[middleIndex] < thingToSearchFor) //look "right" (in the "upper sublist")
				return binarySearch(thingToSearchFor, middleIndex + 1, lastSearchIndex);

			else //look in the "lower" sublist
				return binarySearch(thingToSearchFor, startingSearchIndex, middleIndex - 1);
		}
	
		/*This algorithm has "time complexity" O(N^2) -> N is the number of elements */
		void naiveSort()
		{
			//std::cout << MAX_CAPACITY << "\n";
			for (int outer = 0; outer < MAX_CAPACITY - 1; ++outer)
			{
				for (int inner = outer + 1; inner < MAX_CAPACITY; ++inner) //previously initialized inner to ONE (1) 
				{
					if (listOfThangs[inner] < listOfThangs[outer])//this is a comparison operation (obviously) 
					{
						mySwap(inner, outer); //PascalCase camelCase

						//std::cout << "A SWAP happened! Hooray! Here's the UPDATED array (any key to continue):\n";
						//print(); 
						//std::cin.get(); //requires a single input character before continuing execution
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

