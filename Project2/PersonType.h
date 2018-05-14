/*
	CodeMD
	
	Nguyen, Michael
	Dang, Demi
	
	CS A250: Project 1
*/

#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class PersonType
{
public:
	PersonType();
	PersonType(const string& newFirstName, 
		const string& newLastName, int newSSN); 

	void setPersonInfo(const string& newFirstName,
		const string& newLastName, int newSSN);

	string getFirstName() const;
	string getLastName() const;

	int getSSN() const;

	void printName() const; 
	void printPersonInfo() const; 
	void printSSN() const;

	~PersonType();

private:
	string firstName;
	string lastName;
	int ssn; 
};


#endif

