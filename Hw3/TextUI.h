#ifndef _TEXT_UI_H_
#define _TEXT_UI_H_
#include "Election.h"
#include <iostream>

using namespace std;

class TextUI
{
	public:
		TextUI();
		string MainMenu();
		void RouteChoice(string choice);
	private:
		vector<string> election_types;


};
#endif