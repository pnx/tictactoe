/* board.h - Represents a 3x3 Tic-Tac-Toe board
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

#ifndef BOARD_H
#define BOARD_H

#include "square.h"

/* number of squares on the board */
#define N_SQUARES 9

class Board
{
private:

	/* set of squares to play on */
	Square square[N_SQUARES];

	/* validSquare: returns true if position is a valid square (in range) */
	bool validSquare(int position);

public:

	/* Constructor */
	Board();

	/* Destructor */
	~Board();

	/* numberOfPieces: returns the number of piece_type pieces placed on the board */
	int numberOfPieces(SquareType type);

	/* setPiece: sets a piece of piece_type on position */
	void setPiece(int position, SquareType type);

	/* delPiece: deletes the piece on position */
	void delPiece(int position);

	/* isFree: returns true if this position is free, false otherwise */
	bool isFree(int position);

	/* hasPiece: returns true if position has a piece of piece_type, false otherwise */
	bool hasPiece(int position, SquareType type);

	/* hasCounterPiece: returns true if position occupied but IS NOT piece_type, false otherwise */
	bool hasCounterPiece(int position, SquareType type);

	/* checkPattern: checks if a board has a win pattern of piece_type */
	bool checkPattern(SquareType type);
};

#endif
