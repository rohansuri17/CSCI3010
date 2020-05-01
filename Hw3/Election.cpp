#include <iostream>
#include <iterator>
#include <algorithm>
#include "Election.h"
//https://thispointer.com/finding-all-values-for-a-key-in-multimap-using-equals_range-example/
//Used this resource for multimap 
using namespace std;
/**
Default constructor for Election
*/
Election::Election()
{

}
/**
    Returns None

    @param Party object and an integer id
    @return None
*/
void Election::Campaign(Party party, int id)
{
    District *d = e.GetDistrict()[id];
    map<Party, int> *constituent = d->get_constituents();
	float party1_votes = 0.0;
	float party2_votes = 0.0;
	float party3_votes = 0.0;
	float partyNone_votes = 0.0;
	float p_success = 0.0;
	float p_extra_success = 0.0;
	for(map<Party, int>::iterator it = constituent->begin(); it!= constituent->end(); it++)
	{
		if(it->first==Party::party1)
		{
			party1_votes+=it->second;

		}
		if(it->first==Party::party2)
		{
			party2_votes+=it->second;

		}
		if(it->first==Party::party3)
		{
			party3_votes+=it->second;

		}
		if(it->first==Party::partyNone)
		{
			partyNone_votes+=it->second;

		}
	

	}
	std::cout<<party1_votes<<"Party 1"<<std::endl;
	std::cout<<party2_votes<<"Party2"<<std::endl;
	std::cout<<party3_votes<<"Party3"<<std::endl;
	std::cout<<partyNone_votes<<"PartyNone"<<std::endl;

	if(party==Party::party1)
	{
		p_success = (((party1_votes+1)*2)/(party2_votes+party3_votes));//
		p_success*=(((party1_votes+1)*2)/d->GetArea());
		p_success*=100;
		p_success = std::min(float(100.0),p_success);

	}
	else if(party==Party::party2)
	{
		p_success = (((party2_votes+1)*2)/party1_votes+party3_votes);
		p_success*=(((party2_votes+1)*2)/d->GetArea());
		p_success*=100;
		p_success = std::min(float(100.0),p_success);
	}
	else if(party==Party::party3)
	{
		p_success = (((party3_votes+1)*2)/party1_votes+party2_votes);
		p_success*=(((party3_votes+1)*2)/d->GetArea());
		p_success*=100;
		p_success = std::min(float(100.0),p_success);
	}
	//p_success = (((party1_votes+1)*2)/party2_votes)*(((party1_votes+1)*2)/d->GetArea());
	std::cout<<"Chances to convert: "<<p_success<<std::endl;
	std::cout<<"Chances to convert from another party: "<<p_success*0.1<<std::endl;
	int prob = rand()%100 + 1;
	//std::cout<<prob<<"Random Probability"<<std::endl;
	if(prob < p_success)
	{

		if(constituent->at(Party::partyNone) > 0)
		{
            constituent->at(Party::partyNone) -= 1;
            constituent->at(party) += 1;
            cout<<"Congratulations, you converted someone from none to "<<Stringify(party)<<endl;
        }
        else
        {
            cout<<"Sorry, no one in none to convert"<<endl;
        }
        map<int, District*> d2 = e.GetDistrict();
        Party majority_party;
       	for(auto it = d2.begin(); it!= d2.end();it++)
		{
	       	int max = 0; 
	       	map<Party,int>* c = (it->second)->get_constituents();
	       	for(auto it2 = c->begin(); it2!= c->end();it2++)
			{
				if(it2->second > max)
				{
					max = it2->second;
					majority_party = it2->first;
				}

			}
		}
        if(prob < (p_success*0.1))
		{
			if(party==Party::party1)
			{
				constituent->at(Party::party2)-=1;
				constituent->at(party) += 1;
				cout<<"Congratulations, you converted someone from "<<Stringify(majority_party)<<"to "<<Stringify(party)<<endl;

			}
			else if(party==Party::party2)
			{
				constituent->at(Party::party1)-=1;
				constituent->at(party) += 1;
				cout<<"Congratulations, you converted someone from "<<Stringify(majority_party)<<"to "<<Stringify(party)<<endl;

			}
			else if(party==Party::party3)
			{

			}
			
		}

		}
	//std::cout<<e<<endl;

	
	
}
/**
    Returns None

    @param None
    @return None
*/
void Election::CandidateRegistration()
{
	string input;
	cout<<"Do you want to register a candidate for party one (y or n)?";
	cin >> input;
	int id = 1;
	while(input == "y")
	{
		string name;
		cout<<"What is their name?";
		cin>>name;
		struct Candidate c = {name, Party::party1, id};
		candidates_.push_back(c);
		id++;
		cout<<"Do you want to register a candidate for party one (y or n)?";
		cin >> input;
		

	}
	string input2;
	cout<<"Do you want to register a candidate for party two (y or n)?";
	cin >> input2;
	while(input2 == "y")
	{
		string name2;
		cout<<"What is their name?";
		cin>>name2;
		struct Candidate c2 = {name2, Party::party2, id};
		candidates_.push_back(c2);
		id++;
		cout<<"Do you want to register a candidate for party two (y or n)?";
		cin >> input2;
	}
	string input3;
	cout<<"Do you want to register a candidate for party three (y or n)?";
	cin >> input3;
	while(input3 == "y")
	{
		string name3;
		cout<<"What is their name?";
		cin>>name3;
		struct Candidate c3 = {name3, Party::party3, id};
		candidates_.push_back(c3);
		id++;
		cout<<"Do you want to register a candidate for party three (y or n)?";
		cin >> input3;
	}
	//std::cout<<e<<std::endl;
	
}
/**
    Returns None

    @param None
    @return None
*/
void Election::ReportWinner()
{
	string input="-1";
	Candidate campaigner;
	int vote = 0;
	map<int,int> votes_in_district;
	cout<<"---------------------"<<endl;
	for(Candidate c: candidates_)
	{
		//cout<<c.name<<c.party_<<c.id_;
		cout<<c.id_<<": "<<c.name_<<" "<< "[Party: "<< Stringify(c.party_)<<"]"<<endl;
		
	}
	cout<<endl;

	while(stoi(input) != 0)
	{
		
		cout<<"Which candidate is campaigning (id) (0 to stop) ?";
		cin>>input;
		for(Candidate c : candidates_)
		{
			campaigner = c;
			if(c.id_==stoi(input))
			{
				cout<<e<<std::endl;
			}
		}
			string input2="-1";
		while(stoi(input2)!=0)
		{
			cout<<"Where is this candidate campaigning (id) (0 to stop) ?";
			cin>>input2;
			vote+=1;
			votes_in_district.insert(pair<int,int>(stoi(input2), vote));
			//std::cout<<campaigner.id_<<campaigner.name_<<std::endl;
			if(stoi(input2)!=0)
			{
				cout<<campaigner.name_<<" is campaigning in district "<<input2<<endl;
				Campaign(campaigner.party_,stoi(input2));
				cout<<e<<std::endl;
			}
			else
			{
				cout<<"---------------------"<<endl;

	    		for(Candidate c: candidates_)
	    		{
	        		//cout<<c.name<<c.party_<<c.id_;
	        		cout<<c.id_<<": "<<c.name_<<" "<< "[Party: "<< Stringify(c.party_)<<"]"<<endl;
	    		}
	    		cout<<endl;
			}
		}

		
	}
	map<int, District*> d = e.GetDistrict();
	Party majority_party;
	int partynone_votes = 0;
	vector<pair<string,int>> winner;
	multimap<string, int>result;
	
	for(auto it = d.begin(); it!= d.end();it++)
	{
		std::cout<<"District: "<< it->first<<endl;
		for (int i = 0; i < candidates_.size(); i++)
		{
			candidates_[i].votes_ = 0;
		}

		map<Party,int>* constituents = (it->second)->get_constituents();
		partynone_votes = 0;
		for (int i = 0; i < candidates_.size(); i++)
		{

			for(auto it2 = constituents->begin(); it2!= constituents->end();it2++)
			{

				if(candidates_[i].party_==it2->first)
				{
					candidates_[i].votes_+=it2->second;
					/*for(int j = i+1; j < candidates_.size();j++)
					{

						if(candidates_[i].party_==candidates_[j].party_)
						{

						}

					}
					*/
				}

				
				int max = 0;
				for(auto it3 = constituents->begin(); it3!= constituents->end();it3++)
				{
					if(it3->second > max)
					{
						max = it3->second;
						majority_party = it3->first;
					}

				}
				//cout<<Stringify(majority_party)<<"majority_party"<<endl;
			}
		}
		for(auto it3 = constituents->begin(); it3!= constituents->end();it3++)
		{
			if(it3->first==Party::partyNone)
			{
				partynone_votes+=it3->second;	
			}

		}

		//std::cout<<partynone_votes<<"PARTY NONE VOTES"<<endl;
		for(int j = 0; j < candidates_.size();j++)
		{
			if(candidates_.at(j).party_==majority_party)
			{
				candidates_.at(j).votes_+=partynone_votes;
			}
		}

		
		for (int k = 0; k < candidates_.size(); k++)
		{
			result.insert(pair<string, int> (candidates_[k].name_, candidates_[k].votes_));
			std::cout<<candidates_.at(k).name_<<": "<< candidates_.at(k).votes_<<endl;
		}
	}
	typedef std::multimap<string, int>::iterator MMAPIterator;
	cout<<endl;
	cout<<endl;
	std::cout<<"Full Results "<<endl;
	for(int i = 0 ; i < candidates_.size();i++)
	{
		int votes = 0;
		std::pair<MMAPIterator, MMAPIterator> r = result.equal_range(candidates_.at(i).name_);
		for (MMAPIterator it = r.first; it != r.second; it++)
		{
			votes+=it->second;


		}
		std::cout<<candidates_.at(i).name_<<": "<<votes<<endl;
		winner.push_back(pair<string,int>(candidates_.at(i).name_,votes));	
	}
	int win_votes = -1;
	string winner_name;
	for(const auto& i : winner)
	{
		if(get<1>(i) > win_votes)
		{
			win_votes = get<1>(i);
			winner_name = get<0>(i);
		}


	}
	cout<<endl;
	std::cout<<"Congratulations, "<<winner_name<<", you've won!"<<endl;

}
		
