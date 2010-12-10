
#include <iostream>
#include "game.h"

using namespace std;

int main(void) {

	Game *game = new Game();
	
	// Print a nice welcome message
	cout << "Welcome to tic-tac-toe!" << endl;
	
	// Run the game
	game->play();
	
	// cleanup
	delete game;
	
	return 0;
}
