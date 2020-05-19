/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Castillo, Edgar (TTh 6:30)

		 Monday May 18, 2020

		 CS A250
		 Project 1 - Revised
*/

#include "CandidateList.h"

using namespace std;

// Function declarations
// Same order as in class definition

void CandidateList::addCandidate(const CandidateType& candidate)
{
	// If the list is empty..
	if (!count)
		first = last = new Node(candidate, nullptr); // Assign 'candidate' to --first & --last
	else // Else,...
	{
		// Assing 'candidate' to --last->--link
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
		cerr << "    => List is empty.\n" << endl;
		return 0;
	}
	else
	{
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
}

bool CandidateList::isEmpty() const
{
	// Use ternary operator...
	return count == 0 ? true : false;
}

// Public Search function
bool CandidateList::searchCandidate(int iD) const
{
	Node* ptr2Candidate = nullptr;
	return searchCandidate(iD, ptr2Candidate);
}

void CandidateList::printCandidateName(int iD) const
{
	Node* ptr2Candidate = nullptr;
	if (searchCandidate(iD, ptr2Candidate))
	{
		ptr2Candidate->getCandidate().printName();
	}
}

void CandidateList::printAllCandidates() const
{
	if (!count)
		cerr << "List is empty.\n" << endl;
	else
	{
		Node* temp = first;

		while (temp != nullptr)
		{
			temp->getCandidate().printID();
			cout << " - " << temp->getCandidate().getLastName()
				<< ", " << temp->getCandidate().getFirstName() << "\n";
			temp = temp->getLink();
		}
	}
}

void CandidateList::printKingdomVotes(int iD, int kingdom) const
{
	Node* ptr2Candidate = nullptr;

	if (CandidateList::searchCandidate(iD, ptr2Candidate))
	{
		// Format output here
		cout << right << setw(5) << setfill(' ') 
			<< "*" << setw(3) << ptr2Candidate->getCandidate().getVotesByKingdom(kingdom)
			<< "( => )" << KINGDOMS[kingdom] << "\n";
	}
}

void CandidateList::printCandidateTotalVotes(int iD) const
{
	Node* ptr2Candidate = nullptr;

	if (searchCandidate(iD, ptr2Candidate))
	{
		cout << "    => Total votes: "
			<< ptr2Candidate->getCandidate().getTotalVotes() << endl;
	}
}

void CandidateList::printFinalResults() const
{
	if (!count)
		cerr << "    List is empty.\n";
	else
	{
		Node* temp = first->getLink();
		Node* temp2 = nullptr;
		int highest = first->getCandidate().getTotalVotes();

		// Find Candidate with Highest Votes
		while (temp != nullptr)
		{
			if (highest < temp->getCandidate().getTotalVotes())
			{
				highest = temp->getCandidate().getTotalVotes();
				temp2 = temp;
			}

			temp = temp->getLink();
		}
		// Reset --temp for re-use;
		temp = first;

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

		// Loop to print out Final results;
		for (int i = 1; i <= count; ++i)
		{
			// Print results; 
			cout << left << setw(15) << setfill(' ')
				<< temp2->getCandidate().getLastName() << setw(12)
				<< temp2->getCandidate().getFirstName() << setw(3)
				<< temp2->getCandidate().getTotalVotes() << right 
				<< setw(7) << i << "\n";

			// Put dashes in between every 5 Candidates
			if ((i > 4) && (!(i % 5)))
				cout << right << setw(40) << setfill('-') << "-\n";

			// Loop to find nextHigh to print
			while (temp != nullptr && 
				temp->getCandidate().getTotalVotes() != highest - 1)
			{
				if (temp->getCandidate().getTotalVotes() > highest)
				{
					temp2 = temp;
					highest = temp2->getCandidate().getTotalVotes();
				}	

				temp = temp->getLink();
			}

			temp = first;
		}
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
	first = last = nullptr;
}

CandidateList::~CandidateList()
{
	clearList();
}

// Overloaded Private Search function
bool CandidateList::searchCandidate(int iD, Node*& ptrToCandidate) const
{
	if (!count)
		cerr << "    => List is empty.\n" << endl;
	else
	{
		bool found = false;
		Node* temp = first;

		while (!found && (temp->getLink() != nullptr))
		{
			if (temp->getCandidate().getID() == iD)
			{
				ptrToCandidate = temp;
				found = true;
			}
			else
				temp = temp->getLink();
		}

		if (!found)
			cout << "    => ID not in the list.\n";

		return found;
	}
	
}