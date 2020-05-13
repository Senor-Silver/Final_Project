/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Castillo, Edgar (TTh 6:30)

		 Wednesday May 6, 2020

		 CS A250
		 Project 1 - Part A
*/

#include "CandidateType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

// Default Constructor
CandidateType::CandidateType()
{
	totalVotes = 0;
	numOfKingdoms = NUM_OF_KINGDOMS;
	kingdomVotes = new int[numOfKingdoms] {0};
}

// Copy Constructor
CandidateType::CandidateType(const CandidateType& otherType)
{
	// Gather member variable info via Inheritence
	CharacterType::setCharacterInfo
	(otherType.getLastName(), otherType.getFirstName(), otherType.getID());

	// Update 'CandidateType' member variables
	totalVotes = otherType.totalVotes;
	numOfKingdoms = otherType.numOfKingdoms;
	kingdomVotes = new int[numOfKingdoms];

	// Loop to gather --kingdomVotes info for Copying
	for (int i = 0; i < numOfKingdoms; ++i)
		kingdomVotes[i] = otherType.kingdomVotes[i];
}

// Copy Assingment operator
CandidateType& CandidateType::operator=(const CandidateType& rhs)
{
	if (&rhs != this) // Avoid Self-Assignment by checking addresses
	{
		CharacterType::setCharacterInfo
		(rhs.getLastName(), rhs.getFirstName(), rhs.getID());

		totalVotes = rhs.totalVotes;

		if (numOfKingdoms != rhs.numOfKingdoms)
		{
			delete[] kingdomVotes;
			numOfKingdoms = rhs.numOfKingdoms;
			kingdomVotes = new int[numOfKingdoms];
		}

		for (int i = 0; i < numOfKingdoms; ++i)
			kingdomVotes[i] = rhs.kingdomVotes[i];
	}
	else
		cerr << "Attempted assignment to self.";

	return *this;
}

// updateVotesByKingdom
void CandidateType::updateVotesByKingdom(int kingdomIndex, int numOfVotes)
{
	totalVotes += numOfVotes;
	kingdomVotes[kingdomIndex] = numOfVotes;
}

// getTotalValues
int CandidateType::getTotalVotes() const
{
	return totalVotes;
}

// getVotesByKingdom
int CandidateType::getVotesByKingdom(int index) const
{
	return kingdomVotes[index];
}

// print functions
void CandidateType::printCandidateInfo() const
{
	printID();
	cout << "-";
	printName();
	cout << "\n";
}

void CandidateType::printCandidateTotalVotes() const
{
	printName();
	cout << "=> Total Votes (all kingdoms): " << totalVotes;
}

// Destructor
CandidateType::~CandidateType()
{
	delete[] kingdomVotes;
	kingdomVotes = nullptr;
}
