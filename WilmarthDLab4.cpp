//--------------------------------------------------------------------------------------------------
//File Name: WilmarthDLab4.cpp
//Associated file:
//Description: Main cpp file that runs the game of war. In this version of War, the deck of 52 cards
// is split evenly between the user and the computer hands, which are stacks of linked lists. Rounds
// will be played where each player takes the card on the top of their deck and puts it on their
// table stack, comparing the rank difference. If they tie, then they go to war and will have to bet
// 4 cards at a time, only comparing the ranks of the 4th card, until one player has a higher card 
// then the other. When one wins a round, they receive all cards in on both players table and they
// get placed in the winners winning cards stack. The game continues until one player is completely
// out of cards both in their hand and in their winning stack.
//
//Recursive function: My recursive function is the function War, which calls on itself if the 4th
// card is another tie.
//--------------------------------------------------------------------------------------------------

#include "standards.h"
#include "Deck.h"
#include "Stack.h"
#include <Windows.h>

void CreateHands(deckClassType deck, StackClassType& userHand, StackClassType& cpuHand);

void PlayRound(StackClassType& userHand, StackClassType& cpuHand, StackClassType& userTable,
	StackClassType& cpuTable, StackClassType& userWins, StackClassType& cpuWins, bool& skip);

bool CanContinue(StackClassType& hand, StackClassType& wins, string player);

void War(StackClassType& userHand, StackClassType& cpuHand, StackClassType& userTable,
	StackClassType& cpuTable, StackClassType& userWins, StackClassType& cpuWins, bool& skip);

void WarWin(StackClassType& userTable, StackClassType& cpuTable, StackClassType& wins);

void SkipThrough(bool& skipChoice);

void PauseRun(bool skipChoice, int seconds);

int main(void)
{
	//Declare deckClassType variables for stacks
	deckClassType deck;
	StackClassType userHand;
	StackClassType userWinning;
	StackClassType userTable;
	StackClassType computerHand;
	StackClassType computerWinning;
	StackClassType computerTable;

	//Initialize skip running to false
	bool skipRunning = false;

	//Seed random 
	srand((unsigned int)time(NULL));

	//Shuffle deck
	deck.ShuffleTheDeck();

	//Output the creating of hands
	cout << "Dealing cards to player and computer..." << endl;

	//Create hands
	CreateHands(deck, userHand, computerHand);

	//Pause for immersion
	Sleep(2500);

	//Output that dealing is done
	cout << "All cards dealt, lets begin!" << endl;

	//Pause for 2 seconds
	Sleep(2000);

	//Check if user wants to skip
	SkipThrough(skipRunning);

	//Play a round (Primer)
	PlayRound(userHand, computerHand, userTable, computerTable, userWinning, computerWinning, 
				skipRunning);

	//Pause for 3 seconds
	PauseRun(skipRunning, 3);

	//Check if user wants to skip
	SkipThrough(skipRunning);

	//Output prompt for next round
	cout << endl << "Next Round" << endl << endl;

	//Pause for 3 seconds
	PauseRun(skipRunning, 3);

	//While both hands can continue (aren't empty)
	while (CanContinue(userHand, userWinning, "User") &&
			CanContinue(computerHand, computerWinning, "Computer"))
	{
		//Play a round against each other
		PlayRound(userHand, computerHand, userTable, computerTable, userWinning, computerWinning,
					skipRunning);

		//Pause for 3 seconds
		PauseRun(skipRunning, 3);

		//Check if user wants to skip
		SkipThrough(skipRunning);

		//Output prompt for next round
		cout << endl << "Next Round" << endl << endl;

		//Pause for 3 seconds
		PauseRun(skipRunning, 3);
	}

	//Add more space 
	cout << endl << endl;

	//Check who ran out of cards
	if (!CanContinue(userHand, userWinning, "User"))
	{
		//Output prompt telling user they lost
		cout << "Looks like you lost this time, and here I was thinking it would never end!" << endl;
	}
	else
	{
		//Output prompt telling user they won
		cout << "Congratulations! You won! Orange you glad we played?" << endl;
	}

	return 0;
}

