#include "GenericPlayer.h"
#include<iostream>
GenericPlayer::GenericPlayer()
{
	PlayerName = "Generic Player";
}
void GenericPlayer::busted()
{
	std::cout << PlayerName << " has busted!" << endl;
}
void GenericPlayer::showHand(GenericPlayer genericPlayer)
{
	string line1 = "";
	string line2 = "";
	string line3 = "";
	string line4 = "";
	string line5 = "";
	string line6 = "";
	string line7 = "";

	if (genericPlayer.isFaceDown == true)// sets the first card face down
	{
		genericPlayer.vHand[0].cardName = "     "; // "flips" the first card
		genericPlayer.vHand[0].suitName = " ";
	}
	//this loop adds each card horizontally for the genericPlayer
	cout << genericPlayer.PlayerName << "'s Hand" << endl;
	for (int i = 0; i < genericPlayer.vHand.size(); i++)
	{
		line1 += "----------   ";
		line2 += "|" + genericPlayer.vHand[i].cardName + " " + genericPlayer.vHand[i].suitName + " |   ";
		line3 += "|        |   ";
		line4 += "|        |   ";
		line5 += "|        |   ";
		line6 += "|" + genericPlayer.vHand[i].cardName + " " + genericPlayer.vHand[i].suitName + " |   ";
		line7 += "----------   ";
	}
	cout << line1 << endl;
	cout << line2 << endl;
	cout << line3 << endl;
	cout << line4 << endl;
	cout << line5 << endl;
	cout << line6 << endl;
	cout << line7 << endl;
}