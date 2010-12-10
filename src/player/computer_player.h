
#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "player.h"

class Computer_Player : public Player
{
private :
	
	/* 2 dimensional array of all possible patterns (on a 3x3 board) */
	static const int map[24][3];
	
	/* aiBestMove: will find the best moves based on a ordered list
	   if index is provided the method will make sure not to pick that index. */
	int aiBestMove(int index);
	
	/* aiRandom: makes a random move */
	int aiRandom();
	
	/* aiWinPattern: Return true if p is a winning pattern, false otherwise */
	bool aiWinPattern(const int p[]);
	
	/* aiBlockPattern: Returns true if p is a blocking pattern, false otherwise */
	bool aiBlockPattern(const int p[]);
	
	/* aiFrom: algorithm that finds the best square to move from */
	int aiFrom();
	
	/* aiFrom: algorithm that finds the best square to move to */
	int aiTo(int from);
	
public :
	
	Computer_Player(int piece_type);
	
	~Computer_Player();
	
	/* makeMove: makes a move on the board */
	void makeMove();
};

#endif
