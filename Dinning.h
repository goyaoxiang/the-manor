//this file is to store the class "Dinning" and the function defination in it
#ifndef DINNING_H
#define DINNING_H
#include "Action.h"
#include <iostream>
#include <string>

using namespace std; 

		//class declaration
class Dinning{
	private: 
		Action DinningAction;
	
	public:
		Dinning();
		~Dinning();
		void desDinning();
		void desCandle();
		void deleteAction(string i){
			DinningAction.deleteAction(i);
		};
		void appendAction(string i){
			DinningAction.appendAction(i);
		};
		bool searchAction(string i){
			return DinningAction.searchAction(i);
		};
		string getAction();
		bool getCandle();
};

		//constructor
Dinning::Dinning(){
	DinningAction.appendAction("BACK");
	DinningAction.appendAction("EAT APPLE");
	DinningAction.appendAction("CANDLE");
}

		//destructor
Dinning::~Dinning(){
	
}

		//description of dinning room
void Dinning::desDinning(){
	cout<<"\n-----------------------------------------------------------------------------------------------------\n";
	cout<<"Current location: DINNING ROOM\n\n";
	cout<<"You entered the dinning room, your eyes were immediately drawn to a solitary\n"; 
	cout<<"CANDLE standing proudly atop the dinning table beside the CANDLE is a APPLE, seems like it is eatable.\n"; 
	cout<<"Its flame flickered and danced,casting a warm glow across the room. A sense of relief washed over you,\n";
	cout<<"realising that this source of light would prove invaluable for navigating the mansion's dark corners.\n";
	cout<<"\n-----------------------------------------------------------------------------------------------------\n";
}

		//description of candle
void Dinning:: desCandle(){
	cout<<"      (      \n";
    cout<<"      )\\     \n";
    cout<<"      {_}    \n";
    cout<<"     .-;-.   \n";
    cout<<"    |'-=-'|  \n";
    cout<<"    |     |  \n";
    cout<<"    |     |  \n";
    cout<<"    |     |  \n";
    cout<<"    |     |  \n";
    cout<<"    '.___.'  \n";
	cout<<"\nCandle picked up.\n";
	cout<<"You now have a source of light to move forward for you investigation.\n\n";
}

		//determine the action based on the command
string Dinning::getAction(){
	string input;
	do{
		cout<<">";
		getline(cin, input);
		
		if(input=="CANDLE" && DinningAction.searchAction("CANDLE")){
			DinningAction.deleteAction("CANDLE");
			desCandle();
			input = "";
		}
		else if(input=="CANDLE" && !DinningAction.searchAction("CANDLE")){
			cout<<"\nSeems like you already have that in your inventory...Let's move on...\n\n";
			input = "";
		}
		else if(input=="APPLE"){
			cout<<"\n-------------------------------------\n";
			cout<<"\t"<<"      ,_		\n";
			cout<<"\t"<<" ,--./~'_		\n";
			cout<<"\t"<<"|  `-- # )		\n";
			cout<<"\t"<<" \\      / 	\n"; 
			cout<<"\t"<<"  `-^--'		\n";
			cout<<"\n--------------------------------------\n";
			cout<<"You keep staring at the APPLE. \"What a beautiful APPLE.\"\n\n";
			input = "";
		}
		else if(input=="EAT"){
			cout<<"EAT? What do you want to EAT?\n\n";
			input = "";
		}
		else if(input=="EAT APPLE" && DinningAction.searchAction("EAT APPLE")){
			DinningAction.deleteAction("EAT APPLE");
			cout<<"\n-------------------------------------\n";
 			cout<<"\t"<<"    ,--./,-.    \n";
 			cout<<"\t"<<"   /,-._.--~\\  \n";
 			cout<<"\t"<<"    __}  {      \n";
 			cout<<"\t"<<"   \\`-._,-`-,  \n";
 			cout<<"\t"<<"    `._,._,'    \n";
			cout<<"\n--------------------------------------\n";
			cout << "Ahhhhhh......Sweet...." << endl;
			cout << "I find myself more relieve and relax in this otherwise depressed environment...." << endl << endl;
			return input;
		}
		else if(input=="EAT APPLE" && !DinningAction.searchAction("EAT APPLE")){
			cout<<"\nSeems like you already eat the apple...Let's move on...\n\n";
			input = "";
		}
		else if(input == "INVENTORY" || input == "BACK"){
			return input;
		}
		else if(input=="SAVE"){
			cout<<"\nASCII:\"What? Saving your food for the next meal? Go back LIVING ROOM to SAVE\"\n\n";
			input= "SANITY";
			return input;
		}
		else{
			cout << "\n ASCII:\"I bet we can't do that.\"\n\n";
			input = "SANITY";
			return input;
		}
	}while(input == "");
}

		//return the status of action "CANDLE"
bool Dinning::getCandle(){
	if(!DinningAction.searchAction("CANDLE")){
		return true;
	}
	else{
		return false;
	}
}

#endif
