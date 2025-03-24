// BeginningTopic5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include "Person.h"

/*simple function overloading*/
void printSomething(int a)
{
    std::cout << a << "\n";
}

void printSomething(int a, int b)
{
    std::cout << a << "\t" << b << "\n";
}




int main()
{
    //printSomething(2.3);
    Person you("Bob", "Bob@gmail.com");
    
    Person yourPartner("Partner name", "partner's email.com");

    yourPartner = you; 

    Person yourSpawn = you + yourPartner;

    //std::cout << "spawn's name: " << yourSpawn.name << "\t" << yourSpawn.emailAddress << "\n";

    if (you == yourPartner)
    {
        std::cout << "You are dating YOURSELF?\n";
    }

    else
    {
        std::cout << "Good, you aren't dating yourself\n";
    }

    std::cout << you; //next time!

    //std::cout << "The MEMORY address of the YOU object is: "
    //    << &you << "\n";

    //you.demoThis(); 


    //Person me("me", "me@gmail.com"); 
    //std::cout << "address of me: " << &me << "\n";
    //me.demoThis(); 

    //I am doing this to show what THIS is!
 
}

