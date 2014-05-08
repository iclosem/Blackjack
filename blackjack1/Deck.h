#pragma once
#include "card.h"
#include <vector>
using namespace std;

class Deck {
public:
	Deck();
	int MAX_CARDS_IN_DECK; //52 cards per deck
	int MAX_CARD_PER_SUIT; //13 cards per suit
	int MAX_SUITS; //4 suits per deck
	std::vector<Card> vDeck; //holds all the cards
	void buildDeck();
	void shuffle();
	void Deck::clearDeck();
};