//this file is to store the class "SecondFloor" and the function definations in it
#ifndef SECONDFLOOR_H
#define SECONDFLOOR_H
#include"Action.h"
#include <iostream>
#include <string>
 
using namespace std;

		//class declaration
class SecondFloor{
		private:
		Action SecondFloorAction;
	public:
		SecondFloor();
		~SecondFloor();
		void desSecondFloor();
		string getAction();
};

		//constructor
SecondFloor::SecondFloor(){
	SecondFloorAction.appendAction("BACK");
	SecondFloorAction.appendAction("STUDYROOM");
	SecondFloorAction.appendAction("ATTIC");
	SecondFloorAction.appendAction("TOILET");
	SecondFloorAction.appendAction("BOYS ROOM");
	
}

		//destructor
SecondFloor::~SecondFloor(){
	
}

		//description of second floor
void SecondFloor::desSecondFloor(){
	cout<<"\n--------------------------------------------------------------------------------\n";
	cout<<"Current location: SECOND FLOOR\n\n";
	cout<<"As you ascended the stairs, you emerged into a corridor that branched out into\n";  
	cout<<"multiple rooms.\n"; 
	cout<<"\nASCII:\"To the left you noticed a door to the BOYS ROOM, adjacent to\n";  
	cout<<"the boy's bedroom is a door to small but essential space - the TOILET. Further\n"; 
	cout<<"down the corridor, is the entrance to the STUDYROOM. Lastly, above you is a dark\n"; 
	cout<<"and eerie ATTIC.\n";
	cout<<"\n--------------------------------------------------------------------------------\n";
	
}

		//determine the action based on the commands
string SecondFloor::getAction(){
	string input;

	cout<<">";
	getline(cin, input);
	
	if(input == "BACK" || input == "ATTIC" || input == "TOILET" || input == "STUDYROOM" || input == "BOYS ROOM"|| input == "INVENTORY"){
		return input;
	}
	else if(input=="SAVE"){
		cout<< "\n ASCII: \" So close, yet so far. Go LIVING ROOM to SAVE. \" \n\n";
		input = "SANITY";
		return input;
	}
	else{
		cout << "\n ASCII:\"I bet we can't do that.\"\n\n";
		input = "SANITY";
		return input;
	}
}
#endif
