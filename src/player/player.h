
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "../square.h"
#include "../board.h"

using std::string;

class Player
{
protected :
	
	/* holds what piece_type this player should be used */
	int piece_type;
	
	/* pointer to what board this player is playing on */
	Board *board;
	
public :
	
	Player(int piece_type);
    
	virtual ~Player();
	
	/* makeMove: abstract method that makes a move on the board */
	virtual void makeMove() = 0;
	
	/* setBoard: sets the board used */
	void setBoard(Board *board);
	
	/* isWinner: returns true if this player has won, false otherwise */
	bool isWinner();
	
	/* getPiece: returns the string representation of this piece */
	string getPiece();
	
	/* getNumPieces: returns the number of pieces the player currently has on the board */
	int getNumPieces();
};

#endif
