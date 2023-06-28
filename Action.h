//this file is to store the class "Action" and the fucntion defination in it
#ifndef ACTION_H
#define ACTION_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

		//class declaration
class Action{
	private:
		struct ListNode{
			string action;
			ListNode *next;
		};
		ListNode *head;
	public:
		Action();
		~Action();
		void displayAction() const;
		void appendAction(string);
		void deleteAction(string);
		bool searchAction(string);
		
};

		//constructor
Action::Action(){
	head = nullptr;
}

		//destructor
Action::~Action(){
	ListNode *temp;
	ListNode *nodePtr;
	
	nodePtr = head;
	while(nodePtr){
		temp = nodePtr;
		nodePtr = nodePtr->next;
		delete temp;
	}
}

		//to display the action
void Action::displayAction() const{
	ListNode *nodePtr;
	
	if(!head){
		cout << "No action" << endl;
	}
	else{
		nodePtr = head;
		int counter = 1;
		while(nodePtr){
			cout << setw(5) << counter << ". " << nodePtr->action <<endl;
			counter++;
			nodePtr = nodePtr->next;
		}
	}
}

		//to append new action into the list
void Action::appendAction(string action){
	ListNode *nodePtr;
	ListNode *newNode;
	
	newNode = new ListNode;
	newNode->action = action;
	newNode->next = nullptr;

	if(!head){
		head = newNode;
	}
	else{
		nodePtr = head;
		while(nodePtr->next){
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
		newNode->next = nullptr;
	}
}

		//to delete a certain action in the list
void Action::deleteAction(string action){
	ListNode *nodePtr;
	ListNode *prevNode = nullptr;
	
	if(!head){
		return;
	}
	else{
		nodePtr = head;
		while(nodePtr && nodePtr->action != action){
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if(!prevNode){
			head = nodePtr->next;
			delete nodePtr;
		}
		else{
			prevNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

		//to returnn if certain action is in the list
bool Action::searchAction(string action){
	ListNode *nodePtr;
	bool status = false;
	if(!head){
		return status;
	}
	else{
		nodePtr = head;
		while(nodePtr && nodePtr->action != action){
			nodePtr = nodePtr->next;
			}
		if(nodePtr == NULL){
			status = false;
		}
		else if(nodePtr->action == action){
			status = true;
		}
		return status;
	}
}

#endif
