
#include <iostream>
#include "human_player.h"

using namespace std;

Human_Player::Human_Player(int piece_type) : Player(piece_type)
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
	
	if(board->numberOfPieces(piece_type) < 3) {
		
		do {
			cout << "to where? a number in the range [0-8]: ";
			cin  >> to;
		} while(! board->isFree(to));
		
	} else {
	
		do {	
			cout << "from where to where? two numbers in the range [0-8]: ";
			cin  >> from 
				 >> to;
		} while(! board->isFree(to) || ! board->hasPiece(from, piece_type));
	
		board->delPiece(from);
	}
	
	board->setPiece(to, piece_type);
}
