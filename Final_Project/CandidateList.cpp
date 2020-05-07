/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Catillio, Edgar (TTh 6:30)

		 Wednesday May 6, 2020

		 CS A250
		 Project 1 - Part B
*/

#include "CandidateList.h"

using namespace std;

// Function declarations
// Same order as in class definition
CandidateList::CandidateList()
{
	first = last = nullptr;
	count = 0;
}

void CandidateList::addCandidate(CandidateType& candidate)
{

}

int CandidateList::getWinner() const
{

}

bool CandidateList::isEmpty()
{
	// Use ternary operator...
	return count == 0 ? true : false;
}

// Public Search function
bool CandidateList::searchCandidate(int ID)
{
	Node* ptrToCandidate = nullptr;
	CandidateList::searchCandidate(ID, ptrToCandidate);
}

void CandidateList::printCandidateName() const
{

}

void CandidateList::printAllCandidates() const
{

}

void CandidateList::printKingdomVotes() const
{

}

void CandidateList::printCandidateTotalVotes() const
{

}

void CandidateList::printFinalResults() const
{

}

// Destructor Methods
void CandidateList::clearList()
{
	// Delete all dynamic data
	// Set all member variables to default
}

CandidateList::~CandidateList()
{
	clearList();
}

// Overloaded Private Search function
bool CandidateList::searchCandidate(int ID, Node* ptr)
{
	//For Loop to traverse List
	return true;
}