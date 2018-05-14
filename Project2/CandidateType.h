/*
	CodeMD
	
	Nguyen, Michael
	Dang, Demi
	
	CS A250: Project 1
*/

#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H

#include "PersonType.h"

using namespace std; 

const int NUM_OF_DIVISIONS = 4; 

class CandidateType : public PersonType
{
public:
	CandidateType(); 

	void updateVotesByDivision(int numDivision, int numVotes);

	int getTotalVotes() const;
	int getVotesByDivision(int numDivision) const;

	void printCandidateInfo() const; 
	void printCandidateTotalVotes() const;
	void printCandidateDivisionVotes(int numDivision) const;

	~CandidateType();

private:
	int totalVotes;
	int divisions[NUM_OF_DIVISIONS] = { 0 };
};


#endif
