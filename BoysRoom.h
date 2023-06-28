//this file is to store the class "BoysRoom" and the function definations in it 
#ifndef BOYSROOM_H
#define BOYSROOM_H
#include "Action.h"
#include <iostream>
#include <string>
using namespace std; 

		//class declaration
class BoysRoom{
	private:
		Action BoysRoomAction;
		
	public:
		BoysRoom();
		~BoysRoom();
		void desBoysRoom();
		string getAction();
};

		//constructor
BoysRoom::BoysRoom(){
	BoysRoomAction.appendAction("BACK");
}

		//destructor
BoysRoom::~BoysRoom(){
	
}

		//description of boys room
void BoysRoom::desBoysRoom(){
	cout<<"\n------------------------------------------------------------------------------------------\n";
	cout<<"Current location: BOYS ROOM\n\n";
	cout<<"ASCII:\"I reckon you stay away from this room, last time I went in here, it did not end so well.\n";  
	cout<<"I prefer you to go BACK now before I hover a cold dead body again.\"\n";
	cout<<"\n------------------------------------------------------------------------------------------\n";
}

		//to determine the action based on the commands
string BoysRoom::getAction(){
	string input;

	cout<<">";
	getline(cin, input);
	
	if(input == "BACK" || input == "INVENTORY"){
		return input;
	}
	else if(input=="SAVE"){
		cout<<"\n ASCII: \" Seems like you are trying to get me in some business....Go back LIVING ROOM to SAVE\" \n\n";
		input= "SANITY";
		return input;
	}
	else{
		cout << "\n ASCII:\"I bet we can't do that.\"\n\n";
		input = "SANITY";
		return input;
	}
}

#endif