void CreateHands(deckClassType deck, StackClassType& userHand, StackClassType& cpuHand)
/////////////////////////////////////////////////////////////////////////////////////////
// Function Name: CreateHands
// Description: Creates the user and computer hands with linked lists.
/////////////////////////////////////////////////////////////////////////////////////////
{
	cardClassType arrayCard;
	int deckIndex = 0;

	//While there are cards in the deck
	while (deckIndex < DECK_SIZE)
	{
		//Get card from array
		arrayCard = deck.GetArrayCard(deckIndex);

		//Push card into user hand
		userHand.Push(arrayCard);

		//Increment to next card
		deckIndex++;

		//Get card from array
		arrayCard = deck.GetArrayCard(deckIndex);

		//Push card into computers hand
		cpuHand.Push(arrayCard);

		//Increment deck index to next card
		deckIndex++;
	}
}

void PlayRound(StackClassType& userHand, StackClassType& cpuHand, StackClassType& userTable,
			StackClassType& cpuTable, StackClassType& userWins, StackClassType& cpuWins, bool& skip)
/////////////////////////////////////////////////////////////////////////////////////////
// Function Name: PlayRound
// Description: Determines the winner of the round, continuing until someone wins.
/////////////////////////////////////////////////////////////////////////////////////////
{
	//Pop user's top card into user table and state what it is
	userTable.Push(userHand.Pop());
	cout << left << setw(20) << "User's card: " << right;
	userTable.PrintACard(userTable.GetTop()->Card.GetRank(), userTable.GetTop()->Card.GetSuit());
	cout << endl;

	//Pop computer's card into computer's table and state the card
	cpuTable.Push(cpuHand.Pop());
	cout << left << setw(20) << "Computer's card: " << right;
	cpuTable.PrintACard(cpuTable.GetTop()->Card.GetRank(), cpuTable.GetTop()->Card.GetSuit());
	cout << endl;

	//If the ranks of the cards are tied
	if (userTable.GetTop()->Card == cpuTable.GetTop()->Card)
	{
		if (!CanContinue(userHand, userWins, "User"))
		{
			//Output that user can't continue
			cout << endl << endl;
		}
		else if (!CanContinue(cpuHand, cpuWins, "Computer"))
		{
			//Output that computer can't continue
			cout << endl << endl;
		}
		else
		{
			//Output that it was a tie
			cout << "Round was tied! LET'S GO TO WAR" << endl;

			//Check if user wants to skip
			SkipThrough(skip);

			//Commence the war
			War(userHand, cpuHand, userTable, cpuTable, userWins, cpuWins, skip);

			//Pause program for 2 seconds
			PauseRun(skip, 2);
		}
	}
	else
	{
		//If user's card is higher
		if (userTable.GetTop()->Card > cpuTable.GetTop()->Card)
		{
			//Tell user they won the round
			cout << "You won the round!" << endl;

			//Put all cards on table into user's winning stack
			while (!userTable.isEmptyStack())
			{
				//Push card from user's table into user winning stack
				userWins.Push(userTable.Pop());

				//Push card from computer's table into user winning stack, since they both have the
				//same amount of cards on the table
				userWins.Push(cpuTable.Pop());
			}
		}
		else
		{
			//Tell user they lost the round
			cout << "You lost the round..." << endl;

			//Put all cards on table into computer's winning stack
			while (!cpuTable.isEmptyStack())
			{
				//Push card from user's table into cpu winning stack
				cpuWins.Push(userTable.Pop());

				//Push card from computer's table into cpu winning stack, since they both have the
				//same amount of cards on the table
				cpuWins.Push(cpuTable.Pop());
			}
		}
	}
}

