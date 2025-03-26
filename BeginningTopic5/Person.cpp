#include "Person.h"

Person::Person(const std::string& name, const std::string& emailAddress)
	:name(name), emailAddress(emailAddress)
{
}

Person Person::operator+(const Person& rightHandSidePerson)
{
	std::string newPersonName = this->name + rightHandSidePerson.name; 
	std::string newPersonEmail = this->emailAddress + rightHandSidePerson.emailAddress;
	Person newPerson(newPersonName, newPersonEmail);

	return newPerson; 
}

bool Person::operator==(const Person& rightHandSide)
{
	//if (this->name == rightHandSide.name
	//	&&
	//	this->emailAddress == rightHandSide.emailAddress
	//	)
	//{
	//	return true; 
	//}

	//else
	//{
	//	return false; 
	//}

	return (this->name == rightHandSide.name
		&&
		this->emailAddress == rightHandSide.emailAddress);
}

bool Person::isSamePerson(const Person& rightHandSide)
{
	return (this->name == rightHandSide.name
		&&
		this->emailAddress == rightHandSide.emailAddress);

}

void Person::demoThis()
{
	std::cout << "This is: " << this << "\n";
}

//void AICompanion::sendEmail(const Person& personToEmail)
//{
//    std::cout << "Sending email to ..." << personToEmail.name
//        << "at address ...";
//    std::cout << personToEmail.<< "\n";
//    //To be continued!
//
//}

std::ostream& operator<<(std::ostream& os, const Person& thePerson)
{
	os << thePerson.name << " has email address: " << thePerson.emailAddress
		<< "\n";


	return os; 
}
