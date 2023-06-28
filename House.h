//This is the file that store the class 'House' and the function defination of this class.
//header file needed in this class
#ifndef HOUSE_H
#define HOUSE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "Player.h" 
#include "Attic.h"
#include "Second.h"
#include "BoysRoom.h"
#include "Living.h"
#include "Storage.h"
#include "Dinning.h"
#include "Master.h"
#include "Hallway.h"
#include "Study.h"
#include "Toilet.h"
using namespace std;

		//class declaration
class House:public Player{
	private:
		struct StackNode{
			string classname;
			StackNode *next;
		};
		StackNode *stacktop;
		Player player;
		LivingRoom living;
		Storage storage;
		Dinning dinning;
		Master master;
		Hallway hallway;
		SecondFloor secondFloor;
		Toilet toilet;
		BoysRoom boysroom;
		Attic attic;
		Study study;
		bool SAVE;
		bool WIN;

	public:
		House();
		~House();
		void pushStack(string name);
		void popStack();
		bool isStackEmpty();
		void transition(string);
		string top();
		void readData();
		void updateAction();
		void resetGame();
		bool getSave(){
			return SAVE;
		};
		bool getWin(){
			return WIN;
		};
		void resetSave(){
			SAVE=0;
		};
		
		void displaystack(){
			StackNode *nodePtr;
			
			if(isStackEmpty()){
				cout << "empty" << endl;
			}
			else{
				nodePtr = stacktop;
				while(nodePtr){
					cout << nodePtr->classname << endl;
					nodePtr = nodePtr->next;
				}
			}
		}
};

		//constructor
House::House(){
	stacktop = nullptr;
	pushStack("LIVING ROOM");
	SAVE=0;
	WIN=0;
}

		//destructor
House::~House(){
	StackNode *temp;
	while(!isStackEmpty()){
		temp = stacktop;
		stacktop = stacktop->next;
		delete temp;
	}
}

		//function to push the location of player
void House::pushStack(string name){
	StackNode *newNode;
	
	newNode = new StackNode;
	newNode->classname = name;
	newNode->next = nullptr;
	
	if(isStackEmpty()){
		stacktop = newNode;
		stacktop->next = nullptr;
	}
	else{
		if(name == stacktop->classname){
			return;
		}
		else{
			newNode->next = stacktop;
			stacktop = newNode;
		}
	}

}

		//function to pop the location of player
void House::popStack(){
	StackNode *temp;
	
	if(isStackEmpty()){
		cout << "You have no action yet" << endl;
	}
	else{
		temp = stacktop->next;
		delete stacktop;
		stacktop = temp;
	}
}

		//function to check the stack is empty
bool House::isStackEmpty(){
	return stacktop == nullptr;
}

		//function to return the top of the stack
string House::top(){
	return (stacktop->classname);
}


		//function to determine the transition of player based on the command
