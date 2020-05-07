/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Catillio, Edgar (TTh 6:30)

		 Wednesday May 6, 2020

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
	CandidateType& getWinner() const;

	// isEmpty
	// searchCandidate
	bool isEmpty();
	bool searchCandidate(int ID);

	// printCandidateName
	// printAllCandidates
	// printKingdomVotes
	// printCandidateTotalVotes
	// printFinalResults
	void printCandidateName() const;
	void printAllCandidates() const;
	void printKingdomVotes() const;
	void printCandidateTotalVotes() const;
	void printFinalResults() const;
	
	// clearList
	void clearList();

	// Destructor
	~CandidateList();

private:
	// searchCandidate
	bool searchCandidate(int ID, Node* ptr);
	
	Node *first; 	// pointer to the first candidate in the list
	Node *last;		// pointer to last candidate in the list
	int count;		// number of candidates in the list	
};

#endif