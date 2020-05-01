#include "ElectoralMap.h"
#include "Election.h"
#include "TextUI.h"
#include <iostream>
#include <vector>
/**
Rohan Suri
Homework 3
This program is a super complicated election simulator similar to the presedential election. 
It runs both a direct(based on consituents votes) and representative election(based on overall district votes) 
depending on choice. We have districts, candidates,parties, and constiuents within the game divided up and 
utilized by 3 classes TextUI, ElectoralMap,Election, Run by typing make within this directory on your bash 
command line. Have fun!
*/
int main()
{
	//District d;
	//std::cout<<d<<endl;
	//std::cout<<d.get_id()<<endl;
	//std::cout<<d.get_area()<<endl;
	//ElectoralMap map = ElectoralMap::GetInstance();
	//map.add_districts();
	//std::cout<<map<<std::endl;
	/*std::cout<<map.get_num_districts()<<std::endl;
	/*std::cout<<map.get_vote(0)<<std::endl;
	std::cout<<map->get_district()<<std::endl;
	*/

	//Election e;
	//e.CandidateRegistration();
	//e.Campaign(Party::party1, 0);
	//e.ReportWinner();
	//RepresentativeElection r;
	//r.CandidateRegistration();
	//r.ReportWinner();
	TextUI sim;
	string input;
	while(input!="0")
	{
		input = sim.MainMenu();
		sim.RouteChoice(input);
	}



}