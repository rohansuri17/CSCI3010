#include "TextUI.h"
#include "ElectoralMap.h"
#include "Election.h"
#include <iostream>
using namespace std;


TextUI::TextUI()
{


}
/**
    Returns string of user input

    @param None
    @return string of user input
*/
string TextUI::MainMenu()
{
	string input;
	cout<<"What kind of Election should we have (direct or representative, 0 to stop)?"<<std::endl;
	cin>>input;
	return input;

}
/**
    Returns none

    @param user input of string choice
    @return none
*/
void TextUI::RouteChoice(string choice)
{
	if(choice == "direct")
	{
		Election e;
		e.CandidateRegistration();
		e.ReportWinner();

	}
	else if(choice == "representative")
	{
		RepresentativeElection r;
		r.CandidateRegistration();
		r.ReportWinner();


	}

}