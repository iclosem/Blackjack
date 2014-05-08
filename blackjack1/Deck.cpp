#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
Deck::Deck()
{
	Deck::MAX_CARDS_IN_DECK= 52; //52 cards per deck
	Deck::MAX_CARD_PER_SUIT=13; //13 cards per suit
	Deck::MAX_SUITS=4; //4 suits per deck
}
void Deck::buildDeck() //adds all the cards to the deck
{
	for (int i = 1; i <= Deck::MAX_SUITS; i++) //iterates 4 times because there's 4 suits
	{
		for (int j = 1; j <= Deck::MAX_CARD_PER_SUIT; j++) //as it loops through it builds a new card, assigns value and name and adds it to the deck.
		{
			Card card;
			card.setValue(j, i);
			card.setName(card);

			Deck::vDeck.insert(Deck::vDeck.end(), card);
		}
	}// you end up with 52 cards 13 cards per suit and 4 suits
}

void Deck::shuffle() 
{
	std::srand(time(0));
	std::random_shuffle(vDeck.begin(), vDeck.end()); //this method from the algorithm library randomly shuffles a vector
}
void Deck::clearDeck()
{
	Deck::vDeck.clear();
}