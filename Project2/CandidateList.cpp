/*
	CodeMD
	
	Nguyen, Michael
	Dang, Demi
	
	CS A250: Project 1
*/

#include "CandidateList.h"

using namespace std; 

CandidateList::CandidateList() { candidates = new vector<CandidateType>; }

CandidateList::CandidateList(const CandidateList& otherList)
{
    candidates = new vector<CandidateType>;
    candidates->assign(otherList.candidates->begin(),otherList.candidates->end());
}

CandidateList& CandidateList::operator=(const CandidateList& otherList)
{
    candidates->assign(otherList.candidates->begin(),otherList.candidates->end());
    return *this;
}

void CandidateList::addCandidate(const CandidateType& candidate)
{
    candidates->push_back(candidate);
}

int CandidateList::getWinner() const
{
    vector<CandidateType>::const_iterator iter = candidates->cbegin();
    vector<CandidateType>::const_iterator iterEnd = candidates->cend();
    vector<CandidateType>::const_iterator iterPrev = iter;
    iter++;
    
    while (iter != iterEnd)
    {
        if (iter->getTotalVotes() > iterPrev->getTotalVotes()) iterPrev = iter;
        iter++;
    }
    return iterPrev->getSSN();
}

bool CandidateList::searchCandidate(int ssn) const
{
    vector<CandidateType>::const_iterator iter = candidates->cbegin();
	return searchCandidate(ssn, iter);
}

bool CandidateList::isEmpty() const
{
    return (candidates->size() == 0);
}

void CandidateList::printCandidateName(int ssn) const
{
    vector<CandidateType>::const_iterator candidate = candidates->cbegin();
    if(searchCandidate(ssn, candidate))
        candidate->printName();
}

void CandidateList::printAllCandidates() const
{
	vector<CandidateType>::const_iterator candidate = candidates->cbegin();
    vector<CandidateType>::const_iterator iterEnd = candidates->cend();
    while (candidate != iterEnd)
    {
        candidate->printCandidateInfo();
        cout << endl;
        candidate++;
    }
}

void CandidateList::printCandidateDivisionVotes(int ssn, int numDivision) const
{
    vector<CandidateType>::const_iterator candidate = candidates->cbegin();
    if(searchCandidate(ssn, candidate))
    {
        cout << "    => Division " << numDivision << ": "
            << candidate->getVotesByDivision(numDivision) << endl;
    }
}

void CandidateList::printCandidateTotalVotes(int ssn) const
{
    vector<CandidateType>::const_iterator candidate = candidates->cbegin();
    if(searchCandidate(ssn, candidate))
    {
        cout << "    => Total Votes: " <<
            candidate->getTotalVotes() << endl;
    }
}

CandidateList::~CandidateList()
{
    delete candidates;
    candidates = nullptr;
}

bool CandidateList::searchCandidate(int ssn, vector<CandidateType>::const_iterator & candidate) const
{
    candidate = candidates->begin();
    
    vector<CandidateType>::const_iterator iterEnd = candidates->cend();
    
    while (candidate != iterEnd)
    {
        if (candidate->getSSN() == ssn)
            return true;
        candidate++;
    }
    cerr << "    => SSN not in the list." << endl;
    return false;
}
