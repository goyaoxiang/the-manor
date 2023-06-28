//this file is to store the class "Study" and the function definations in it 
#ifndef STUDY_H
#define STUDY_H
#include"Action.h"
#include <iostream>
#include <string>

using namespace std;

		//class declaration
class Study{
	private:
		Action StudyAction;
		
	public:
		Study();
		~Study();
		void desStudy();
		void desCrowbar();
		void chairStudy();
		void obtCrowbar();
		void deleteAction(string i){
			StudyAction.deleteAction(i);
		};
		void appendAction(string i){
			StudyAction.appendAction(i);
		};
		bool searchAction(string i){
			StudyAction.searchAction(i);
		};
		string getAction();
		bool getCrowbar();
};

		//constuctor
Study::Study(){
	StudyAction.appendAction("BACK");
	StudyAction.appendAction("CROWBAR");
	StudyAction.appendAction("CHAIR");
}

		//destructor
Study::~Study(){
	
}

		//description of studyroom
void Study::desStudy(){
	cout<<"\n--------------------------------------------------------------------------------------------\n";
	cout<<"Current location: STUDYROOM\n\n";
	cout<<"In the study room, you spotted a CROWBAR on a high bookshelf. Knowing it could\n"; 
	cout<<"help remove the affixed wooden planks on the storage room door.\n"; 
	cout<<"ASCII:\"That CROWBAR is too high for you to reach it, you might need something to help you\n"; 
	cout<<"to reach it, that nearby CHAIR beside the table might come in handy.\"\n";
	cout<<"\n--------------------------------------------------------------------------------------------\n";
}

		//description for crowbar
void Study::desCrowbar(){
	cout<<"\nToo high for you to reach it, requires something for you to go up and get it, perhaps a CHAIR?\n\n";
}

		//description for chair
void Study::chairStudy(){
  	cout<<"      .-===-.  \n";
  	cout<<"      | . . |  \n";
  	cout<<"      | .'. |  \n";
  	cout<<"     ()_____() \n";
  	cout<<"     ||_____|| \n";
  	cout<<"      W     W  \n";
	cout<<"\n------------------------------------------------------------------------------------------\n";
	cout<<"With a grunt of effort, you positioned the chair beneath the bookshelf, ensuring its\n"; 
	cout<<"stability. Climbing onto its worn seat, you cautiously extended your hand towards the\n";
	cout<<"CROWBAR, its cold metal gleaming in the dim light.\n";
	cout<<"\nASCII:\"You just need to stretch your fingers a few more inches.\"\n";
	cout<<"\n------------------------------------------------------------------------------------------\n";
}

		//description when obtain crowbar
void Study::obtCrowbar(){
    cout<<"           /___\\          \n";
    cout<<"          //   \\         \n";
    cout<<"         //     \\        \n";
    cout<<"               //         \n";
    cout<<"               \\         \n";
    cout<<"                \\        \n";
    cout<<"                 \\       \n";
    cout<<"                  \\     \n";
    cout<<"                   \\    \n";
    cout<<"                    \\_/  \n";
	cout<<"\nCrowbar obtained !\n\n";
}

		//return the status of action "CROWBAR"
bool Study::getCrowbar(){
	return !(StudyAction.searchAction("CROWBAR"));
}

		//to determine the action based on the commands
string Study::getAction(){
	string input;
	do{
		cout << ">";
		getline(cin, input);
		
		if(input == "CHAIR" && StudyAction.searchAction("CHAIR")){
			StudyAction.deleteAction("CHAIR");
			chairStudy();
			input = "";
		}
		else if(input == "CROWBAR" && !(StudyAction.searchAction("CROWBAR"))){
			cout << "\nSeems like you already have this item in your inventory.\n\n";
			input = "";
		}
		else if(input == "CHAIR" && !StudyAction.searchAction("CHAIR")){
			cout << "\nPerhaps it's already in it's position...Let's continue....\n\n";
			input = "";
		}
		else if(input == "CROWBAR" && !StudyAction.searchAction("CHAIR")){
			StudyAction.deleteAction("CROWBAR");
			obtCrowbar();
			input = "";	
		}
		else if(input == "CROWBAR" && StudyAction.searchAction("CHAIR")){
			desCrowbar();
			input = "";
		}
		else if(input == "BACK" || input == "INVENTORY"){
			return input;
		}
		else if(input=="SAVE"){
			cout<<"\n ASCII: \" Try to save your books? Just kidding, go LIVING ROOM to SAVE! \" \n\n";
			input= "SANITY";
			return input;
		}
		else if(input=="READ"|| input=="BOOK"){
			cout<<"\n ASCII: \" Hey kid, books in this manor is dangerous! Let's move on!\" \n\n";
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

#endif
