/*
		OOPS
		 Iacob, Marius (TTh 6:30)
		 Castillo, Edgar (TTh 6:30)

		 Monday May 18, 2020

		 CS A250
		 Project 1 - Revised
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
	CandidateList() : first(nullptr), last(nullptr), count(0) {};

	// addCandidate
	void addCandidate(const CandidateType& candidate);

	// getWinner
	int getWinner() const;

	// isEmpty
	// searchCandidate
	bool isEmpty() const;
	bool searchCandidate(int id) const;

	// printCandidateName
	// printAllCandidates
	// printKingdomVotes
	// printCandidateTotalVotes
	void printCandidateName(int id) const;
	void printAllCandidates() const;
	void printKingdomVotes(int id, int kingdom) const;
	void printCandidateTotalVotes(int id) const;
	void printFinalResults() const;

	// Destructors
	void clearList();
	~CandidateList();

private:
	// searchCandidate
	bool searchCandidate(int ID, Node*& ptrToCandidate) const;
	
	Node *first; 	// pointer to the first candidate in the list
	Node *last;		// pointer to last candidate in the list
	int count;		// number of candidates in the list	
};

#endif
