#pragma once
#include <iostream>

class AICompanion
{
    std::string aiName = "Chat GPT";

public: 
    //void sendEmail(const Person& personToEmail); //function declaration 
};

class Person
{
public: 
    std::string emailAddress;

public:
    std::string name;
    Person(const std::string& name, const std::string& emailAddress);

    friend class AICompanion; 

    /*The GENERIC syntax for overloading an operator*/
    //returnType operator operatorSymbol(input);

    Person operator + (const Person& rightHandSide);

    bool operator == (const Person& rightHandSide);

    bool isSamePerson(const Person& rightHandSide);

    void demoThis(); 

    //friend void someFriendFunction(); //let's come back to this later!
};

