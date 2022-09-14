#ifndef CARD_H
#define CARD_H

//--------------------------------------------------------------------------------------------------
//File Name: Card.h
//Associated file: Card.cpp
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

#include "standards.h"

//Set enum for suits
enum suit { heart = 3, diamond, club, spade };

class cardClassType
{
public:
	//Constructor
	cardClassType(void);

	int GetSuit(void) { return cardSuit; }

	int GetRank(void) { return cardRank; }

	void SetSuit(int aSuit) { cardSuit = aSuit; }

	void SetRank(int aNumber) { cardRank = aNumber; }

	void PrintACard(int rank, int suit);

	//Overload members
	bool operator < (const cardClassType& card);

	bool operator > (const cardClassType& card);

	bool operator == (const cardClassType& card);

	//Destructor
	~cardClassType(void);
private:
	int cardSuit;
	int cardRank;
};

struct nodeStructType
{
	cardClassType Card;
	nodeStructType* link;
};

typedef nodeStructType* nodePTR;

#endif // !Card