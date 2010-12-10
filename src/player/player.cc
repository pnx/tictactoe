/* player.cc - Base class for a player
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

#include "player.h"

Player::Player(int piece_type)
{
	this->piece_type = piece_type;
}

Player::~Player()
{
}

bool Player::isWinner()
{
	return board->checkPattern(piece_type);
}

string Player::getPiece()
{
	return (piece_type == CROSS_PIECE) 
		 ? "CROSSES" : "CIRCLES";
}

int Player::getNumPieces()
{
	return board->numberOfPieces(piece_type);
}

void Player::setBoard(Board *board) 
{
	this->board = board;
}
