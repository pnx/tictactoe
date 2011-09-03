/* human_player.h
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

#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "player.h"

class Human_Player : public Player
{
public :
	Human_Player(SquareType piece_type);

	~Human_Player();

	/* makeMove: makes a move on the board */
	bool makeMove();
};

#endif
