/*
		TeamName
		 Iacob, Marius (TTh 6:30)
		 Catillio, Edgar (TTh 6:30)

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
	CharacterType();

	// Overloaded constructor
	CharacterType(std::string lastN, std::string firstN, int ID);

	// setCharacterInfo Function
	void setCharacterInfo(std::string fName, std::string lName, int ID);

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

