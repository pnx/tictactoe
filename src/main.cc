/* main.cc
 *
 *   Copyright (C) 2009-2010  Henrik Hautakoski <henrik@fiktivkod.org>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
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