/**
    Returns None

    @param None
    @return None
*/
void RepresentativeElection::ReportWinner()
{
	string input="-1";
	Candidate campaigner2;
	int vote = 0;
	map<int,int> votes_in_district_r;
	cout<<"---------------------"<<endl;
	for(Candidate c: candidates_)
	{
		//cout<<c.name<<c.party_<<c.id_;
		cout<<c.id_<<": "<<c.name_<<" "<< "[Party: "<< Stringify(c.party_)<<"]"<<endl;
	}
	cout<<endl;

	while(stoi(input) != 0)
	{
		
		cout<<"Which candidate is campaigning (id) (0 to stop) ?";
		cin>>input;
		for(Candidate c : candidates_)
		{
			campaigner2 = c;
			if(c.id_==stoi(input))
			{
				cout<<e<<std::endl;
			}
		}
			string input2="-1";
		while(stoi(input2)!=0)
		{
			cout<<"Where is this candidate campaigning (id) (0 to stop) ?";
			cin>>input2;
			vote+=1;
			votes_in_district_r.insert(pair<int,int>(stoi(input2), vote));
			//std::cout<<campaigner.id_<<campaigner.name_<<std::endl;
			if(stoi(input2)!=0)
			{
				cout<<campaigner2.name_<<" is campaigning in district "<<input2<<endl;
				Campaign(campaigner2.party_,stoi(input2));
				std::cout<<e<<std::endl;
			}
			else
			{
				cout<<"---------------------"<<endl;

	    		for(Candidate c: candidates_)
	    		{
	        		//cout<<c.name<<c.party_<<c.id_;
	        		cout<<c.id_<<": "<<c.name_<<" "<< "[Party: "<< Stringify(c.party_)<<"]"<<endl;
	    		}
	    		cout<<endl;
			}
		}

		
	}


	map<int, District*> d = e.GetDistrict();
	Candidate MajorityCandidate;
	Party majority_party;
	int partynone_votes = 0;
	vector<pair<string,int>> winner;
	multimap<string, int>result;
	int constituents_in_district = 0;
	int constituents_all_districts = 0;
	int max = 0;
	for(auto it = d.begin(); it!= d.end();it++)
	{
		map<Party,int> *c = it->second->get_constituents();
		for(auto it2 = c->begin(); it2!= c->end();it2++)
		{
			constituents_all_districts+=it2->second;

		}
		std::cout<<"District: "<< it->first<<endl;
		for (int i = 0; i < candidates_.size(); i++)
		{
			candidates_[i].votes_ = 0;
		}

		map<Party,int>* constituents = (it->second)->get_constituents();
		partynone_votes = 0;
		for (int i = 0; i < candidates_.size(); i++)
		{
			constituents_in_district = 0;
			max = 0;

			for(auto it2 = constituents->begin(); it2!= constituents->end();it2++)
			{

				if(candidates_[i].party_==it2->first)
				{
					candidates_[i].votes_+=it2->second;
				}
				constituents_in_district+=it2->second;

				
				if(it2->second > max)
				{
					max = it2->second;
					majority_party = it2->first;
				}

				//cout<<Stringify(majority_party)<<"majority_party"<<endl;
			}
			if(candidates_.at(i).party_==majority_party)
			{
				//candidates_.at(j).votes_+=partynone_votes;
				candidates_.at(i).votes_ = e.GetVote(constituents_in_district,constituents_all_districts);
			}
			else
			{
				candidates_.at(i).votes_ = 0;
			}
			result.insert(pair<string, int> (candidates_[i].name_, candidates_[i].votes_));
			std::cout<<candidates_.at(i).name_<<": "<< candidates_.at(i).votes_<<endl;
		}
	}
	typedef std::multimap<string, int>::iterator MMAPIterator;
	cout<<endl;
	cout<<endl;
	std::cout<<"Full Results "<<endl;
	for(int i = 0 ; i < candidates_.size();i++)
	{
		int votes = 0;
		std::pair<MMAPIterator, MMAPIterator> r = result.equal_range(candidates_.at(i).name_);
		for (MMAPIterator it = r.first; it != r.second; it++)
		{
			votes+=it->second;


		}
		std::cout<<candidates_.at(i).name_<<": "<<votes<<endl;
		winner.push_back(pair<string,int>(candidates_.at(i).name_,votes));	
	}
	int win_votes = -1;
	string winner_name;
	for(const auto& i : winner)
	{
		if(get<1>(i) > win_votes)
		{
			win_votes = get<1>(i);
			winner_name = get<0>(i);
		}


	}
	cout<<endl;
	std::cout<<"Congratulations, "<<winner_name<<", you've won!"<<endl;


}