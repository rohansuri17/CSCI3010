#include "ElectoralMap.h"
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <iterator>
#include <random>
#include <stdlib.h>
#include <time.h>
/**
    Returns party object as a string

    @param Party object 
    @return party object as a string
*/
string Stringify(Party p) 
{
	if (p == Party::party1){

    	return "PartyOne";
	}
    if (p == Party::party2){

    	return "PartyTwo";
    }
    if (p == Party::party3){

    	return "PartyThree";
    }
    if (p == Party::partyNone){

    	return "PartyNone";
    }

	return "Error"; 
}
vector<Party> parties = {Party::party1, Party::party2, Party::party3, Party::partyNone};

/**
Overloaded  constructor for District initializing constituents and area
*/
District::District(int id, map<Party,int> constituents, int a)
{
	id_ = id;
	constituents_ = constituents;
	area_ = a;
}
/**
    Returns None

    @param integer id for the district id
    @return None
*/
void District::SetId(int id)
{
	id_ = id;

}
/**
    Returns integer district id

    @param None
    @return integer district id
*/
int District::GetId()
{
	return id_;
}
/**
    Returns integer area in sq miles

    @param None
    @return integer area in sq miles
*/
int District::GetArea() const
{
	return area_;
	
}
/**
    Returns Map from a party object to an integer

    @param None
    @return Map from a party object to an integer
*/
map<Party, int>* District::get_constituents()
{
	return &constituents_;
}

std::ostream& operator<<(std::ostream& os, District& d)
{

	map<Party, int> *constituents = d.get_constituents();
    os << "square miles: "+ to_string(d.GetArea()) + "\n";
    string Party_info="";
	for(auto it = constituents->begin(); it != constituents->end(); it++)
	{
		Party_info += "[Party: "+Stringify(it->first)+"] : "+ to_string(it->second)+"\t";
	}
    os<< Party_info;

    return os;
}
/**
Default constructor for Electoral Map initializing constituents parties and districts
*/
ElectoralMap::ElectoralMap()
{
	srand (time(NULL));
	for(int i = 1 ; i <= num_districts_; i++)
	{	
		map<Party,int> constituent;

		vector<Party> parties = {Party::party1, Party::party2, Party::party3, Party::partyNone};

		for(auto p : parties)
		{
	 		
	 		constituent[p] = rand()%10; 
	 	}

	 	int area = (rand()% 25) + 5;
	 	District *d = new District(i,constituent,area);
	 	district_map_.insert(std::pair<int,District*>(d->GetId(),d));

		

	}

}
/**
    Returns Instance of singleton electoral map class object

    @param None
    @return Instance of singleton electoral map class object
*/
ElectoralMap& ElectoralMap::GetInstance()
{
	static ElectoralMap instance;
    return instance;
}
/**
    Returns map from an integer to a district aka our private variable district_map_

    @param None
    @return map from an integer to a district aka our private variable district_map_
*/
map<int, District*> ElectoralMap::GetDistrict() const 
{
	return district_map_;

}
/**
    Returns integer number of districts

    @param None
    @return integer number of districts
*/
int ElectoralMap::GetNumDistricts()
{
	return num_districts_;

}
/**
    Returns integer with a vote for a specific district

    @param int number of constituents for that district and int constituents for all districts
    @return integer number of districts
*/
int ElectoralMap::GetVote(int constituents_one, int constituents_all)
{
	float result = (constituents_one*1.0)/(constituents_all);
	return floor(result*(5*num_districts_));
}

std::ostream& operator<<(std::ostream& os, const ElectoralMap &m)
{
	map<int, District *> district = m.GetDistrict();

	for(auto it = district.begin(); it != district.end(); it++)
	{
      District *d = it->second;
      os << "District "<< to_string(it->first) << ":\n";
      os << *(d) <<endl;
	}
return os;
}



