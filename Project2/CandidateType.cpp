/*
	CodeMD
	
	Nguyen, Michael
	Dang, Demi
	
	CS A250: Project 1
*/

#include "CandidateType.h"

CandidateType::CandidateType() : totalVotes(0), PersonType() {}

void CandidateType::updateVotesByDivision(int numDivision, int numVotes) 
{
	divisions[numDivision] += numVotes;
	totalVotes += numVotes; 
}

int CandidateType::getTotalVotes() const
{
	return totalVotes;
}

int CandidateType::getVotesByDivision(int numDivision) const
{
	return divisions[numDivision - 1];
}

void CandidateType::printCandidateInfo() const
{
	if (getSSN() == 0) cout << "No information available for this candidate.";
	else
	{
		printSSN();
		cout << " - ";
		printName();
	}
}

void CandidateType::printCandidateTotalVotes() const
{
	printName();
	cout << "\n=> Total Votes (all divisions): " << totalVotes;
}

void CandidateType::printCandidateDivisionVotes(int numDivision) const
{
	printName();
	cout << "\n=> Division " << numDivision << " total votes: "
		<< divisions[numDivision - 1]; 
}

CandidateType::~CandidateType()
{}