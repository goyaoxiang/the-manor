//this is the main programme 
#include <iostream>
#include <string>
#include "Functions.h"
#include "House.h"

using namespace std;

		//main function
int main(){
	//to call the opening of the game
	opening();
	
	//create an object of class "House"
	House house;
	
	//to store the input
	string choice;
	
	//loop that continue only when player wanted to quit
	do{
				//to check if player saved the game before
		if(house.getSave()){
			opening();
			house.resetGame();
			house.resetSave();
		}
				//to check if player cleared the game 
		else if(house.getWin()){
			gameEnd();
			house.destructDatabase();
			break;
		}
				//to check if player lose the game
		else if(house.getSanity() <= 0){
			house.resetGame();
			house.destructDatabase();
			opening();
		}
		
				//to get input from player
		cout <<"\nYour Selection\n>";
		getline(cin, choice);
		
				//to verify input
		if(choice == "START" || choice == "NEW"){
			introduction();
			house.transition("LIVING ROOM");
		}
		else if(choice == "LOAD"){
			cout<<"\nLoading your file....\n";
			house.readData();
			
			cout<<"Done loading inventory...updating action....\n";
			house.updateAction();
			cout<<"Let's begin..into THE MANOR..\n";
		
			introduction();
			house.transition("LIVING ROOM");
		}
		else if(choice != "QUIT"){
			cout << "INVALID CHOICE!\n";
		}
	}while(choice != "QUIT");
	
	return 0;
}
