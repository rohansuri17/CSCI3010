#ifndef _ELECTION_H_
#define _ELECTION_H_
#include "ElectoralMap.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Candidate
{
	string name_;
	Party party_;
	int id_;
	int votes_;
};
class Election
{
	public:
		Election();
		void CandidateRegistration();
		void Campaign(Party party, int id);
		virtual void ReportWinner();
	protected:
		ElectoralMap & e = ElectoralMap::GetInstance();
		vector<Candidate> candidates_;


};

class RepresentativeElection: public Election
{
	public:
		RepresentativeElection():Election(){};
		void ReportWinner();
};
#endif