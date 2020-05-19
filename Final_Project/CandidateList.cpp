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
	// Create a Map containing <--totalVotes, pair<--lastName, --firstName>>
	// Map has a nested Pair for ease of access to Name
	//map<int, pair<string, string>> candMap; 

	if (!count)
		cerr << "    List is empty.\n";
	else
	{
		Node* high = first;
		Node* traverse = first->getLink();
		int highest = first->getCandidate().getTotalVotes();

		// Find Candidate with Highest Votes
		for (int i = 1; i < count; ++i)
		{
			if (highest < traverse->getCandidate().getTotalVotes())
			{
				high = traverse;
				highest = traverse->getCandidate().getTotalVotes();
			}

			traverse = traverse->getLink();

			// Creation of Map to gather info for output in Order
			// Will have to create a reverseIterator() 
			//candMap.insert(make_pair(temp->getCandidate().getTotalVotes(),
						//make_pair(temp->getCandidate().getLastName(),
								  //temp->getCandidate().getFirstName())));
			//temp = temp->getLink();
		}
		// Reset --traverse for resuse;
		traverse = first;

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

		//int candidatePOSition = 0;
		//map<int, pair<string, string>>::
			//const_reverse_iterator revIter = candMap.crbegin();

		//for (revIter; revIter != candMap.crend(); ++revIter)
		int nextH = 0;

		// Loop to print out Final results;
		for (int j = 1; j <= count; ++j)
		{
			// Print results; 
			cout << left << setw(15) << setfill(' ')
				<< high->getCandidate().getLastName() << setw(12)
				<< high->getCandidate().getFirstName() << setw(3)
				<< high->getCandidate().getTotalVotes()
				<< right << setw(7) << j << "\n";

			// Put dashes in between every 5 Candidates
			if ((j > 4) && (!(j % 5)))
				cout << right << setw(40) << setfill('-') << "-\n";

			// Loop to find nextHigh to print
			while (nextH != highest - 1)
			{
				nextH = traverse->getCandidate().getTotalVotes();

				if (nextH < highest && nextH > highest)
				{
					highest = nextH;
					high = traverse;
				}	
				traverse = traverse->getLink();
			}
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