void House::transition(string name){
	srand(time(0));
		//loop that will continue until the end of the game
	while(!isStackEmpty()){
		if(name=="SAVE"){
			setHallway(!living.searchAction("HALLWAY"));
			setApple(!dinning.searchAction("EAT APPLE"));
			writeInventory();
			SAVE=1;
			cout<<"\nThe manor awaits your return....See you soon....\n";
			break;
		}
		else if(name == "LIVING ROOM"){
			living.desLiving();
			name = living.getAction();
		}
		else if(name == "INVENTORY"){
			displayInventory();
			name = top();
		}
		else if(name == "BACK"){
			popStack();
			name = top();
		}
		else if(name =="LEAVE"){
			if(searchItem("MAIN KEY")){
				popStack();
				WIN=1;
			}
			else{
				cout<<"\nASCII:\"Trying to escape? YOU CANT'T WITHOUT A KEY.\"\n\n";
				name = "LIVING ROOM";
			}
		}
		else if(name == "EAT APPLE"){
			addSanity(20);
			name = dinning.getAction();
			if(dinning.getCandle()){
				appendInventory("CANDLE");
			}
		}
		else if(name == "JUMPSCARE"){
			minusSanity(20);
			name = "BACK";
		}
		else if(name == "SANITY"){
			minusSanity(rand() % 5 + 1);
			if(getSanity() <= 0){
				break;
			}
			else{
				name = top();
				if(name == "LIVING ROOM"){
					name = living.getAction();
				}
				else if(name == "HALLWAY"){
					name = hallway.getAction();
				}
				else if(name == "MASTER BEDROOM"){
					name = master.getAction();
				}
				else if(name == "DINNING ROOM"){
					name = dinning.getAction();
					if(dinning.getCandle()){
						appendInventory("CANDLE");
					}
				}
				else if(name == "STORAGE"){
					name = storage.getAction();
					if(storage.getLadder()){
						appendInventory("LADDER");
					}
				}
				else if(name == "SECOND FLOOR"){
					name = secondFloor.getAction();
				}
				else if(name == "STUDYROOM"){
					name = study.getAction();
					if(study.getCrowbar()){
						appendInventory("CROWBAR");
					}
				}
				else if(name == "ATTIC"){
					if(!searchItem("CANDLE")){
						name = attic.getCandleless();
					}
					else{
						name = attic.getAction();
						if(attic.getKey()){
							appendInventory("KEY");
						}
					}
				}
				else if(name == "BOYSROOM"){
					name = boysroom.getAction();
				}
				else if(name == "TOILET"){
					name = toilet.getAction();
				}
			}
		}
		else if(name == "DINNING ROOM"){
			pushStack("DINNING ROOM");
			dinning.desDinning();
			name = dinning.getAction();
			if(dinning.getCandle()){
				appendInventory("CANDLE");
			}
		}
		else if(name == "HALLWAY"){
			pushStack("HALLWAY");
			hallway.desHallway();
			name = hallway.getAction();
		}
		else if(name == "STORAGE"){
			if(searchItem("CROWBAR")){
				pushStack("STORAGE");
				storage.desStorage();
				name = storage.getAction();
				if(storage.getLadder()){
					appendInventory("LADDER");
				}
			}
			else{
				storage.lockedStorage();
				name = living.getAction();
			}
		}
		else if(name == "MASTER BEDROOM"){
			if(!searchItem("KEY")){
				master.lockedMaster();
				name = living.getAction();
			}
			else{
				pushStack("MASTER BEDROOM");
				master.desMaster();
				name = master.getAction();
			}
		}
		else if(name == "MAIN KEY"){
			appendInventory("MAIN KEY");
			name = "MASTER BEDROOM";
		}
		else if(name == "SECOND FLOOR"){
			pushStack("SECOND FLOOR");
			secondFloor.desSecondFloor();
			name = secondFloor.getAction();
		}
		else if(name == "TOILET"){
			pushStack("TOILET");
			toilet.desToilet();
			name = toilet.getAction();
		}
		else if(name =="BOYS ROOM"){
			pushStack("BOYS ROOM");
			boysroom.desBoysRoom();
			name = boysroom.getAction();
		}
		else if(name == "ATTIC"){
			if(searchItem("LADDER") && searchItem("CANDLE")){
				pushStack("ATTIC");
				attic.desAttic();
				name = attic.getAction();
				if(attic.getKey()){
					appendInventory("KEY");
				}
			}
			else if(!searchItem("LADDER")){
				attic.lockedAttic();
				name = secondFloor.getAction();
			}
			else if(!searchItem("CANDLE")){
				pushStack("ATTIC");
				attic.candlelessAttic();
				name = attic.getCandleless();
			}
		}
		else if(name == "STUDYROOM"){
			pushStack("STUDYROOM");
			study.desStudy();
			name = study.getAction();
			if(study.getCrowbar()){
				appendInventory("CROWBAR");
			}
		}
	}
}

		//function to read data from the database
void House::readData(){
	ifstream database;
	database.open("Database.txt");
	
	if(database){
		string temp;
		int num;
		bool hallway, apple;
		
		database >> hallway;
		database >> apple;
		database >> num;
		setHallway(hallway);
		setApple(apple);
		setSanity(num);
		database.ignore();
		while(!database.eof()){
			getline(database,temp, '\n');
			appendInventory(temp);
		}
		database.close();
	}
	else{
		cout<<"\nError reading file !\nConsider checking the database or start a new game instead.\n\n";
		return ;
	}
}

		//function to update the action list after reading the data
void House::updateAction(){
	if(searchItem("MAIN KEY") && master.searchAction("MAIN KEY") && master.searchAction("CHEST")){
		master.deleteAction("MAIN KEY");
		master.deleteAction("CHEST");
	}
	if(searchItem("LADDER") && storage.searchAction("LADDER")){
		storage.deleteAction("LADDER");
	}
	if(searchItem("CROWBAR") && study.searchAction("CROWBAR")){
		study.deleteAction("CROWBAR");
		study.deleteAction("CHAIR");
	}
	if(searchItem("CANDLE") && dinning.searchAction("CANDLE")){
		dinning.deleteAction("CANDLE");
	}
	if(searchItem("KEY") && attic.searchAction("KEY")){
		attic.deleteAction("KEY");
	}
	if(returnHallway()){
		living.deleteAction("HALLWAY");
	}
	if(returnApple()){
		dinning.deleteAction("EAT APPLE");
	}

	return ;
}

		//function to reset the status in the game
void House::resetGame(){
	
	if(searchItem("MAIN KEY")){
		master.appendAction("MAIN KEY");
		master.appendAction("CHEST");
	}
	if(searchItem("LADDER")){
		storage.appendAction("LADDER");
	}
	if(searchItem("CROWBAR")){
		study.appendAction("CROWBAR");
		study.appendAction("CHAIR");
	}
	if(searchItem("CANDLE")){
		dinning.appendAction("CANDLE");
	}
	if(searchItem("KEY")){
		attic.appendAction("KEY");
	}
	if(!living.searchAction("HALLWAY")){
		living.appendAction("HALLWAY");
	}
	if(!dinning.searchAction("EAT APPLE")){
		dinning.appendAction("EAT APPLE");
	}
	
	clearInventory();
	
	StackNode *temp;
	while(!isStackEmpty()){
		temp = stacktop;
		stacktop = stacktop->next;
		delete temp;
	}
	
	stacktop = nullptr;
	pushStack("LIVING ROOM");
	SAVE=0;
	WIN=0;
	setSanity(100);
	setHallway(0);
	setApple(0);
	
	updateAction();
}

#endif
