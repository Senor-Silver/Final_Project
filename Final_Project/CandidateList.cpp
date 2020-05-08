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
	if (this->isEmpty() /* || !count*/)
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
	int winnerID = first->getCandidate().getID();
	int winnerTtlVotes = first->getCandidate().getTotalVotes();
	
	// WHILE the next --link does not equal nullptr
	while (temp->getLink() != nullptr)
	{
		// Update 'temp' to next --link
		temp = temp->getLink();

		// Compare Total Votes of Candidates
		if (winnerTtlVotes < temp->getCandidate().getTotalVotes())
		{
			winnerID = temp->getCandidate().getID();
			winnerTtlVotes = temp->getCandidate().getTotalVotes();
		}
	}
	// Return ID of Winner
	return winnerID;
}

bool CandidateList::isEmpty()
{
	// Use ternary operator...
	return count == 0 ? true : false;
}

// Public Search function
bool CandidateList::searchCandidate(int ID)
{
	Node* ptr2Candidate = nullptr;
	return CandidateList::searchCandidate(ID, ptr2Candidate);
}

void CandidateList::printCandidateName(int ID) const
{

}

void CandidateList::printAllCandidates() const
{

}

void CandidateList::printKingdomVotes(int ID, int kingdom) const
{

}

void CandidateList::printCandidateTotalVotes(int ID) const
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
bool CandidateList::searchCandidate(int ID, Node*& ptrToCandidate)
{
	if (this->isEmpty())
		cerr << "=> List is empty. " << endl;
	
	bool found = false;
	Node* temp = first;

	while (!found)
	{
		if (temp->getCandidate().getID() == ID)
		{
			ptrToCandidate = temp;
			found = true;
		}
		else
			temp = temp->getLink();
	}

	return found;
}