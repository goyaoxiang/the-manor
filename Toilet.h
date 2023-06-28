//this file is to store the class "Toilet" and the function definations in it 
#ifndef TOILET_H
#define TOILET_H
#include "Action.h"
#include <iostream>
#include <string>

using namespace std;

		//class declaration
class Toilet{
	private:
		Action ToiletAction;
	
	public:
		Toilet();
		~Toilet();
		void desToilet();
		string getAction();
};

		//constructor
Toilet::Toilet(){
	ToiletAction.appendAction("BACK");
	
}

		//destructor
Toilet::~Toilet(){
	
}

		//description for toilet
void Toilet::desToilet(){
	cout<<"\n---------------------------------------------------------------------------------\n";
	cout<<"Current location: TOILET\n\n";
	cout<<"Feeling the urge, you headed to the toilet to tend to a more immediate matter.\n";  
	cout<<"ARHHHHHHHHH RELAXING :))))))))))))))))\n"; 
	cout<<"You look up and you see a couple of symbols displayed on the mirror of the toilet\n";
	cout<<"\n(4AE\"\"$)\n";
	cout<<"Hmm...weird.\n";
	cout<<"\n---------------------------------------------------------------------------------\n";
}

		//to determine the action based on the commands
string Toilet::getAction(){
	string input;

	cout<<">";
	getline(cin, input);
	
	if(input == "BACK" || input == "INVENTORY"){
		return input;
	}
	else if(input=="SYMBOLS"){
		cout<<"\n ASCII: \" HAHAHA, wanna take a picture of the symbols?? Don't be silly kid. Let's move on. \" \n\n";
		input="SANITY";
		return input;
	}
	else if(input=="SAVE"){
		cout<<"\n ASCII: \" Hmm...interesting, save this 'RELAXING' moment? Go LIVING ROOM to SAVE!!\" \n\n";
		input="SANITY";
		return input;
	}
	else if(input=="FLUSH"){
		cout<<"\n ASCII: \" Such a lovely boy, trying to keep the toilet clean. Unfortunately, the flush is broken\"\n\n";
		input="SANITY";
		return input;
	}
	else{
		cout << "\n ASCII:\"I bet we can't do that in TOILET.\"\n\n";
		input = "SANITY";
		return input;
	}
}



#endif
