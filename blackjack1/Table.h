#ifndef TABLE_H
#define TABLE_H
#include "Deck.h"
#include "card.h"
#include "Dealer.h"
#include "Player.h"
#include <vector>

using namespace std;
class Table {
public:
	Table();
	bool gameOver;
	int usedcards;
	Deck newdeck;
	void hit();
	void stay();
	void start();
	void deal();
	void showCards();
	void showInstructions();
	void checkRules(string state, GenericPlayer genericPlayer);
	void clearTable();
	void playDealer();
	void playAgain();
	int calcHand(std::vector<Card> vHand);
	Dealer dealer;
	Player player;


};
#endif