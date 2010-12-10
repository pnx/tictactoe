
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
