
#include "intDLList.h"
#include <iostream>

using namespace std;


const int EMPTY_LIST = 1;

intDLList::intDLList(){ //class constructor
	head = tail = nullptr;
}

bool intDLList::isEmpty(){ //checks if list is empty or not
	if(head == nullptr){
		return true;
	}
	else{
		return false;
	}
}

intDLList::~intDLList(){ //class destructor
	for(intDLLNode* p; !isEmpty(); head = p){
		p = head->next;
		delete head;
	}
}


void intDLList::addToHead(int i){ //adds integer of user's choice to the head of the list
	if(isEmpty()){
		intDLLNode* node = new intDLLNode(i);
		head = tail = node;
	}
	else{
		intDLLNode* new_node = new intDLLNode(i, head);
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
		}
	}

void intDLList::addToTail(int i){ //adds integer of the user's choice to the tail of the list
	if(tail != nullptr){
		tail = new intDLLNode(i, nullptr, tail);
		tail->prev->next = tail;
	}
	else{
		head = tail = new intDLLNode(i);
	}
}

int intDLList::deleteFromHead(){ //deletes the integer at the head of the list
	if(!isEmpty()){
		int i = head->info;
		intDLLNode *temp = head;
		if(head == tail){
			head = tail = nullptr;
		}
		else{
			head = head->next;
			head->prev = nullptr;
		}
		delete temp;
		return i;
	}
	else{
		throw(EMPTY_LIST);
	}
}

int intDLList::deleteFromTail(){ //deletes the integer at the tail of the list
	if(head != nullptr){
		int i = tail->info;
		if(head == tail){
			delete tail;
			head = tail = nullptr;
		}
		else{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		return i;
	}
	else{
		throw(EMPTY_LIST);
	}
}
	
void intDLList::deleteNode(int i){ //searches for an integer of the user's choice and deletes that node
	if(head != nullptr){
		if(head == tail && i == head->info){
			intDLLNode* temp = head;
			head = tail = nullptr;
			delete temp;
		}
		else{
			if(i == head->info){ //removes the head if it contains the element
				intDLLNode* temp = head;
				head->prev = nullptr;
				head = head->next;
				delete temp;
			}
			else if(i == tail->info){ //removes the tail if it contains the element
				intDLLNode* temp = tail;
				tail = tail->prev;
				tail->next = nullptr;
				delete temp;
			}
			else{ //removes a middle node if it contains the element
				intDLLNode* temp;
				intDLLNode* n;
				intDLLNode* pred;
				for(temp = head->next; temp != nullptr && temp->info != i; temp = temp->next);
				n = temp->next;
				pred = temp->prev;
				if(n != nullptr){
					n->prev = pred;
				}
				if(pred != nullptr){
					pred->next = n;
				}
				delete temp;
			}
		}
	}
}

bool intDLList::isInList(int i) const{ //checks if a certain integer is in the list
	intDLLNode* temp;
	for(temp = head; temp!=nullptr && temp->info != i; temp = temp->next);
	return (temp!=nullptr);
}

void intDLList::addSorted(int i){ //adds integer of the user's choice to list and places it such that the list is in increasing order
	if(isEmpty()){
		addToHead(i);
	}
	else{
		if(head->info > i){ //el is to be inserted before the current head
			addToHead(i);
		}
		else if(tail->info < i){ //el is to be inserted after current tail
			addToTail(i);
		}
		else{ // el is to be inserted between head and tail
			intDLLNode* test;
			for(test = head; test!= nullptr && test->info < i; test = test->next);
		
			intDLLNode* p = test->prev;
			intDLLNode* new_node = new intDLLNode(i, test, p);
			p->next = new_node;
			test->prev = new_node;
		}
	}
}

void intDLList::printList(){ //displays the list
	if(!isEmpty()){
		intDLLNode* ref = head;
		while(ref != nullptr){
			cout << ref->info << " ";
			ref = ref->next;
		}
	}
	else{
		cout << "List is empty" << endl;
	}
	cout << endl;
}

	




