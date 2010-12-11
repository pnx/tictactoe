/* game.cc - Overall game logic
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
#include "player/computer_player.h"
#include "player/human_player.h"
#include "square.h"

using std::cout;
using std::endl;

Game::Game()
{
	// create a board
	board = new Board();
	
	// create players
	player[0] = new Human_Player(CROSS_PIECE);
	player[1] = new Computer_Player(CIRCLE_PIECE);
	
	// pass board to players
	player[0]->setBoard(board);
	player[1]->setBoard(board);
}

Game::~Game()
{
	delete player[0];
	delete player[1];
	delete board;
}

void Game::play(void) {
	
	/* Holds the count of how many moves have been played */
	int moves = 0;
	
	/* flag to break the main loop */
	bool loop = true;
	
	// Begin by drawing the board
	board->display();
	
	// Main loop
	while(loop) {
		
		moves++;
		
		for(int i=0; i < N_PLAYERS; i++) {
			
			// let the player make a move
			player[i]->makeMove();
			
			// Display the move on screen
			cout << player[i]->getPiece() << " move:" << endl;
			board->display();
			
			// Check if player has won.
			if (player[i]->isWinner()) {
				cout << endl << player[i]->getPiece() 
					 << " won in " << moves << " moves!" << endl;
				loop = false;
				break;
			}
		}
	}
}
