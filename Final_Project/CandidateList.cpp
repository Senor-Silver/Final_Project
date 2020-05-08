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
	// If the list is empty...
	// Assign 'candidate' to --first & --last
	if (this->isEmpty())
		first = last = new Node(candidate, nullptr);
	// Else, assing 'candidate' to --last->--link
	else
	{
		last->setLink(new Node(candidate, nullptr));
		last = last->getLink();
	}

	count++;
}

int CandidateList::getWinner() const
{
	// If --count is 0...
	if (!count)
	{
		// List is empty, output cerr
		cerr << "=> List is empty. " << endl;
		return 0;
	}
		
	// Use a Node*, 'temp' to traverse list
	// Keep track of winner with 
	Node* temp = first;
	int victorOfVotes = first->getCandidate().getID();

	/*
	// Do...
	do
	{

		
		temp = temp->getLink();              // Proceed to next Node
	} while (temp->getLink() != nullptr // || temp != last);    // Continue loop if not at last
	*/
	
	// WHILE the next --link does not equal nullptr
	while (temp->getLink() != nullptr)
	{
		// Save # of Votes into var, move 'temp' to next --link
		int tempVotes = temp->getCandidate().getTotalVotes();
		temp = temp->getLink();

		// Compare votes and assign new Victor
		if (tempVotes < temp->getCandidate().getTotalVotes())
			victorOfVotes = temp->getCandidate().getID();
	}
	// Return ID of Winner
	return victorOfVotes;
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