/* square.h - Represents a square on the board
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

#ifndef SQUARE_H
#define SQUARE_H

/* types of piece's a square can be */
typedef enum {
	SQUARE_EMPTY = 0,
	SQUARE_CIRCLE,
	SQUARE_CROSS
} SquareType;

#include "gfx/Entity.h"

class Square : public Entity
{
private:
	SquareType type;

public:

	Square();

	/* setFree: mark this square as free */
	void setFree();

	/* isFree: returns true if square is free, false otherwise. */
	bool isFree();

	/* setPiece: set this square as piece_type */
	void setType(SquareType type);

	/* getPiece: returns the piece of this square */
	SquareType getType() { return type; };
};

#endif