bool CanContinue(StackClassType& hand, StackClassType& wins, string player)
/////////////////////////////////////////////////////////////////////////////////////////
// Function Name: CanContinue
// Description: Determines if the players hand can continue or ends the game if both their
// hand and winning stack are empty. If the hand is empty but not the winning stack, it 
// will fill the hand with all winning cards.
/////////////////////////////////////////////////////////////////////////////////////////
{
	bool continuePlaying = true;

	//If user hand is empty and their winning stack is empty
	if (hand.isEmptyStack() && wins.isEmptyStack())
	{
		//Prompt that game is over
		cout << "Uh oh, " << player << " is out of cards!" << endl;

		//Game is over
		continuePlaying = false;
	}
	else if (hand.isEmptyStack() && !wins.isEmptyStack())
	{
		//Output to user that winning stack goes into hand
		cout << "Looks like " << player << " is out of cards in their hand." << endl;
		cout << "Luckily they have some winnings, lets put those back in the hand!" << endl << endl;

		//If user is out of cards but has cards won, then shuffle them into their hand
		while (!wins.isEmptyStack())
		{
			//Push card from winning stack to hand
			hand.Push(wins.Pop());

			//Game can continue
			continuePlaying = true;
		}
	}
	return continuePlaying;
}

void War(StackClassType& userHand, StackClassType& cpuHand, StackClassType& userTable,
	StackClassType& cpuTable, StackClassType& userWins, StackClassType& cpuWins, bool& skip)
/////////////////////////////////////////////////////////////////////////////////////////
// Function Name: War
// Description: Sets 3 cards from each players hand onto the table, then compares the 4th
// card to see who winds them all. If the 4th card ties again, it will recursively call 
// and repeat the process.
/////////////////////////////////////////////////////////////////////////////////////////
{
	//Prompt each player to put 3 cards down
	cout << "Each player puts 3 cards face down, no peeking!" << endl << endl;

	//Each put 3 cards down
	for (int index = 0; index < 3; index++)
	{
		//Check that there are still available cards
		if (CanContinue(userHand, userWins, "User"))
		{
			//Output card being popped for immersion
			cout << "User card #" << (index+1) << endl;

			//Move card from user hand to table
			userTable.Push(userHand.Pop());

			//Pause before computer's card
			PauseRun(skip, 1);
		}
		//Check that there are still available cards
		if (CanContinue(cpuHand, cpuWins, "Computer"))
		{
			//Output card being popped for immersion
			cout << "Computer card #" << (index+1) << endl;

			//Move card from computer hand to table
			cpuTable.Push(cpuHand.Pop());

			//Pause before user's next card
			PauseRun(skip, 1);
		}
	}
	//Pause for 2 seconds
	PauseRun(skip, 2);

	//Prompt the final card that will compare
	cout << endl << "Play your 4th card..." << endl;

	//Pause for dramatic effect
	PauseRun(skip, 2);

	//Check that there are still available cards
	if (CanContinue(userHand, userWins, "User") && CanContinue(cpuHand, cpuWins, "Computer"))
	{
		//Pop user's top card into user table and state what it is
		userTable.Push(userHand.Pop());
		cout << left << setw(20) << "User's card: " << right;
		userTable.PrintACard(userTable.GetTop()->Card.GetRank(), userTable.GetTop()->Card.GetSuit());
		cout << endl;

		//Pop computer's card into computer's table and state the card
		cpuTable.Push(cpuHand.Pop());
		cout << left << setw(20) << "Computer's card: " << right;
		cpuTable.PrintACard(cpuTable.GetTop()->Card.GetRank(), cpuTable.GetTop()->Card.GetSuit());
		cout << endl;

		//Recursive if statement; If the ranks of the cards are tied
		if (userTable.GetTop()->Card == cpuTable.GetTop()->Card)
		{
			if (!CanContinue(userHand, userWins, "User"))
			{
				//Output that user can't continue
				cout << endl << endl;
			}
			else if (!CanContinue(cpuHand, cpuWins, "Computer"))
			{
				//Output that computer can't continue
				cout << endl << endl;
			}
			else
			{
				//Output that it was a tie
				cout << "Round was tied! LET'S GO TO WAR AGAIN" << endl;

				SkipThrough(skip);

				//Commence Recursive War
				War(userHand, cpuHand, userTable, cpuTable, userWins, cpuWins, skip);

				//Pause program for 2 seconds
				PauseRun(skip, 2);
			}
		}
		else
		{
			//If user's card is higher
			if (userTable.GetTop()->Card > cpuTable.GetTop()->Card)
			{
				//Tell user they won the round
				cout << "You won the round!" << endl << endl;

				//Pause for 2 seconds
				PauseRun(skip, 2);

				//Allocate winnings to user
				WarWin(userTable, cpuTable, userWins);
			}
			else
			{
				//Tell user they lost the round
				cout << "You lost the round..." << endl;

				//Pause for 2 seconds
				PauseRun(skip, 2);

				//Allocate winnings to computer
				WarWin(userTable, cpuTable, cpuWins);
			}
		}
	}
}

