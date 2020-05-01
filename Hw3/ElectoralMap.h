#ifndef _ELECTORALMAP_H_
#define _ELECTORALMAP_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum class Party{party1, party2, party3, partyNone};
string Stringify(Party p);


class District
{
	public:
		District(int id, map<Party,int> constituents, int a);
		void SetId(int id);
		int GetId();
		int GetArea() const;
		map<Party, int>* get_constituents();

		friend std::ostream& operator<<(std::ostream& os, const District& d);
	private:
		int id_;
		int area_;
    	map<Party, int> constituents_;

};

class ElectoralMap
{
	public:
		static ElectoralMap& GetInstance();
	    map<int, District*> GetDistrict() const;
	  	int GetNumDistricts();
	  	int GetVote(int constituents_one, int constituents_all);
	    friend std::ostream& operator<<(std::ostream& os, const ElectoralMap &m);
	private:
		ElectoralMap();
		map<int, District* > district_map_;
		static const int num_districts_ = 4;


};

#endif