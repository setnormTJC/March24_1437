// Demo sorting objects of a class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<algorithm>
#include <iostream>
#include <vector>


class Shoe
{
private: 
    int numberOfStarsOnAmazon = 1; 
    double cost; 
    std::string name; 


public: 
    Shoe(int n, double c, const std::string& name)
        :numberOfStarsOnAmazon(n), cost(c), name(name)
    {

    }

    friend std::ostream& operator << (std::ostream& os, const Shoe& shoeObject)
    {
        os << shoeObject.name << "\t" << shoeObject.cost << "\t" << shoeObject.numberOfStarsOnAmazon << "\n";
        return os; 
    }

    //bool operator < (const Shoe& otherShoe)
    //{
    //    return (this->cost < otherShoe.cost); 
    //}

    friend bool compareByName(const Shoe& firstShoe, const Shoe& secondShoe); 
};

bool compareByName(const Shoe& firstShoe, const Shoe& secondShoe)
{
    return (firstShoe.name < secondShoe.name); 
}


int main()
{
    //Shoe someShoe(4, 109.99, "some shoe");

    //std::cout << someShoe << "\n";

    std::vector<Shoe> shoeList =
    {
        Shoe(5, 89.99, "Nike Air Zoom Pegasus"),
        Shoe(4, 59.95, "Adidas Lite Racer"),
        Shoe(3, 35.50, "Skechers Go Walk"),
        Shoe(5, 120.00, "New Balance Fresh Foam"),
        Shoe(2, 19.99, "Budget Basics"),
        Shoe(4, 75.25, "Puma RS-X"),
        Shoe(5, 140.49, "Brooks Ghost 14"),
        Shoe(3, 45.00, "Reebok Classics"),
        Shoe(4, 68.90, "ASICS Gel-Venture"),
        Shoe(5, 150.00, "Hoka One One Clifton")
    };

    std::sort(shoeList.begin(), shoeList.end(), compareByName);  //not so fast!


    std::cout << "Name\tCost\tNumber of stars\n";
    for (const auto& theCurrentShoe : shoeList)
    {
        std::cout << theCurrentShoe << "\n";
    }

}


