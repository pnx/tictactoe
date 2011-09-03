/* computer_player.h - Computer AI player
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

#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "player.h"

class Computer_Player : public Player
{
private :

	/* 2 dimensional array of all possible patterns (on a 3x3 board) */
	static const int map[24][3];

	/* aiBestMove: will find the best moves based on a ordered list
	   if index is provided the method will make sure not to pick that index. */
	int aiBestMove(int index);

	/* aiRandom: makes a random move */
	int aiRandom();

	/* aiWinPattern: Return true if p is a winning pattern, false otherwise */
	bool aiWinPattern(const int p[]);

	/* aiBlockPattern: Returns true if p is a blocking pattern, false otherwise */
	bool aiBlockPattern(const int p[]);

	/* aiFrom: algorithm that finds the best square to move from */
	int aiFrom();

	/* aiFrom: algorithm that finds the best square to move to */
	int aiTo(int from);

public :

	Computer_Player(SquareType piece_type);

	~Computer_Player();

	/* makeMove: makes a move on the board */
	bool makeMove();
};

#endif
