
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
	int numberOfPieces(int piece_type);
	
	/* setPiece: sets a piece of piece_type on position */
	void setPiece(int position, int piece_type);
	
	/* delPiece: deletes the piece on position */
	void delPiece(int position);
	
	/* isFree: returns true if this position is free, false otherwise */
	bool isFree(int position);
	
	/* hasPiece: returns true if position has a piece of piece_type, false otherwise */
	bool hasPiece(int position, int piece_type);
	
	/* hasCounterPiece: returns true if position occupied but IS NOT piece_type, false otherwise */
	bool hasCounterPiece(int position, int piece_type);
	
	/* checkPattern: checks if a board has a win pattern of piece_type */
	bool checkPattern(int piece_type);
	
	/* drawBoard: draws the board on the screen */
	void display();
};

#endif
