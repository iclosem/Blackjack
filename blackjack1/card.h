#pragma once
#include <string>
#include<vector>
class Card {
public:
	
	int positionValue, suitValue;  //position value is meaningless to the games, just used to populate the deck.  
									//Suit value is 1-4 only used to populate deck and also meaningless to the game
	int cardValue;					// meaningful to the game, tells what the actual value of the card is
	std::string cardName, suitName;
	void setValue(int a, int b); 
	void setName(Card card);
	
};


