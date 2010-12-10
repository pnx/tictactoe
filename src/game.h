/* game.h - Overall game logic
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

#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player/player.h"

#define N_PLAYERS 2

class Game
{
private :
	
	/* holds the board */
	Board *board;
	
	/* set of players */
	Player *player[N_PLAYERS];
	
public :

	Game();
	
	~Game();
	
	/* game: Run a tic tac toe game */
	void play(void);
};

#endif
