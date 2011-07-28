/* human_player.cc - Human player using the keyboard as input.
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
#include "human_player.h"

using namespace std;

Human_Player::Human_Player(SquareType piece_type) : Player(piece_type)
{
}

Human_Player::~Human_Player()
{
}

void Human_Player::makeMove()
{
	// Holds the position of the piece to be moved
	int from;

	// Hold the position of the square that should be moved to
	int to;

	if (board->numberOfPieces(piece_type) < 3) {

		do {
			cout << "to where? a number in the range [0-8]: ";
			cin  >> to;
		} while(!board->isFree(to));

	} else {

		do {
			cout << "from where to where? two numbers in the range [0-8]: ";
			cin  >> from
				 >> to;
		} while(!board->isFree(to) || !board->hasPiece(from, piece_type));

		board->delPiece(from);
	}

	board->setPiece(to, piece_type);
}
