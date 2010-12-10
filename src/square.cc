
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

