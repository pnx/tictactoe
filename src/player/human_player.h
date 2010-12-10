
#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "player.h"

class Human_Player : public Player
{
public :
	Human_Player(int piece_type);

	~Human_Player();

	/* makeMove: makes a move on the board */
	void makeMove();
};

#endif
