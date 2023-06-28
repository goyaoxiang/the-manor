//this file is to store the class "Attic" and the function defination in it
#ifndef ATTIC_H
#define ATTIC_H
#include "Action.h"
#include <iostream>
#include <string>

using namespace std;

		//class declaration
class Attic{
	private:
		Action AtticAction;
		
	public:
		Attic();
		~Attic();
		void desAttic();
		void lockedAttic();
		void candlelessAttic();
		void desHint();
		void deleteAction(string i){
			AtticAction.deleteAction(i);
		};
		void appendAction(string i){
			AtticAction.appendAction(i);
		};
		bool searchAction(string i){
			AtticAction.searchAction(i);
		};
		string getAction();
		string getCandleless();
		bool getKey();

};

		//constructor
Attic::Attic(){
	AtticAction.appendAction("HINT");
	AtticAction.appendAction("KEY");
	AtticAction.appendAction("BACK");
}

		//destructor
Attic::~Attic(){
	
}

		//description of attic
void Attic::desAttic(){
	cout<<"\n----------------------------------------------------------------------------------\n";
	cout<<"Current location: ATTIC\n\n";
	cout<<"Crik-Crack, Crik-Crack, you reached the top of the attic with a candle in your hand.\n"; 
	cout<<"The flickering candle casting eerie shadows along the walls, you carefully surveyed\n"; 
	cout<<"the attic and notice a KEY stacked on top of a note, could it be a HINT?\n"; 
	cout<<"\n----------------------------------------------------------------------------------\n";
}

		//description when the door is locked
void Attic::lockedAttic(){
	cout<<"\n--------------------------------------------------------------------------------\n";
	cout<<"Current location: SECOND FLOOR\n\n";
	cout<<"As you arrived below the attic, the gap between the floor and the attic entrance\n"; 
	cout<<"seemed unreachable. You need a LADDER  to gain further access to the attic, it is\n"; 
	cout<<"probably hidden somewhere in one of the rooms.\n";
	cout<<"\n--------------------------------------------------------------------------------\n";

}

		//description when it's no candle
void Attic::candlelessAttic(){
	cout<<"\n---------------------------------------------------------------------------\n";
	cout<<"Current location: ATTIC\n\n";
	cout<<"Reaching the top, you emerged into a dark and eerie atmosphere of the attic.\n"; 
	cout<<"You cannot see anything, perhaps you need a source of light.\n";
	cout<<"\n---------------------------------------------------------------------------\n";

}

		//description for the hint
void Attic::desHint(){
	cout<<" \n************************************************\n";
	cout<<"X                                               X\n";
	cout<<"X Dear Tyler,                                   X\n";
	cout<<"X                                               X\n";
	cout<<"X    When you see this message, I'm already     X\n";
	cout<<"X    long gone,devoured by the entity that      X\n";
	cout<<"X    haunts this place.                         X\n";
	cout<<"X    I have one last thing left                 X\n";
	cout<<"X    for you. \"-15 holds the key\". Never        X\n";
	cout<<"X    overlook the mudane places, as it holds    X\n";
	cout<<"X    the most needed thing that you might       X\n";
	cout<<"X    need, I wish you all the best.             X\n";
	cout<<"X                                               X\n";
	cout<<"X                                               X\n";
	cout<<"X                             Yours sincerely,  X\n";
	cout<<"X                                      Ascii    X\n";
	cout<<" ************************************************\n\n";
}

		//return the status of action "KEY"
bool Attic::getKey(){
	return !(AtticAction.searchAction("KEY"));
}

		//to determine the action based on the commands
string Attic::getAction(){
	string input;
	do{
		cout<<">";
		getline(cin,input);
		
		if(input=="KEY" && AtticAction.searchAction("KEY")){
			AtticAction.deleteAction("KEY");
			cout << "\n====================================\n";
			cout<<"       __           \n";
 			cout<<"      /o \\_____     \n";
  			cout<<"      \\__/-=\"=\"`    \n";
  			cout << "\n====================================\n";
			cout<<"\nObtained KEY to open some door....\n\n";
			input = "";
		}
		else if(input=="KEY" && !AtticAction.searchAction("KEY")){
			cout<<"\nSeems like you already got the item in your inventory....\n\n";
			input = "";
		}
		else if(input == "HINT" && AtticAction.searchAction("HINT")){
			desHint();
			input = "";
		}
		else if(input == "BACK" || input == "INVENTORY"){
			return input;
		}
		else if(input=="SAVE"){
			cout<<"\n ASCII: \"Ah...I see..You really like to stay in such dark and scary places, aren't you?.Go back LIVING ROOM to SAVE!!\"\n\n";
			input="SANITY";
			return input;
		}
		else{
			cout << "\n ASCII:\"I bet we can't do that.\"\n\n";
			input = "SANITY";
			return input;
		}
	}while(input == "");
}

		//to determine the action based on the command when there is no candle
string Attic::getCandleless(){
	string input;

	cout << ">";
	getline(cin, input);
	
	if(input == "BACK" || input == "INVENTORY"){
		return input;
	}
	else if(input =="SAVE"){
		cout<<"\n ASCII: \" Really? Try to save when you can't see anything? Go back LIVING ROOM to SAVE\"\n\n";
		candlelessAttic();
		input="SANITY";
		return input;
	}
	else{
		candlelessAttic();
		input = "SANITY";
		return input;
	}
}

#endif