void WarWin(StackClassType& userTable, StackClassType& cpuTable, StackClassType& wins)
/////////////////////////////////////////////////////////////////////////////////////////
// Function Name: WarWin
// Description: Outputs what cards were face down/on the table and puts all cards on the
// table into the winners winning stack.
/////////////////////////////////////////////////////////////////////////////////////////
{
	//Tell the user what cards of there's were flipped down
	cout << left << setw(50) << "Your flipped down cards were: " << right;

	//Pop the card we saw back in first
	wins.Push(userTable.Pop());

	//Put all cards on table into user's winning stack
	while (!userTable.isEmptyStack())
	{
		//Push card from user's table into user winning stack
		wins.Push(userTable.Pop());

		//Print the card that was face down
		wins.PrintACard(wins.GetTop()->Card.GetRank(), wins.GetTop()->Card.GetSuit());
		cout << " ";
	}
	//Output space
	cout << endl << endl;

	//Tell the user what cards of the computer's were flipped down
	cout << left << setw(50) << "The computer's flipped down cards were: " << right;

	//Pop the card we saw back in first
	wins.Push(cpuTable.Pop());

	//Put all cards on table into user's winning stack
	while (!cpuTable.isEmptyStack())
	{
		//Push card from user's table into user winning stack
		wins.Push(cpuTable.Pop());

		//Print the card that was face down
		wins.PrintACard(wins.GetTop()->Card.GetRank(), wins.GetTop()->Card.GetSuit());
		cout << " ";
	}
	//Output space
	cout << endl << endl;
}

void SkipThrough(bool& skipChoice)
/////////////////////////////////////////////////////////////////////////////////////////
// Function Name: SkipThrough
// Description: Gets input from user if they would like to skip the running.
/////////////////////////////////////////////////////////////////////////////////////////
{
	string userInput;

	//If the user hasn't chosen to skip yet
	if (!skipChoice)
	{
		//Prompt user to input
		cout << endl;
		cout << "If you would like to skip through the program, please type \"Skip\"" << endl;
		cout << "Enter anything else if you would like to see the next round: ";
		getline(cin, userInput);

		//Output another line to separate from round
		cout << endl;

		for (int index = 0; index < (int)userInput.length(); index++)
		{
			//Lowercase the character
			userInput[index] = tolower(userInput[index]);
		}
		if (userInput == "skip")
		{
			//Output their decision
			cout << "Skipping through program, hold on to your seats!" << endl << endl;

			//Pause for 3 seconds
			Sleep(3000);

			//If user wants to skip, return skip choice as true
			skipChoice = true;
		}
		else
		{
			skipChoice = false;
		}
	
	}
}

void PauseRun(bool skipChoice, int seconds)
/////////////////////////////////////////////////////////////////////////////////////////
// Function Name: PauseRun
// Description: Pauses the run if user hasn't chosen to skip for the chosen amount of
// seconds.
/////////////////////////////////////////////////////////////////////////////////////////
{
	//If user hasn't skipped
	if (!skipChoice)
	{
		//Sleep for specified time
		Sleep((seconds * 1000));
	}
}
