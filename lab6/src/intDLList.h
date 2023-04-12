
#ifndef _INTDLLIST_H_
#define _INTDLLIST_H_
#include "intDLLNode.h"

class intDLList
{
public:
	intDLList();
	~intDLList();
	bool isEmpty();
	void addToHead(int i);
	void addToTail(int i);
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode(int i);
	bool isInList(int i) const;
	void addSorted(int i);
	void printList();
	
	

protected:

private:
	intDLLNode *head;
	intDLLNode *tail;
};

#endif // _INTDLLIST_H_

