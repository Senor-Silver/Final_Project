/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Catillio, Edgar (TTh 6:30)

		 Wednesday May 6, 2020

		 CS A250
		 Project 1 - Part B
*/

#include "CandidateList.h"
#include <utility>
#include <map>
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

void CandidateList::printCandidateName(int ID)
{
	Node* ptr2Candidate = nullptr;
	if (CandidateList::searchCandidate(ID, ptr2Candidate))
	{
		ptr2Candidate->getCandidate().printName();
	}
}

void CandidateList::printAllCandidates()
{
	if (this->isEmpty())
		cerr << "List is empty. " << endl;

	Node* temp = first;

	while (temp->getLink() != nullptr)
	{
		temp->getCandidate().printCandidateInfo();
		temp = temp->getLink();
	}
}

void CandidateList::printKingdomVotes(int ID, int kingdom)
{
	Node* ptr2Candidate = nullptr;
	if (CandidateList::searchCandidate(ID, ptr2Candidate))
	{
		// Format output here
		cout << "\t*" << right << setw(3) << setfill(' ')
			<< ptr2Candidate->getCandidate().getVotesByKingdom(kingdom)
			<< "( => )" << KINGDOMS[kingdom] << "\n";
	}
		
}

void CandidateList::printCandidateTotalVotes(int ID) 
{
	Node* ptr2Candidate = nullptr;
	if (CandidateList::searchCandidate(ID, ptr2Candidate))
	{
		cout << "\t=> Total votes: "
		<< ptr2Candidate->getCandidate().getTotalVotes();
	}
}

void CandidateList::printFinalResults()
{
	// Create a Map containing <--totalVotes, --
	// Map has a nested Pair for ease of access to Name
	map<int, pair<string, string>> candMap;
	Node* temp = first;

	while (temp != nullptr)
	{
		// Creation of Map to gather info for output in Order
		// Will have to create a reverseIterator() 
		candMap.insert(make_pair(temp->getCandidate().getTotalVotes(),
					make_pair(temp->getCandidate().getLastName(),
						      temp->getCandidate().getFirstName())));

		temp = temp->getLink();
	}

	// Print Top of Table Before Results
	cout << right << setw(18) << setfill('*') << " FINAL"
		<< left << setw(21) << " RESULTS ";

	cout << left << setw(17) << setfill(' ') << "\n\nLAST"
		<< setw(10) << "FIRST"
		<< setw(5) << "TOTAL"
		<< right << setw(8) << "POS\n";

	cout << left << setw(15) << "NAME"
		<< setw(10) << "NAME"
		<< setw(5) << "VOTES"
		<< right << setw(8) << "#\n"
		<< setw(41) << setfill('_') << "_\n\n";

	// For Loop to print from Winner to Last with iomanipS
	// FOR loop to access Name and TtlVotes
	for (auto tableInfo : candMap)
	{
		cout << tableInfo.second.first << ", " << tableInfo.second.second
			<< "----" << tableInfo.first << "\n";
	}
}

// Destructor Methods
void CandidateList::clearList()
{
	// Delete all dynamic data
	// Set all member variables to default
	Node* temp = first;

	while (first != nullptr)
	{
		first = first->getLink();
		delete temp;
		temp = first;
	}

	count = 0;
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

	while (!found && (temp->getLink() != nullptr))
	{
		if (temp->getCandidate().getID() == ID)
		{
			ptrToCandidate = temp;
			found = true;
		}
		else
			temp = temp->getLink();
	}

	if (!found)
		cerr << "=> ID not in the list.";

	return found;
}