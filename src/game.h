
#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player/player.h"

#define N_PLAYERS 2

class Game
{
private :
	
	/* holds the board */
	Board *board;
	
	/* set of players */
	Player *player[N_PLAYERS];
	
public :

	Game();
	
	~Game();
	
	/* game: Run a tic tac toe game */
	void play(void);
};

#endif
