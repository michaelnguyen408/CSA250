/*
	CodeMD
	
	Nguyen, Michael
	Dang, Demi
	
	CS A250: Project 1
*/

#include "PersonType.h"

PersonType::PersonType()
{
	ssn = 0; 
}

PersonType::PersonType(const string& newFirstName,
	const string& newLastName, int newSSN) : firstName(newFirstName), lastName(newLastName), ssn(newSSN) {}

void PersonType::setPersonInfo(const string& newFirstName,
	const string& newLastName, int newSSN)
{
	firstName = newFirstName;
	lastName = newLastName;
	ssn = newSSN;
}

string PersonType::getFirstName() const
{
	return firstName;
}

string PersonType::getLastName() const
{
	return lastName; 
}

int PersonType::getSSN() const
{
	return ssn;
}

void PersonType::printName() const
{
	cout << lastName << ", " << firstName;
}

void PersonType::printPersonInfo() const
{
	printSSN();
	cout << " " << firstName 
		<< " " << lastName;
}

void PersonType::printSSN() const
{
	int firstThreeNumbers = ssn / 1000000;
	int middleTwoNumbers = (ssn % 1000000) / 10000;
	int lastThreeNumbers = (ssn % 10000);
	cout << setfill('0') << setw(3) << firstThreeNumbers << "-"
		<< setw(2) << middleTwoNumbers << "-"
		<< setw(4) << lastThreeNumbers;
}

PersonType::~PersonType()
{}