//--------------------------------------------------------------------------------------------------
//File Name: Deck.cpp
//Associated file: Deck.h
//Members:
//	1 Constructor : Creates a deck of 52 cards.
//	Standard Methods:
//		Get - ArrayCard
//		Set - N/A
//		Print - Deck
//	Other Methods: CreateDeck, Shuffle Deck, Swap
//	Friends:
//	Destructor 
//--------------------------------------------------------------------------------------------------

#include "Deck.h"

void deckClassType::CreateDeck(void)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: CreateDeck
// Class Name: deckClassType
// Description: Creates array filled with all cards in a deck.
/////////////////////////////////////////////////////////////////////////////////////////
{
	int index;
	int rank = 2;
	int suit = heart;
	
	for (index = 0; index < DECK_SIZE; index++)
	{
		//Set rank and suit
		deckArray[index].SetRank(rank);
		deckArray[index].SetSuit(suit);

		//Increment rank
		rank++;

		//If rank is past the highest card
		if (rank == 15)
		{
			//Reset rank and change suit
			rank = 2;
			suit++;
		}
	}
}

void deckClassType::ShuffleTheDeck(void)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: ShuffleTheDeck
// Class Name: deckClassType
// Description: Shuffles the order of cards in the deck array.
/////////////////////////////////////////////////////////////////////////////////////////
{
	int randSpot;
	int index;

	//For the whole deck
	for (index = 0; index < DECK_SIZE; index++)
	{
		//Get random spot in a ray
		randSpot = rand() % DECK_SIZE;

		//Swap cards with the random object
		swap(deckArray[index], deckArray[randSpot]);

	}
}

void deckClassType::Swap(cardClassType& first, cardClassType& second)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: Swap
// Class Name: deckClassType
// Description: Swaps the values of two card objects.
/////////////////////////////////////////////////////////////////////////////////////////
{
	cardClassType temp;

	temp = first;
	first = second;
	second = temp;
}

void deckClassType::PrintTheDeck(void)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: PrintTheDeck
// Class Name: deckClassType
// Description: Prints the entire deck.
/////////////////////////////////////////////////////////////////////////////////////////
{
	int index;
	int card = 1;
	int suitChange = 1;


	for (index = 0; index < DECK_SIZE; index++)
	{
		PrintACard(deckArray[index].GetRank(), deckArray[index].GetSuit());
		suitChange++;
		if (suitChange == 14)
		{
			suitChange = 1;
			cout << endl;
		}

	}

}

deckClassType::~deckClassType(void)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: ~deckClassType
// Class Name: deckClassType
// Description: Destructor for deckClassType that deletes the stack.
/////////////////////////////////////////////////////////////////////////////////////////
{
	//Static count
	static int destructIndex = 0;

	//Print to console that object is destroyed 
	cout << "Deck #" << ++destructIndex << " is done building." << endl;
}