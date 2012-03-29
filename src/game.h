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

#include "gfx/Graphics/Texture.h"
#include "gfx/Engine.h"
#include "board.h"
#include "player/player.h"

#define N_PLAYERS 2

class Game : public Engine
{
private :

    unsigned moves;

	/* holds the board */
	Board *board;

	/* set of players */
	Player *player[N_PLAYERS];

	// index of the current player
	unsigned int current_player;

	bool inProgress;

	Texture *bg;
	Texture *cross;
	Texture *circle;

public :

	void Init();
	void Update();
	void Render();
	void Exit();
};

#endif
