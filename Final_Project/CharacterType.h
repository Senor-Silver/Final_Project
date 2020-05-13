/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Castillo, Edgar (TTh 6:30)

		 Sunday, May 3, 2020

		 CS A250
		 Project 1 - Part A
*/

#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H

#include <iostream>
#include <string>

class CharacterType
{
public:
	// Default constructor
	CharacterType() : id(0) {};

	// Overloaded constructor
	CharacterType(const std::string& firstN, 
					const std::string& lastN, int ID);

	// setCharacterInfo Function
	void setCharacterInfo(const std::string& fName, 
							const std::string& lName, int ID);

	// Getters Functions
	std::string getFirstName() const;
	std::string getLastName() const;
	int getID() const;

	// Printing Functions
	void printName() const;
	void printCharacterInfo() const;
	void printID() const;

	// Destructor
	~CharacterType();

private:
	std::string firstName;
	std::string lastName;
	int id;
};

#endif 

