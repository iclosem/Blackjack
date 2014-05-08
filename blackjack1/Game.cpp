#include "Game.h"
Game::Game()
{
}
void Game::Start()
{
	Table newgame;
	bool endgame = false;
	char command;
	//This initializes the game. Creates the deck and shuffles it. Also initializes some variables
	newgame.start();

	//This deals the first round.
	newgame.deal();
	newgame.gameOver = false;  // initialize bool gameOver.  If it's true, game will end.
	// this loop allows the user to choose among get another card, stay, or end the game
	while (!endgame && newgame.gameOver == false)
	{
		// In the table class, i put some instructions to Deal (D), Stay (S), or End the game (E)
		// This reads the command from the user
		cout << "Please enter a command" << endl;
		cin >> command;


		if (command == 'D')
		{
			newgame.hit();
		}
		else if (command == 'S')
		{
			newgame.stay();
		}
		else if (command == 'E')
		{
			endgame = true;
			break;
		}
		else
		{
			cout << "Please enter a valid command!"<< endl;
		}
	}
}