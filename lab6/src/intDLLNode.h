

#ifndef _INTDLLNODE_H_
#define _INTDLLNODE_H_

class intDLLNode
{
	friend class intDLList;
	
public:
	intDLLNode(int el = 0, intDLLNode *n = nullptr, intDLLNode *p = nullptr){
		info  = el;
		next = n;
		prev = p;
	}

protected:
	int info;
	intDLLNode *next, *prev;

private:

};


#endif // _INTDLLNODE_H_

