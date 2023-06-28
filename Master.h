//this file is to store the class"Master" and the function defination in it
#ifndef MASTER_H
#define MASTER_H
#include "Action.h"
#include <iostream>
#include <string>

using namespace std; 

		//class declaration
class Master{
	private:
		Action MasterAction;
	public:
		Master();
		~Master();
		void desMaster();
		void lockedMaster();
		void desMainKey();
		void desChest();
		void deleteAction(string i){
			MasterAction.deleteAction(i);
		};
		bool searchAction(string i){
			MasterAction.searchAction(i);
		};
		void appendAction(string i){
			MasterAction.appendAction(i);
		};
		string getAction();
		void getChest(string &);
};

		//constructor
Master::Master(){
	MasterAction.appendAction("BACK");
	MasterAction.appendAction("CHEST");
	MasterAction.appendAction("MAIN KEY");
	
}

		//destructor
Master::~Master(){
	
	
}

		//description of master bedroom
void Master::desMaster(){
	cout<<"\n----------------------------------------------------------------------------------\n";
	cout<<"Current location: MASTER BEDROOM\n\n";
	cout<<"You are now in the master bedroom, your eyes scanned the room, an old and\n"; 
	cout<<"antique chest was found positioned at the foot of an ornate bed. You tried to OPEN\n"; 
	cout<<"the chest, but failed to. You need a password to open the chest. What is hidden\n"; 
	cout<<"inside in the CHEST? Might be the MAIN KEY for you to escape from the mansion.\n"; 
	cout<<"\n----------------------------------------------------------------------------------\n";
	
}

		//message when the door is locked
void Master::lockedMaster(){
	cout<<"\n--------------------------------------------------------------------------------------\n";
	cout<<"Current location: LIVING ROOM\n\n";
	cout<<"You stood before the imposing entrance to what appeared to be the master\n"; 
	cout<<"bedroom. You tried to open the door. Klick-klick, the door couldn\'t be open. You try to\n"; 
	cout<<"force your way in, but there’s no effect. Seems like you are required to have a KEY\n"; 
	cout<<"to unlock the door.\n";
	cout<<"\n--------------------------------------------------------------------------------------\n";
}

		//description of the chest
void Master::desChest(){
	cout<<"\n-------------------------------------------------------------------------------------------------------\n";
	cout<<"\nThis chest requires a six character code. There are some wordings crafted on the chest.\n\n";
	cout<<"It reads out: \n";
	cout<<"\"Crepusculo de las Almas\"\n";
	cout<<"Beware, courageous soul who dares to open this cursed box.\n";
	cout<<"I beseech you to heed my warning, for within its depths lies a key that grants escape from this manor.\n";
	cout<<"However, a sinister fate shall befall any who dares to claim it.\n\n";
	cout<<"\n-------------------------------------------------------------------------------------------------------\n";
}

		//description for main key
void Master::desMainKey(){
	cout<<"MAIN KEY obtained.\n";
	cout<<"You feel extreme cold.\n";
	cout<<"The ghosts are angry and furious, find your way out now!!\n";
}

		//to determine the action based on the commands
string Master::getAction(){
	string input;
	do{
		cout<<">";
		getline(cin, input);
		
		if(input=="CHEST" && !MasterAction.searchAction("CHEST")){
			cout<<"\nYou already opened it....Let's get out....\n\n";
			input = "";
		}
		else if(input=="CHEST" && MasterAction.searchAction("CHEST")){
			desChest();
			getChest(input);
			if(input == "MASTER BEDROOM" || input == "MAIN KEY"){
				return input;
			}
		}
		else if(input == "MAIN KEY" && MasterAction.searchAction("CHEST")){
			cout << "Invalid action. You cannot do that.\n\n";
			input = "";
		}
		else if(input == "MAIN KEY" && !MasterAction.searchAction("CHEST")){
			cout << "\nSeems like you already have that in your inventory...Let's move on...\n\n";
			input = "";
		}
		else if(input == "INVENTORY" || input == "BACK"){
			return input;
		}
		else if(input=="SAVE"){
			cout<<"\nASCII:\"Kid, bedroom is for sleeping, not for saving your game, go back LIVING ROOM to SAVE\"\n\n";
			input="SANITY";
			return input;
		}
		else if(input=="SLEEP"){
			cout<<"\nASCII:\"Seriously? Sleep? I'll take it as a joke...Let's continue...\"\n\n";
			input="SANITY";
			return input;
		}
		else{
			cout<<"\nASCII:\"I bet we can't do that.\"\n\n";
			input = "SANITY";
			return input;
		}
	}while(input == "");
}

		//to get player input to open the chest
void Master::getChest(string& input){
	string decision;
	string answer;
	const string PASSWORD="CPT113";
	
	cout<<"\nDo you want to give a try and open this cursed chest?...Say a YES or NO...\nconsider the consequences..\n";
	do{
		cout << ">";
		getline(cin, decision);
		
		if(decision=="YES"){
			do{
				cout<<"\nPlease insert the password needed ..... \n>";
				getline(cin,answer);
				
				if(answer==PASSWORD){
					//main key
					cout<<"\n====================================\n\n";
 					cout<<"\t"<<" ,o.          8 8 \n";
 					cout<<"\t"<<"d   bzzzzzzzza8o8b\n";
 					cout<<"\t"<<" `o'              \n";
 					cout<<"\n====================================\n";
					cout<<"\nBravo!! Seems like you still have your sanity.\n";
					input="MAIN KEY";
					MasterAction.deleteAction("MAIN KEY");
					MasterAction.deleteAction("CHEST");
					desMainKey();
				}
				else if(answer=="BACK"){
					input="MASTER BEDROOM";
				}
				else{
					cout<<"\nStuck? You can always step BACK...\n";
				}
			}while(answer!=PASSWORD && answer!="BACK");
		}
		else if(decision=="NO"){
			cout<<"\nASCII:\"Afraid of making the decision?\nYou are going to be left to ROT in this manor! HAHAHAHAHAHAHA\"\n";
			input = "MASTER BEDROOM";
		}
		else{
			cout<<"\nASCII:\"You can't do " << decision << ".\"\n" << endl; 
		}
	}while(decision!="YES" && decision!="NO");
}

#endif
