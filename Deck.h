#ifndef DECK_H
#define DECK_H

//--------------------------------------------------------------------------------------------------
//File Name: Deck.h
//Associated file: Deck.cpp
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

#include "Card.H"
#include <cstdlib>
#include <ctime>

const int DECK_SIZE = 52;

class deckClassType : public cardClassType
{
public:

	deckClassType(void) { CreateDeck(); }

	void CreateDeck(void);

	void ShuffleTheDeck(void);

	void Swap(cardClassType& first, cardClassType& second);

	void PrintTheDeck(void);

	cardClassType GetArrayCard(int arrayIndex) { return deckArray[arrayIndex]; }

	~deckClassType(void);

private:
	cardClassType deckArray[52];

};
#endif // !Deck
