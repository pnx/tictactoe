/* player.h - Base class for a player
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

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "../square.h"
#include "../board.h"

using std::string;

class Player
{
protected :

	/* holds what piece type this player should be used */
	SquareType piece_type;

	/* pointer to what board this player is playing on */
	Board *board;

public :

	Player(SquareType piece_type);

	virtual ~Player();

	/* makeMove: abstract method that makes a move on the board */
	virtual void makeMove() = 0;

	/* setBoard: sets the board used */
	void setBoard(Board *board);

	/* isWinner: returns true if this player has won, false otherwise */
	bool isWinner();

	/* getPiece: returns the string representation of this piece */
	string getPiece();

	/* getNumPieces: returns the number of pieces the player currently has on the board */
	int getNumPieces();
};

#endif
