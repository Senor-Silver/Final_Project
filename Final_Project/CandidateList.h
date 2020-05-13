/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Castillo, Edgar (TTh 6:30)

		 Sunday, May 3, 2020

		 CS A250
		 Project 1 - Part B
*/

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"

#include <iostream>
#include <string>
#include <iomanip>

class Node
{
public:
	Node() : link(nullptr) {}
    Node(const CandidateType& newCandidate, Node *theLink) 
		: candidate(newCandidate), link(theLink){}
    Node* getLink( ) const { return link; }
	CandidateType getCandidate( ) const { return candidate; }
    void setCandidate(const CandidateType& newCandidate)
		{ candidate = newCandidate; }
    void setLink(Node *theLink) { link = theLink; }
	~Node() {}
private:
    CandidateType candidate;
    Node *link;		//pointer that points to next node
};

class CandidateList
{
public:
	// Default constructor
	CandidateList();

	// addCandidate
	void addCandidate(CandidateType& candidate);

	// getWinner
	int getWinner() const;

	// isEmpty
	// searchCandidate
	bool isEmpty();
	bool searchCandidate(int ID);

	// printCandidateName
	// printAllCandidates
	// printKingdomVotes
	// printCandidateTotalVotes
	// printFinalResults
	void printCandidateName(int ID);
	void printAllCandidates();
	void printKingdomVotes(int ID, int kingdom);
	void printCandidateTotalVotes(int ID);
	void printFinalResults();
	
	// clearList
	void clearList();

	// Destructor
	~CandidateList();

private:
	// searchCandidate
	bool searchCandidate(int ID, Node*& ptrToCandidate);
	
	Node *first; 	// pointer to the first candidate in the list
	Node *last;		// pointer to last candidate in the list
	int count;		// number of candidates in the list	
};

#endif
