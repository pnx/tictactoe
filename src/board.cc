/* board.cc - Represents a 3x3 Tic-Tac-Toe board
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
#include "board.h"

using std::cout;
using std::cerr;
using std::endl;

Board::Board()
{
}

Board::~Board()
{
}

bool Board::validSquare(int position)
{
	if (position < 0 || position >= N_SQUARES) {
		cerr << "ERROR: invalid square index " << position << endl;
		return false;
	}

	return true;
}

Square* Board::getSquare(int index)
{
	return &square[index];
}

int Board::numberOfPieces(SquareType type)
{
	int i, m = 0;

	for(i=0; i < N_SQUARES; i++) {

		// count this square if matched
		if (square[i].getType() == type)
			m++;
	}

	return m;
}

void Board::setPiece(int position, SquareType type)
{
	if (!validSquare(position))
		return;

	square[position].setType(type);
}

void Board::delPiece(int position)
{
    if (!validSquare(position))
		return;

	square[position].setFree();
}

bool Board::isFree(int position)
{
	if (!validSquare(position))
		return false;

	return square[position].isFree();
}

bool Board::hasPiece(int position, SquareType type)
{
	if (!validSquare(position))
		return false;

	return square[position].getType() == type;
}

bool Board::hasCounterPiece(int position, SquareType type)
{
	if (!validSquare(position))
		return false;

	return !square[position].isFree() &&
		square[position].getType() != type;
}

bool Board::checkPattern(SquareType type)
{
	int i, j;

	for(i=0; i < 3; i++) {
		for(j=0; j < 3; j++) {
			if (square[(i*3)+j].getType() != type)
				break;

			if (j == 2)
				return true;
		}

		for(j=0; j < 3; j++) {
			if (square[i+(j*3)].getType() != type)
				break;

			if (j == 2)
				return true;
		}
	}

	/* Diagonal */

	for(i=0; i < 3; i++) {
		if (square[4*i].getType() != type)
			break;

		if (i == 2)
			return true;
	}

	for(i=1; i <= 3; i++) {
		if (square[2*i].getType() != type)
			break;

		if (i == 3)
			return true;
	}

	return false;
}

bool Board::isDraw(void)
{
	int i;

	for(i=0; i < N_SQUARES; i++) {

		if (square[i].getType() == SQUARE_EMPTY)
			return false;
	}
	return true;
}
