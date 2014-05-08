#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H
#include<string>
#include <vector>
#include <string>
#include<iostream>
#include "card.h"
using namespace std;
class GenericPlayer
{
public:
	GenericPlayer();
	std::vector<Card> vHand;
	bool isFaceDown;
	Card firstCard;
	string PlayerName;
	void busted();
	static void showHand(GenericPlayer genericPlayer);
};
#endif