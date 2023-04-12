//Kenny Detlet
//ECE 2620-001
#include <iostream>
#include "intDLLNode.h"
#include "intDLList.h"


using namespace std;


int main()
{
	while(1){
		int input; //input for which switch case needs to be accessed
		int input2; //inputs for if-else statements within switch
		cout << "(1) Create Simple (Unsorted) List" << endl;
		cout << "(2) Create Sorted List" << endl;
		cout << "(3) Create Queue (FIFO)" << endl;
		cout << "(4) Create Stack (LIFO)" << endl;
		cout << "(5) Exit Program" << endl;
		cin >> input;

		switch(input){
			case 1:
			{
				intDLList list; //Creates basic linked list. All members functions that modify list are availble
				while(1){
					cout << "(1) Enter integer for insertion at head of list" << endl;
					cout << "(2) Enter intger for insertion at tail of list" << endl;
					cout << "(3) Display and delete integer from head of list" << endl;
					cout << "(4) Display and delete integer from tail of list" << endl;
					cout << "(5) Search for integer in list and delete that node" << endl;
					cout << "(6) Display contents of list from head to tail" << endl;
					cout << "(7) Exit program" << endl;
					cin >> input2;
				
					if(input2 == 1){
						int a;
						cout << "Enter integer:" << endl;
						cin >> a;
						list.addToHead(a);
					}
					else if(input2 == 2){
						int b;
						cout << "Enter integer:" << endl;
						cin >> b;
						list.addToTail(b);
					}
					else if(input2 == 3){
						int c;
						try{
							c = list.deleteFromHead();
							cout << "Removed integer was:" << c << endl;
						}
						catch(const int EMPTY_LIST){
							cerr << "Error:" << EMPTY_LIST << endl;
							cerr << "Add to the list before removing items" << endl;
						}
					}	
					else if(input2 == 4){
						int d; 
						try{
							d = list.deleteFromTail();
							cout << "Removed integer was:" << d << endl;
						}
						catch(const int EMPTY_LIST){
							cerr << "Error:" << EMPTY_LIST << endl;
							cerr << "Add to the list before removing items" << endl;
						}
					}
							
					else if(input2 == 5){
						int e;
						cout << "Enter integer:" << endl;
						cin >> e;
						list.deleteNode(e);
					}
					else if(input2 == 6){
						list.printList();
					}
					else if(input2 == 7){
						break;
					}
					else{
						cout << "Invalid input. Enter valid number" << endl;
					}
				
				}
			break;
			}
			case 2:
			{
				intDLList sortedList; //Creates sorted linked list. Puts integers in increasing order
				while(1){
					cout << "(1) Enter integer for sorted insertion" << endl;
					cout << "(2) Search and delete integer, if present in list" << endl;
					cout << "(3) Display contents of sorted list of integers, in increasing order" << endl;
					cout << "(4) Exit program" << endl;
					cin >> input2;
						if(input2 == 1){
							int f;
							cout << "Enter integer:" << endl;
							cin >> f;
							sortedList.addSorted(f);
						}
						else if(input2 == 2){
							int g;
							cout << "Enter integer:" << endl;
							cin >> g;
							sortedList.deleteNode(g);
						}
						else if(input2 == 3){
							sortedList.printList();
						}
						else if(input2 == 4){
							break;
						}
						else{
							cout << "Invalid input. Enter valid number" << endl;
						}
					
					}
				break;
				}
					
			case 3:
			{
				intDLList DLLqueue; //Creates queue. Adds to the tail, removes from the head
				while(1){
					cout << "(1) ENQUEUE      (Enter integer for insertion into queue)" << endl;
					cout << "(2) DEQUEUE      (Display and delete integer from queue)" << endl;
					cout << "(3) PRINT QUEUE  (Display queue contents without deleting anything, first element first)" << endl;
					cout << "(4) Exit program" << endl;
					cin >> input2;
					
						if(input2 == 1){
							int h;
							cout << "Enter integer:" << endl;
							cin >> h;
							DLLqueue.addToTail(h);
						}
						else if(input2 == 2){
							int k; 
							try{
								k = DLLqueue.deleteFromHead();
								cout << "Removed integer was: " << k << endl;
							}
							catch(const int EMPTY_LIST){
								cerr << "Error:" << EMPTY_LIST << endl;
								cerr << "Add to the queue before removing items" << endl;
							}
						}
						else if(input2 == 3){
							DLLqueue.printList();
						}
						else if(input2 == 4){
							break;
						}
						else{
							cout << "Invalid input. Enter valid number" << endl;
						}
					
					}
				break;
				}
			case 4:
			{
				intDLList DLLStack; //Creates stack. Adds and removes only from the head
				while(1){
				cout << "(1) PUSH         (Enter integer for insertion into stack)" << endl;
				cout << "(2) POP          (Display and delete integer from stack)" << endl;
				cout << "(3) PRINT STACK  (Display stack elements without deleting anything, last element first)" << endl;
				cout << "(4) Exit program" << endl;
				cin >> input2;

					if(input2 == 1){
						int m;
						cout << "Enter integer:" << endl;
						cin >> m;
						DLLStack.addToHead(m);
					}
					else if(input2 == 2){
						int n;
						try{
							n = DLLStack.deleteFromHead();
							cout << "Removed integer was: " << n << endl;
						}
						catch(const int EMPTY_LIST){
							cerr << "Error:" << EMPTY_LIST << endl;
							cerr << "Add to the stack before removing items" << endl;
						}
					}
					else if(input2 == 3){ 
						DLLStack.printList();
					}
					else if(input2 == 4){
						break;
					}
					else{
						cout << "Invalid input. Enter valid number" << endl;
					}
					
				}
				break;
			}
				
			case 5:
				break;
			default:
				cout << "Invalid input. Enter valid number" << endl;

		}
		break;
	}
		
		
	return 0;
}


