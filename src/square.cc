/* square.cc - Represents a square on the board
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

#include "square.h"

Square::Square() 
{
	// a new square is free
	setFree();
}

void Square::setFree() 
{
	free = 1;
	piece_type = NO_PIECE;
}

void Square::setPiece(int piece_type) 
{
	free = 0;
	this->piece_type = piece_type;
}

bool Square::hasPiece(int piece_type) 
{
	return this->piece_type == piece_type && free == 0;
}

char Square::getMarker()
{
	switch(piece_type) {
    case CIRCLE_PIECE :
        return M_CIRCLE;
    case CROSS_PIECE :
        return M_CROSS;
    default :
        return M_EMPTY;
	}
}

