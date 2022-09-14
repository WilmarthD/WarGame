//--------------------------------------------------------------------------------------------------
//File Name: Card.cpp
//Associated file: Card.h
//Members:
//	1 Constructor : Default
//	Standard Methods:
//		Get - suit, rank
//		Set - suit, rank
//		Print - PrintACard
//	Other Methods:
//	Friends:
//	Destructor
//--------------------------------------------------------------------------------------------------

#include "Card.h"

cardClassType::cardClassType(void)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: cardClassType
// Class Name: cardClassType
// Description: Constructor for the cardClassType class
/////////////////////////////////////////////////////////////////////////////////////////
{
	//Initialize class variables
	cardSuit = 0;
	cardRank = 0;
}

void cardClassType::PrintACard(int rank, int suit)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: PrintACard
// Class Name: cardClassType
// Description: Prints the suit then rank of a card.
/////////////////////////////////////////////////////////////////////////////////////////
{
	char charRank;

	//If rank is numerical
	if (rank >= 2 && rank <= 10)
	{
		//Print card
		cout << setw(5) << rank << (char)suit;
	}
	else
	{
		//Determine rank
		switch (rank)
		{
		case (11):
			charRank = 'J';
			break;
		case (12):
			charRank = 'Q';
			break;
		case (13):
			charRank = 'K';
			break;
		default:
			charRank = 'A';
		}

		//Print card
		cout << setw(5) << charRank << (char)suit;
	}
}

bool cardClassType::operator < (const cardClassType& card)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: Overload <
// Class Name: cardClassType
// Description: Overloads < operator and returns whether the card is lower or not.
/////////////////////////////////////////////////////////////////////////////////////////
{
	bool lowerThan = false;

	//If rank is lower than other card
	if (cardRank < card.cardRank)
	{
		//Set lower than to true
		lowerThan = true;
	}

	return lowerThan;
}

bool cardClassType::operator > (const cardClassType& card)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: Overload >
// Class Name: cardClassType
// Description: Overloads > operator and returns whether the card is higher or not.
/////////////////////////////////////////////////////////////////////////////////////////
{
	bool greaterThan = false;

	//If rank is lower than other card
	if (cardRank > card.cardRank)
	{
		//Set lower than to true
		greaterThan = true;
	}

	return greaterThan;
}

bool cardClassType::operator == (const cardClassType& card)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: Overload ==
// Class Name: cardClassType
// Description: Overloads == operator and returns whether the card is equal or not.
/////////////////////////////////////////////////////////////////////////////////////////
{
	bool equalTo = false;

	//If rank is lower than other card
	if (cardRank == card.cardRank)
	{
		//Set lower than to true
		equalTo = true;
	}

	return equalTo;
}

cardClassType::~cardClassType(void)
/////////////////////////////////////////////////////////////////////////////////////////
// Method Name: ~cardClassType
// Class Name: cardClassType
// Description: Destructor for the cardClassType class
/////////////////////////////////////////////////////////////////////////////////////////
{
	/*

	//Static count
	static int destructIndex = 0;

	//Print to console that object is destroyed 
	cout << "Card object # " << ++destructIndex << " destroyed" << endl;

	*/
}