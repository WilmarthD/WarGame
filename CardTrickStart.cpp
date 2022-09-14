
/*





///This program creates a deck of cards, displays it and shuffles it

///This is just an example, remember not to used structs and to delete from final product
#include <iostream>
#include <iomanip>

///You need the next two includes to do a random number
#include <cstdlib>
#include <ctime>

using namespace std;
///This is an enumerated type...just a named integer.  Normally, they would start with 0, if just listed. -------------- This allows us to increment suits such that it goes to the next name (I believe)
///Since I have started the first one out with a 3, the values are 3, 4, 5 and 6,
enum suits { heart = 3, diamond, club, spade };

const int DECK_SIZE = 52;

struct cardType
{
	int rank;
	int suit;
};

void CreateDeck(cardType deck[]);
void PrintTheDeck(cardType deck[]);

void Swap(cardType& first, cardType& second);

void ShuffleTheDeck(cardType deck[]);

void PrintACard(int card, int suit);

void CardTrick(cardType deck[]);
void DisplayTheTable(cardType trickDeck[][3]);

int main(void)
{
	cardType deck[DECK_SIZE];

	/// This will seed the random off the clock tick.  That way you will get a more random number
	srand((unsigned int)time(NULL));


	CreateDeck(deck);

	PrintTheDeck(deck);

	cout << endl << endl;

	ShuffleTheDeck(deck);

	PrintTheDeck(deck);

	CardTrick(deck);

	return 0;
}
void CreateDeck(cardType deck[])
{
	int index;
	int card = 1;
	int suit = heart;

	for (index = 0; index < DECK_SIZE; index++)
	{
		deck[index].rank = card;
		deck[index].suit = suit;
		card++;
		if (card == 14)
		{
			card = 1;
			suit++;
		}
	}

}

void PrintTheDeck(cardType deck[])
{
	int index;
	int card = 1;
	int suitChange = 1;


	for (index = 0; index < DECK_SIZE; index++)
	{
		PrintACard(deck[index].rank, deck[index].suit);
		suitChange++;
		if (suitChange == 14)
		{
			suitChange = 1;
			cout << endl;
		}

	}

}

void Swap(cardType& first, cardType& second)
{
	cardType temp;

	temp = first;
	first = second;
	second = temp;
}

void ShuffleTheDeck(cardType deck[])
{
	int randSpot;
	int index;
	/// We go through the whole deck
	for (index = 0; index < DECK_SIZE; index++)
	{
		/// rand function will give you a random number between 0 and the max integer.  The % with deck size
		/// give you a random number between 0 and one less than that number.
		randSpot = rand() % DECK_SIZE;
		/// We then swap the card sport we are on (index) with the random spot
		swap(deck[index], deck[randSpot]);

	}
	/// You could shuffle like this in a loop and go more than one time
}


void CardTrick(cardType deck[])
{
	cout << "Do the card trick" << endl;   ///remove this when you program the trick

}
//You must use this function with a 2 dimensional array for printing.  You do not 
//have to use a two dimensional array any where else, but here you have to.
//This takes in any number of rows but only 3 columns.

void DisplayTheTable(cardType trickDeck[][3])
{

}
void PrintACard(int card, int suit)
{
	/// You will have to change this nested if to a switch statement.
	char printChar;

	if (card >= 2 && card <= 10)
	{
		cout << setw(5) << card << (char)suit;
	}
	else
	{
		if (card == 11)
		{
			printChar = 'J';
		}
		else if (card == 12)
		{
			printChar = 'Q';
		}
		else if (card == 13)
		{
			printChar = 'K';
		}
		else
		{
			printChar = 'A';
		}

		cout << setw(5) << printChar << (char)suit;
	}

}














*/