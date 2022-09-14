//--------------------------------------------------------------------------------------------------
//File Name: Stack.cpp
//Associated file: Stack.h
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

#include "Stack.h"

nodePTR StackClassType::GetANode(int aSuit, int aRank)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: GetANode
// Class Name: deckClassType
// Description: Creates a node filled with data.
/////////////////////////////////////////////////////////////////////////////////////////
{
	//Allocate memory to node
	nodePTR ptr = new nodeStructType;

	//Set rank and suit
	ptr->Card.SetSuit(aSuit);
	ptr->Card.SetRank(aRank);

	//Assign link to NULL
	ptr->link = NULL;

	return ptr;
}

nodePTR StackClassType::GetTop(void)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: GetTop
// Class Name: deckClassType
// Description: Returns the top node of the stack.
/////////////////////////////////////////////////////////////////////////////////////////
{
	if (!isEmptyStack())
	{
		//Return the top node if stack isn't empty
		return stackTop;
	}
	else
	{
		//If stack is empty, output such to screen
		cout << "Can not return card, deck is empty." << endl;

		//Return NULL
		return NULL;
	}
}

void StackClassType::Push(cardClassType aCard)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: Push
// Class Name: deckClassType
// Description: Adds a card to the top of the stack.
/////////////////////////////////////////////////////////////////////////////////////////
{
	//Create new node
	nodePTR newNode = GetANode(aCard.GetSuit(), aCard.GetRank());

	//Check if stack is empty
	if (isEmptyStack())
	{
		//Set card to top
		stackTop = newNode;
	}
	else
	{
		//Link previous top node to new node
		newNode->link = stackTop;

		//Set new node to stack top
		stackTop = newNode;
	}
}

cardClassType StackClassType::Pop(void)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: Pop
// Class Name: deckClassType
// Description: Returns the value and removes top element in stack.
/////////////////////////////////////////////////////////////////////////////////////////
{
	cardClassType cardNode;
	nodePTR tempNode;

	if (!isEmptyStack())
	{
		//Set top node to current top of stack and assign rank value
		tempNode = stackTop;
		cardNode = tempNode->Card;

		//Set stack top to next node
		stackTop = stackTop->link;

		//Delete top node
		delete tempNode;

		//Return value of rank
		return cardNode;
	}
	else
	{
		//If deck is empty, then output such to screen
		cout << "Cannot remove from an empty deck." << endl;

		return stackTop->Card;
	}
}

void StackClassType::CreateAStack(void)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: CreateAStack
// Class Name: deckClassType
// Description: Sets top of stack to null pointer.
/////////////////////////////////////////////////////////////////////////////////////////
{
	//Set top to null
	stackTop = nullptr;
}

void StackClassType::DestroyStack(void)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: DestroyStack
// Class Name: deckClassType
// Description: Deletes all nodes in the stack.
/////////////////////////////////////////////////////////////////////////////////////////
{
	cardClassType temp;

	while (stackTop != nullptr)
	{
		//Pop top of stack
		temp = Pop();
	}
}
