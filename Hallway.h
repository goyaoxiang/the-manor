//this file is to store the class"Hallway" and the function defination in it
#ifndef HALLWAY_H
#define HALLWAY_H
#include"Action.h"
#include <iostream>
#include <string>

using namespace std;

		//class declaration
class Hallway{
	private:
		Action HallwayAction;
	public:
		Hallway();
		~Hallway();
		void desHallway();
		void Jumpscare();
		string getAction();
};

		//constructor
Hallway::Hallway(){
	HallwayAction.appendAction("BACK");
}

		//destructor
Hallway::~Hallway(){
	
}

		//description of the hallway
void Hallway::desHallway(){
	cout<<"\n----------------------------------------------------------------------------------\n";
	cout<<"Current location: HALLWAY\n\n";
	cout<<"You tried to move into the hallway, but you feel an intangible barrier seem to\n"; 
	cout<<"materialize before you, creating an impenetrable wall that does not let you pass\n"; 
	cout<<"through. You start to feel a cold breeze, it seems like something is not right.\n";
	cout<<"\n----------------------------------------------------------------------------------\n";

}

		//function to prompt out the jumpscare
void Hallway::Jumpscare(){
	cout<<"\n\n\n               @@@%%%%%%%%%@@      " <<endl;
	cout<<"             @@@%%%%%%%%%#######%@@ " <<endl;
	cout<<"            @@@@%%%%%%%######?######%@" <<endl;
	cout<<"           @@@@%%%%%%%#######:########%@" <<endl;
	cout<<"          @@@@@%%%%%%#########:??#######%" <<endl;
	cout<<"         @@@%%%%%####???###?+:??####?###@" <<endl;
	cout<<"        @@@%%%%%%#?+???###?:+?##??###?##@" <<endl;
	cout<<"      @??%@%%%##????????++:;+?+????????#@" <<endl;
	cout<<"      #  ;?%#?+; ..::+?+ ::;++++++?+???#" <<endl;
	cout<<"      %  :?%;;;:  ....:#+ :;+++????+???@" <<endl;
	cout<<"      #;;+??+++:   ...;##: ;;;++???++?%" <<endl;
	cout<<"      %#%+::++?#+;:::;?##+ ;;;;++??++#" <<endl;
	cout<<"      %?% : :???+?++???######?+;;+??#" <<endl;
	cout<<"      @%# ; ;??;;+ ;???+;;:..::.:+?%" <<endl;
	cout<<"        @???;;?+;;;+ ;:;;......;;;#@" <<endl;
	cout<<"        %##?++?+++;+ ??% @%%@@@@" <<endl;
	cout<<"        @_:?_:+_:_:#%\n\n\n\n" <<endl;
	
	system("pause");
}

		//function to determine the action based on the commands
string Hallway::getAction(){
	string input;
	
	cout<<">";
	getline(cin, input);
	
	if(input == "BACK"){
		Jumpscare();
		input = "JUMPSCARE";
		return input;
	}
	else if(input == "INVENTORY"){
		return input;
	}
	else if(input=="SAVE"){
		cout<<"\nASCII:\"Are you kidding me? Something is not right and you are trying to save your game??\"\n\n";
		input="SANITY";
		return input;
	}
	else{
		cout<<"ASCII:\"Seems like something bad is going to happen, better go BACK now!\"\n\n";
		input = "SANITY";
		return input;
	}
}

#endif
