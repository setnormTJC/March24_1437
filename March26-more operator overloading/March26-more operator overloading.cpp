// March26-more operator overloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<algorithm>

#include<fstream> //we are gonna write to a text file here

#include<iomanip> 
#include <iostream>
#include <vector>


class Shoe
{
private: //let's enforce ENCAPSULATION - prevent main from screwin' stuff up!
    std::string name; 
    int numberOfStars; 
    double price; 
public: 
    Shoe() = delete; 
    Shoe(const std::string& name, const int numberOfStars, const double price)
        :name(name), numberOfStars(numberOfStars), price(price)
    {

    };
    
    friend std::ostream& operator << (std::ostream& os, const Shoe& shoeObject)
    {
        constexpr int NAME_COL_WIDTH = 30; 
        
        os << std::left << std::setw(NAME_COL_WIDTH) << shoeObject.name;
        os << std::left << std::setw(5) << shoeObject.numberOfStars;
        os << std::left << std::setw(8) << shoeObject.price;

        return os; 
    }

    /*
    * For NOW, we will say one shoe is "less than" another shoe if its PRICE is less than the other shoe's price
    * @param rhs -> this means "right-hand side" shoe 
    */
    bool operator < (const Shoe& rhs)
    {
        return (price < rhs.price);
    }

    friend bool compareByStars(const Shoe& lhs, const Shoe& rhs);


};


bool compareByStars(const Shoe& lhs, const Shoe& rhs)
{
    return (lhs.numberOfStars < rhs.numberOfStars); 
}

void printShoeList(const std::vector<Shoe>& shoeList, const std::string& descriptionOfOrder)
{
    std::cout << descriptionOfOrder << "\n";

    for (const Shoe& currentShoe : shoeList)
    {
        std::cout << currentShoe << "\n";
    }
}

void demoSimpleSortOfNumbers()
{
    std::vector<int> nums = { 8, 6, 7, 5, 3, 0, 9 };

    std::sort(nums.begin(), nums.end());

    std::cout << "\n\n\nAfter sorting, the list of numbers becomes: \n";

    for (const int num : nums)
    {
        std::cout << num << " ";
    }
}

int main()
{
    Shoe firstShoe("Assert 9", 4, 59.99);
    Shoe lastShoe("My shoes", 5, 129.99);

    //if (firstShoe < lastShoe)

    std::vector<Shoe> shoeList =
    {
        firstShoe,
        Shoe ("Running shoes", 5, 1'425.92), //this is called an "anonymous" object 
        Shoe("V5 metal basketball shoe", 3, 4.79),
        Shoe("High top sports shoe", 1, 11.01),
        lastShoe
    };

    printShoeList(shoeList, "In no particular order");

    //now order by PRICE: 
    
    std::sort(shoeList.begin(), shoeList.end());
    //if curious about these begin, end functions ...    
    //std::cout << "\n\n\nShoelist.begin()._ptr yields: " << shoeList.begin()._Ptr << "\n"; 


    printShoeList(shoeList, "\n\nSorted by PRICE:");

    //compareByStars is a function pointer in the line of code below: 
    std::sort(shoeList.begin(), shoeList.end(), compareByStars); //NOTE: compareByStars is NOT a member of `Shoe`
    printShoeList(shoeList, "\n\nSorted by REVIEW rating:");


    std::string filename = "out.txt";

    std::ofstream fout("out.txt");

    fout << firstShoe << "\n";
    fout.close(); 

    system(filename.c_str()); //this opens out.txt (just a convenience)
    
}

