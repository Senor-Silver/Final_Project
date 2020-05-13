/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Castillo, Edgar (TTh 6:30)

		 Wednesday May 6, 2020

		 CS A250
		 Project 1 - Part A
*/

#include "CharacterType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

// Overloaded constructor
CharacterType::CharacterType(const string& firstN, 
							 const string& lastN, int ID)
{
	firstName = firstN;
	lastName = lastN;
	id = ID;
}

// setCharacterInfo Function
void CharacterType::setCharacterInfo(const string& fName, 
									 const string& lName, int ID)
{
	firstName = fName;
	lastName = lName;
	id = ID;
}

// Getters Functions
string CharacterType::getFirstName() const
{
	return firstName;
}
string CharacterType::getLastName() const
{
	return lastName;
}
int CharacterType::getID() const
{
	return id;
}

// Printing Functions
void CharacterType::printName() const
{
	cout << lastName << ", " << firstName;
}
void CharacterType::printCharacterInfo() const 
{
	cout << "ID# " << id << firstName << lastName;
}
void CharacterType::printID() const
{
	cout << "ID# " << id;
}

// Destructor
CharacterType::~CharacterType(){}