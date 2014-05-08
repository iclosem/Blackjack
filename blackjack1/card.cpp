#ifndef CARD_H
#define CARD_H
#include "card.h"
#include <string>
#include<iostream>
#include "Dealer.h"
using namespace std;
void Card::setValue(int a, int b)
{
	positionValue = a;
	suitValue = b;
}

void Card::setName(Card card) // assigns names and card values for each card
{
	switch (card.positionValue)
	{
	case 1: cardName = "A    ";
		cardValue = 11;
		break;
	case 2: cardName = "2    ";
		cardValue = 2;
		break;
	case 3: cardName = "3    ";
		cardValue = 3;
		break;
	case 4: cardName = "4    ";
		cardValue = 4;
		break;
	case 5: cardName = "5    ";
		cardValue = 5;
		break;
	case 6: cardName = "6    ";
		cardValue = 6;
		break;
	case 7: cardName = "7    ";
		cardValue = 7;
		break;
	case 8: cardName = "8    ";
		cardValue = 8;
		break;
	case 9: cardName = "9    ";
		cardValue = 9;
		break;
	case 10: cardName = "10   ";
		cardValue = 10;
		break;
	case 11: cardName = "Jack ";
		cardValue = 10;
		break;
	case 12: cardName = "Queen";
		cardValue = 10;
		break;
	case 13: cardName = "King ";
		cardValue = 10;
		break;
	default: cardName = "Nothing Set";
		break;
	}
	switch (card.suitValue)
	{
	case 1: suitName = "S"; //Spades
		break;
	case 2: suitName = "C"; //Clubs
		break;
	case 3: suitName = "D"; //Diamonds
		break;
	case 4: suitName = "H"; //Hearts
		break;
	default: suitName = "Nothing Set";
		break;
	}
}
#endif

