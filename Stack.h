#ifndef STACK_H
#define STACK_H

//--------------------------------------------------------------------------------------------------
//File Name: Stack.h
//Associated file: Stack.cpp
//Members:
//	1 Constructor : Creates a stack.
//	Standard Methods:
//		Get - ANode, 
//		Set - N/A
//		Print - N/A
//	Other Methods: CreateAStack, DestroyStack, isEmptyStack, Push, GetTop, Pop
//	Friends:
//	Destructor: Deletes all nodes on the stack.
//--------------------------------------------------------------------------------------------------

#include "Deck.h"
//#include <cstdlib>
//#include <ctime>

class StackClassType : public cardClassType
{
public:
	StackClassType(void) { CreateAStack(); }

	nodePTR GetANode(int aSuit, int aRank);

	void CreateAStack(void);

	void DestroyStack(void);

	bool isEmptyStack(void) { return (stackTop == nullptr); }

	void Push(cardClassType aCard);

	nodePTR GetTop(void);

	cardClassType Pop(void);

	~StackClassType(void) { DestroyStack(); }

private:
	nodePTR stackTop;

};

#endif // !Stack