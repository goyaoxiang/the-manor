//this file is to store the class "Storage" and the function defination in it
#ifndef STORAGE_H
#define STORAGE_H
#include <iostream>
#include "Action.h"
#include <string>
using namespace std; 

		//class declaration
class Storage{
	private:
		Action StorageAction;
	public: 
		Storage();
		~Storage();
		void desStorage();
		void lockedStorage();
		void desLadder();
		void deleteAction(string i){
			StorageAction.deleteAction(i);
		};
		void appendAction(string i){
			StorageAction.appendAction(i);
		};
		bool searchAction(string i){
			StorageAction.searchAction(i);
		};
		string getAction();
		bool getLadder();
		
};

		//constructor
Storage::Storage(){
	StorageAction.appendAction("BACK");
	StorageAction.appendAction("LADDER");
	
}

		//destructor
Storage::~Storage(){
	
}

		//description of storage
void Storage :: desStorage(){
	cout<<"\n----------------------------------------------------------------------------------------------\n";
	cout<<"Current location: STORAGE\n\n";
	cout<<"You enter the storage room. The room was filled to the brim with an assortment of\n"; 
	cout<<"forgotten items and dusty relics. Boxes upon boxes were stacked haphazardly, their\n"; 
	cout<<"contents obscured by layers of cobwebs and time. Amongst the discarded furniture,\n"; 
	cout<<"you saw a old wooden LADDER, which seemed like it might be useful to access a\n"; 
	cout<<"specific area.\n";
	cout<<"\nASCII:\"That LADDER grant access to a part of the house, which will be very useful for you\n";
	cout<<"when exploring the manor later on.\"\n";
	cout<<"\n----------------------------------------------------------------------------------------------\n";

}

		//description when the door is blocked
void Storage::lockedStorage(){
	cout<<"\n---------------------------------------------------------------------------------------------------------------\n";
	cout<<"Current location: LIVING ROOM\n\n";
	cout<<"You stood in front of the door of the storage room, a barricade of wooden planks are\n";
	cout<<"firmly affixed to the door. The obstruction barred your entry to the storage room.\n"; 
	cout<<"\nASCII:\"You need a tool to remove the wooden planks here's a hint, you may consider checking the SECOND FLOOR\"\n";
	cout<<"\n----------------------------------------------------------------------------------------------------------------\n";
}

		//description for ladder
void Storage::desLadder(){
  	cout<<"    ||  || \n";
  	cout<<"    |____| \n";
  	cout<<"    ||  || \n";
  	cout<<"    |____| \n";
  	cout<<"    ||  || \n";
  	cout<<"    |____| \n";
  	cout<<"    ||  || \n";
  	cout<<"    |____| \n";
  	cout<<"    ||  || \n";
	cout<<"\nLadder obtained.\n";
	cout<<"ASCII: \"Seems like it is useful to climb up something.\"\n\n";
}

		//determine the action based on the commands
string Storage::getAction(){
	string input;
	do{
		cout<<">";
		getline(cin, input);
		
		if(input == "LADDER" && StorageAction.searchAction("LADDER")){
			StorageAction.deleteAction("LADDER");
			desLadder();
			input = "";
		}
		else if(input == "LADDER" && (!StorageAction.searchAction("LADDER"))){
			cout<<"\nIt's already in your inventory.\n\n";
			input = "";
		}
		else if(input == "BACK" || input == "INVENTORY"){
			return input;
		}
		else if(input=="SAVE"){
			cout<<"\nASCII:\"Yeah..I know storage room can store things but not your progress, go back LIVING ROOM to SAVE\"\n\n";
			input= "SANITY";
			return input;
		}
		else{
			cout << "\n I bet we can't do that.\n\n";
			input = "SANITY";
			return input;
		}
	}while(input == "");
}

		//return the status of the action "LADDER"
bool Storage::getLadder(){
	if(!StorageAction.searchAction("LADDER")){
		return true;
	}
	else{
		return false;
	}
}
	
#endif
	

