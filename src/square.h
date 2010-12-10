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

/* Character representations */
#define M_EMPTY	 0x20 /* whitespace */
#define M_CROSS  0x58 /* ASCII X */
#define M_CIRCLE 0x4F /* ASCII O */

/* types of piece's a square can be */
#define NO_PIECE     0
#define CIRCLE_PIECE 1
#define CROSS_PIECE  2

class Square
{
private:
	
	/* flag to indicate if a square is free or not */  
	bool free;
	
	/* the type of piece stored on the square if the 
	   square is not free, in this case the admissible 
	   values are CROSS_PIECE and CIRCLE_PIECE, 
	   otherwise the value NO_PIECE is used */ 
	int piece_type;

public:
	
	Square();
	
	/* setFree: mark this square as free */
	void setFree();
	
	/* isFree: returns true if square is free, false otherwise. */
	bool isFree() { return free; };
	
	/* setPiece: set this square as piece_type */
	void setPiece(int piece_type);
	
	/* getPiece: returns the piece of this square */
	int getPiece() { return piece_type; };
	
	/* hasPiece: return true if square is piece_type, false otherwise. */
	bool hasPiece(int piece_type);
	
	/* getMarker: returns the symbol representation of this square */
	char getMarker();
};

#endif
