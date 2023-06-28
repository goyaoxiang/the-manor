//this file is to store the class "Player" and the function defination in it 
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

		//class declaration
class Player{
	private:
		struct ListNode{
			string item;
			ListNode *next;
		};
		ListNode *last;
		int sanity;
		bool hallwayStatus;
		bool appleStatus;
	public:
		Player();
		~Player();
		void clearInventory();
		void displayInventory() const;
		void appendInventory(string);
		bool searchItem(string);
		void writeInventory();
		void destructDatabase();
		bool isEmpty();
		void minusSanity(int);
		void addSanity(int);
		void setSanity(int);
		void setHallway(bool i){
			hallwayStatus=i;
		};
		void setApple(bool i){
			appleStatus=i;
		};
		bool returnHallway(){
			return hallwayStatus;
		};
		bool returnApple(){
			return appleStatus;
		};
		int getSanity();
		void gameover();
};

		//constructor
Player::Player(){
	last = nullptr;
	sanity = 100;
	hallwayStatus=0;
	appleStatus=0;
}

		//to clear the inventory list
void Player::clearInventory(){
	ListNode *temp;
	ListNode *nodePtr;
	
	if(!last){
		return;
	}
	else{
		nodePtr = last->next;
		do{
			temp = nodePtr;
			nodePtr = nodePtr->next;
			delete temp;
		}while(nodePtr != last->next);
		last=nullptr;
	}
}

		//destructor
Player::~Player(){
	clearInventory();
}

		//to display the inventory list
void Player::displayInventory()const{
	ListNode *nodePtr;
	
	if(!last){
		cout << "\nYou have nothing in your inventory!" << endl;
	}
	else{
		nodePtr = last->next;
		cout << endl;
		do{
			cout << "| " << setw(10) << nodePtr->item << " |";
			nodePtr = nodePtr->next;
		}while(nodePtr != last->next);
		cout << endl;
	}
}

		//to append new inventory into the list
void Player::appendInventory(string name){
	ListNode *newNode;
	ListNode *nodeptr;
	newNode = new ListNode;
	newNode->item = name;
	newNode->next = nullptr;
	
	if(!last){
		last = newNode;
		last->next = newNode;
	}
	else{
		nodeptr=last;
		
		do{
			nodeptr=nodeptr->next;
			
		}while(nodeptr->item!=name && nodeptr!=last);
		
		if(nodeptr->item==name){
			return ;
		}
		else{
			newNode->next = last->next;
			last->next = newNode;
			last = newNode;
		}
	
	}
}

		//to return if certain items is in the list
bool Player::searchItem(string name){
	ListNode *nodePtr;
	ListNode *prevNode;
	bool found = false;
	
	if(!last){
		return found;
	}
	else{
		nodePtr = last->next;
		
		do{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}while(nodePtr != last->next && nodePtr->item != name);
		
		if(nodePtr->item == name){
			found = true;
		}
		return found;
	}
}

		//to return whether the list is empty
bool Player::isEmpty(){
	return last == nullptr;
}

		//to write the data into the database
void Player::writeInventory(){
	ofstream database;
	database.open("Database.txt");
	
	if(!database){
		cout << "There is an error when saving ! \n";
		return;
	}
	else if(!last){
		database << hallwayStatus << endl;
		database << appleStatus << endl;
		database << getSanity();
	}
	else{
		database << hallwayStatus << endl;
		database << appleStatus << endl;
		database << getSanity() << endl;
		ListNode *nodeptr=last;
		do{
			nodeptr=nodeptr->next;
			if(nodeptr==last){
				database << (nodeptr->item);
			}
			else{
				database << (nodeptr->item)<<endl;
			}
		}while(nodeptr != last);
		
		database.close();
	}

	cout << "\nGame saved !\n";
}

		//to clear the database
void Player::destructDatabase(){
	ofstream database;
	database.open("Database.txt");
	
	database << 0 << endl;
	database << 0 << endl;
	database << 100;
	
	database.close();
}

		//to minus the sanity value
void Player::minusSanity(int num){
	sanity = sanity - num;
	if(sanity <= 0){
		gameover();
	}
	else if(sanity <= 15){
		cout<<"\nYOUR NEXT MOVE COULD BE YOUR LAST. CHOOSE YOUR WORDS WISELY.\n\n"; 
	}
	else if(sanity <= 25){
		cout<<"\"WHAT ARE THESE VOICES IN MY HEAD!!!?\" The pain is unbearable.\n"; 
		cout<<"Warning: Less than 25% SANITY left.\n\n"; 
	}
	else if(sanity <= 50){
		cout<<"\nYou start to hallucinate, it seems like EVERYTHING is not going too well.\n";   
		cout<<"SANITY : < 50%\n\n"; 
	}
	else if(sanity <= 75){
		cout<<"\nYour sanity gauge displays a reassuring statistic: you still posses sanity less than 75%\n\n"; 
	}
}

		//to add the sanity value
void Player::addSanity(int num){
	sanity = sanity + num;
	
	if(sanity > 100){
		sanity = 100;
	}
}

		//to set the sanity value
void Player::setSanity(int num){
	sanity = num;
}

		//to return the sanity value
int Player::getSanity(){
	return sanity;
}

		//the message when sanity goes down to 0 
void Player::gameover(){
	cout<<"\n=====================================================================\n";
	cout<<"               ******    ****    **    **  *********\n";
	cout<<"      ************       **  **   *** ****  **\n";
	cout<<"              ***  ***  ********  ********  *****\n";
	cout<<"                **  **  ***   **  ***   **  **\n";
	cout<<"                 *****  **    **  **    **  *********\n";
	cout<<"\n";
	cout<<"              ******** ***    **  ********* ********\n";
	cout<<"              ***   **  **    **  **        **   ***\n";
	cout<<"              **    **   ******   *******   ******\n";
	cout<<"      ****************     **  ***********  **  ****\n";
	cout<<"\n======================================================================\n";
	
	cout<<"\nYOU RAN OUT OF SANITY.\n";
	cout<<"\"You have traversed the treacherous depths of this place, but alas, your mind has\n";
	cout<<"succumbed to its malevolent grip. Your sanity, once a beacon of light, now fades into oblivion.\"\n";
	cout<<"With mocking laughter and malicious satisfaction \"Game over, dear player. Your\n";
	cout<<"sanity shattered, your hopes dashed. Welcome to the realm of eternal madness,\n";
	cout<<"where your torment shall endure for all eternity.\"\n\n\n";
	
	system("pause");
}

#endif
