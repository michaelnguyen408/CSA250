/*
	CodeMD
	
	Nguyen, Michael
	Dang, Demi
	
	CS A250: Project 1
*/

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include<vector>

#include "CandidateType.h"

using namespace std;

class CandidateList
{
public:
	// Function declarations
	CandidateList(); 
    CandidateList(const CandidateList&);
    
    CandidateList& operator=(const CandidateList&);
    
	void addCandidate(const CandidateType& candidate);
	
	int getWinner() const;
	
	bool searchCandidate(int ssn) const;

    bool isEmpty() const;
    
	void printCandidateName(int ssn) const;
	void printAllCandidates() const; 
	void printCandidateDivisionVotes(int ssn, int numDivision) const;
	void printCandidateTotalVotes(int ssn) const;
    
	~CandidateList();

private:
    bool searchCandidate(int ssn, vector<CandidateType>::const_iterator &) const;

    vector<CandidateType>* candidates;
};

#endif
