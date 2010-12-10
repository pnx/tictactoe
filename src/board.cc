
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
	if(position < 0 || position >= N_SQUARES) {
		cerr << "ERROR: invalid square index " << position << endl;
		return false;
	}
	
	return true;
}

int Board::numberOfPieces(int piece_type) 
{
	int i;
	int m = 0;
	
	for(i=0; i < N_SQUARES; i++) {
		
		// count this square if matched
		if(square[i].hasPiece(piece_type))
			if(++m == 3) break;
	}
	
	return m;
}

void Board::setPiece(int position, int piece_type)
{
	if(! validSquare(position))
		return;

    square[position].setPiece(piece_type);
}

void Board::delPiece(int position)
{
    if(! validSquare(position))
		return;
		
	square[position].setFree();
}

bool Board::isFree(int position)
{
	if(! validSquare(position))
		return false;
	
	return square[position].isFree();
}

bool Board::hasPiece(int position, int piece_type)
{
	if(! validSquare(position))
		return false;
		
	return square[position].hasPiece(piece_type);
}

bool Board::hasCounterPiece(int position, int piece_type)
{
	if(! validSquare(position))
		return false;
	
	return ! square[position].isFree() && ! square[position].hasPiece(piece_type);
}

bool Board::checkPattern(int piece_type) 
{
	int i, j;
	
	for(i=0; i < 3; i++) {
		for(j=0; j < 3; j++) {
			if(! square[(i*3)+j].hasPiece(piece_type))
				break;
			
			if(j == 2)
				return true;
		}

		for(j=0; j < 3; j++) {
			if(! square[i+(j*3)].hasPiece(piece_type))
				break;
			
			if(j == 2)
				return true;
		}
	}
	
	/* Diagonal */
	
	for(i=0; i < 3; i++) {
		if(! square[4*i].hasPiece(piece_type))
			break;
		
		if(i == 2)
			return true;
	}
	
	for(i=1; i <= 3; i++) {
		if(! square[2*i].hasPiece(piece_type))
			break;
			
		if(i == 3)
			return true;
	}
	
	return false;
}

void Board::display() 
{
	int i;
	
	/* Draw beginning line */
	cout << "+---+---+---+" << endl;

	/* For each square */
	for(i=0; i < N_SQUARES; i++) {
		
		/* Draw square */
		cout << "| " << square[i].getMarker() << " ";
		
		/* For every third square, close it and draw line-break */
		if((i+1) % 3 == 0) {
			cout << "|" << endl 
			     << "+---+---+---+" << endl;
	    }
	}
}
