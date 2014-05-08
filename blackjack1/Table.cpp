#include "Table.h"
#include <iostream>
#include <algorithm>
#include "Game.h"
#include <thread>
#include <chrono>
using namespace std;

//This deals one more card to the player
Table::Table()
{
	bool gameOver = false; //To keep track of when to end the game
}
void Table::hit()
{
	try
	{
		player.vHand.push_back(newdeck.vDeck[usedcards]);
		usedcards++;
		showCards();
		checkRules("hit", player);
	}
	catch (int e)
	{
		cout << "Sorry, we had an oopsy: " << e << endl;
	}
}
void Table::clearTable()
{
	newdeck.clearDeck();
	dealer.vHand.clear();
	player.vHand.clear();
}

void Table::stay()
{
	//Starts dealing to the dealer and check for the rules. we need to come up with the rules for the dealer to keep going or stop
	
	showCards();
	checkRules("stay", player);
	//In blackjack, I believe, the dealer has to keep going if he is lower than 16 and stay if the is higher or equal than 16
}

//Initializes the game. Creates the deck, shuffles it and initilizes the used cards variable.
void Table::start()
{
	showInstructions();
	newdeck.buildDeck();
	newdeck.shuffle();
	usedcards = 0;
	dealer.isFaceDown = true; //if player stays, this is false
	
}

//Deals the first round of cards.
void Table::deal()
{
	try
	{

		// The dealer always deals 2 cards to the players and himself
		for (int i = 0; i < 4; i++)
		{
			//note the usedcards variable keeps track of what cards have been used
			dealer.vHand.push_back(newdeck.vDeck[usedcards]);
			usedcards++;
			i++;
			player.vHand.push_back(newdeck.vDeck[usedcards]);
			usedcards++;

		}
		dealer.firstCard = dealer.vHand[0]; //temporarily stores the first card
		//Show the cards for the dealer and player.
		showCards();
	}
	catch (int e)
	{
		cout << "Sorry, we had an oopsy: " << e << endl;
	}

	
}

//Shows the cards in the table
void Table::showCards()
{
	system("CLS"); // clears screen
	showInstructions();
	Dealer::showHand(dealer);
	Player::showHand(player);
}

//Shows the instructions and header
void Table::showInstructions()
{
	cout << "Welcome to SUPER BLACK-JACK" << endl;
	cout << "Instructions:" << endl;
	cout << "D - Deals a card   |   S - Stay   |   E - Exit the game" << endl;
	cout << "-------------------------------------------------------" << endl << endl;
}

//This checks the rules of the game. This needs to be expanded and/or improved. I was working on this until this morning before work 
//so it is not complete.
int Table::calcHand(vector<Card> vHand)
{
	int sumHand = 0;
	int numOfAces=0;
	for (int i = 0; i < vHand.size(); i++)
	{
		sumHand += vHand[i].cardValue;
		if (vHand[i].cardName == "A    ")
			numOfAces++;
	}
	if (sumHand > 21 && numOfAces == 1)
	{
		return sumHand - 10;
	}
	else if (sumHand > 21 && numOfAces >= 1)
	{
		return sumHand - (10 * (numOfAces - 1));
	}
	else
	{
		return sumHand;
	}
	
}
void Table::playDealer()
{

	try
	{
		int sumPlayer = calcHand(player.vHand);
		while (calcHand(dealer.vHand) < 17)
		{
			dealer.vHand.push_back(newdeck.vDeck[usedcards]);
			usedcards++;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			showCards();
		}
		int sumDealer = calcHand(dealer.vHand);
		cout << "Player's total is: " << sumPlayer << endl;
		cout << "Dealer's total is: " << sumDealer << endl;
		if (sumDealer > 21)
		{
			cout << "YOU WIN" << endl;
			playAgain();
		}
		else if (sumPlayer > sumDealer)
		{
			cout << "YOU WIN" << endl;
			playAgain();
		}
		else if (sumDealer > sumPlayer)
		{
			cout << "YOU LOST" << endl;
			playAgain();
		}
		else
		{
			cout << "TIE!!" << endl;
			playAgain();
		}
	}
	catch (int e)
	{
		cout << "Sorry, we had an oopsy: " << e << endl;
	}
	
}

void Table::playAgain()
{
	string userInput;
	
	bool userInputGood = false;
	while (userInputGood == false)
	{
		cout << "Would you like to play a new game? (Y/N): ";
		cin >> userInput;
		if (userInput == "Y" || userInput == "y")
		{
			clearTable(); //clear everything out
			start(); //builds deck and resets used card counter
			deal(); //deals everything out
			showCards(); //Play AGAIN!
			userInputGood = true;
		}
		else if (userInput == "N" || userInput == "n")
		{
			gameOver = true;
			userInputGood = true;
		}

		else
		{
			cout << "Please enter a valid option" << endl;
		}
	}
}
void Table::checkRules(string state, GenericPlayer genericPlayer)
{
	try
	{
		int sumDealer = calcHand(dealer.vHand);
		int sumPlayer = calcHand(player.vHand);
		//if the state is hit check the hand of the player to see if it busted
		if (state == "hit")
		{
			//if the sum is greater than 21 
			if (calcHand(genericPlayer.vHand) > 21)
			{
				genericPlayer.busted();
				cout << genericPlayer.PlayerName << "'s Total is: " << calcHand(genericPlayer.vHand) << endl;;
				playAgain();
			}
			else
			{
				cout << "Player's total is: " << sumPlayer << endl;
			}


		}
		//this rules are for stay. Here we will check for the rules for the Dealer.
		else if (state == "stay")
		{
			dealer.isFaceDown = false;
			showCards();
			playDealer();

		}
	}
	catch (int e)
	{
		cout << "Sorry, we had an oopsy: " << e << endl;
	}
}