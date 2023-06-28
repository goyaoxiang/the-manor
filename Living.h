//this file is to store the class "LivingRoom" and the function defination in it
#ifndef LIVING_H
#define LIVING_H 
#include "Action.h"
#include <iostream>
#include <string>

using namespace std; 

		//class declaration
class LivingRoom{
	private: 
		Action LivingRoomAction;
	
	public: 
		LivingRoom();
		~LivingRoom();
		void desLiving();
		void showNote();
		bool searchAction(string i){
			return LivingRoomAction.searchAction(i);
		};
		void appendAction(string i){
			LivingRoomAction.appendAction(i);
		};
		void deleteAction(string i){
			LivingRoomAction.deleteAction(i);
		};
		string getAction();
};

		//constructor
LivingRoom::LivingRoom(){
		LivingRoomAction.appendAction("DINNING ROOM");
		LivingRoomAction.appendAction("MASTER BEDROOM");
		LivingRoomAction.appendAction("HALLWAY");
		LivingRoomAction.appendAction("STORAGE");
		LivingRoomAction.appendAction("NOTE");
		LivingRoomAction.appendAction("SECOND FLOOR");
		LivingRoomAction.appendAction("LEAVE");
		LivingRoomAction.appendAction("SAVE");
	
}

		//destructor
LivingRoom::~LivingRoom(){
	
}

		//description of livingroom
void LivingRoom::desLiving(){
	cout<<"\n-------------------------------------------------------------------------------------\n";
	cout<<"Current location: LIVING ROOM\n\n";
	cout<<"You are now in a spacious old living room filled with candles hanging on the wall,\n"; 
	cout<<"\nASCII:\"Towards your left is the entrance for you to go into the DINNING ROOM\n";  
	cout<<"Adjacent to it, is the door to the owner's MASTER BEDROOM, and a\n";  
	cout<<"broad HALLWAY stretching out before you. To your right, there is a STORAGE\n";
	cout<<"room awaiting for your exploration. At the corner of the living room is a stairway up\n";
	cout<<"to the SECOND FLOOR. There is a NOTE that I have specially left for you to read\n";
	cout<<"on top of the table. You can LEAVE when you think it's the time...Goodluck.'\"\n";
	cout<<"\nREMINDER: You can only SAVE your game's progress in the LIVING ROOM\n";
	cout<<"\n-------------------------------------------------------------------------------------\n";


}

		//function to show the note
void LivingRoom::showNote(){
	cout<<"\n*************************************************\n";
	cout<<"*                                               *\n";
	cout<<"*                                               *\n";
	cout<<"*                                               *\n";
	cout<<"*     Seeker of secrets                         *\n";
	cout<<"*     To unlock the next chapter,               *\n";
	cout<<"*     Transcribe your words with might,         *\n";
	cout<<"*     In the realm of UPPERCASE,                *\n";
	cout<<"*     Where power and clarity unite.            *\n";
	cout<<"*     Only then shall the path reveal,          *\n";
	cout<<"*     The enigma concealed within.              *\n";
	cout<<"*                                               *\n";
	cout<<"*                                               *\n";
	cout<<"*                                               *\n";
	cout<<"*                                With regards,  *\n";
	cout<<"*                                        Teh    *\n";
	cout<<"*************************************************\n\n";
	cout<<"This looks like a hint, It seemed that the next phase of your quest required the\n"; 
	cout<<"strength and resonance of UPPERCASE letters.\n\n\n";
}

		//function to determine the action based on the command
string LivingRoom::getAction() {
	string input = "SANITY";
	do {
		cout << ">";
		getline(cin,input);
		
		if (input == "NOTE" && LivingRoomAction.searchAction("NOTE")) {
			LivingRoomAction.deleteAction("NOTE");
			showNote();
			input = "";
		}
		else if (input == "HALLWAY" && LivingRoomAction.searchAction("HALLWAY")) {
			LivingRoomAction.deleteAction("HALLWAY");
		}
		else if (input == "NOTE" && !LivingRoomAction.searchAction("NOTE")) {
			cout << "\nSeems like we have done that...Let's move on...\n\n";
			input = "";
		}
		else if (input == "HALLWAY" && !LivingRoomAction.searchAction("HALLWAY")) {
			cout << "\n ASCII :\"I don't really want to experience that again.....Let's move on... \"\n\n";
			input = "";
		}
		else if(input == "LEAVE" || input == "INVENTORY" || input == "DINNING ROOM" || input == "MASTER BEDROOM" 
				|| input == "STORAGE" || input == "SECOND FLOOR" || input == "HALLWAY"||input=="SAVE"){
			return input;
		}
		else{
			cout << "\n ASCII:\"I bet we can't do that.\"\n\n";
			input = "SANITY";
			return input;
		}
	} while (input == "");

	return input;
}

#endif
