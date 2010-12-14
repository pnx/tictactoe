/* computer_player.cc - Computer AI player
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

#include "computer_player.h"
#include "../square.h"

#include <iostream>
#include <cstdlib> /* used for RNG */
#include <ctime>

// msleep() - milliseconds sleep
#ifdef _WIN32
#include <windows.h>
#define msleep(x) Sleep(x)
#else
#include <unistd.h>
#define msleep(x) usleep((x) * 1000)
#endif

using std::cerr;
using std::endl;

// Initialize the map
const int Computer_Player::map[24][3] = {
	/* middle */
	{ 4, 0, 8 }, { 4, 2, 6 }, { 4, 1, 7 }, { 4, 3, 5 },
	/* corners */
	{ 0, 1, 2 }, { 0, 3, 6 }, { 0, 4, 8 },
	{ 2, 5, 8 }, { 2, 1, 0 }, { 2, 4, 6 },
	{ 8, 7, 6 }, { 8, 5, 2 }, { 8, 4, 0 },
	{ 6, 3, 0 }, { 6, 7, 8 }, { 6, 4, 2 },
	/* edge */
	{ 1, 0, 2 }, { 1, 4, 7 },
	{ 5, 2, 8 }, { 5, 4, 3 },
	{ 7, 8, 6 }, { 7, 4, 1 },
	{ 3, 6, 0 }, { 3, 4, 5 }
};

Computer_Player::Computer_Player(int piece_type) : Player(piece_type)
{
}

Computer_Player::~Computer_Player()
{
}

int Computer_Player::aiBestMove(int index = -1)
{
	/* Ordered list of best squares, 
	   best square first */
	int squares[9] = { 4, 0, 2, 6, 8, 1, 3, 7, 5 };
	
	for(int i=0; i < 9; i++) {
		
		if (squares[i] == index)
			continue;
		
		if (board->isFree(squares[i]))
			return squares[i];
	}
	
	return -1;
}

int Computer_Player::aiRandom()
{
	int position;

	do {
		// seed
		srand(time(NULL));
			
		// get random integer 
		position = rand() % N_SQUARES;
			
		// rest some time to free CPU cycles to the operating system
        msleep(1);
        
	} while(!board->hasPiece(position, piece_type));
	
	return position;
}

bool Computer_Player::aiWinPattern(const int p[])
{
	return board->isFree(p[0])
		&& board->hasPiece(p[1], piece_type) 
		&& board->hasPiece(p[2], piece_type);
}

bool Computer_Player::aiBlockPattern(const int p[])
{
	return board->hasCounterPiece(p[1], piece_type) 
		&& board->hasCounterPiece(p[2], piece_type);
}

int Computer_Player::aiFrom()
{
	int i;
	
	// begin by checking if any of the patterns will make a win
	for(i=0; i < 24; i++) {
		
		const int *pattern = map[i];
		
		// check this pattern
		if (!aiWinPattern(pattern))
			continue;
		
		// if matched, try find a piece that is not a part of this pattern.
		for(i=0; i < N_SQUARES; i++) {
					
			// skip this square if part of pattern or we will break it
			if (i == pattern[0] || i == pattern[1] || i == pattern[2])
				continue;
				
			if (board->hasPiece(i, piece_type))
				return i;
		}
		
		// should not get here
		break;
	}

	/* otherwise we go through all the patterns (lowest value first) 
	and pick one that is not part of a blocking pattern */

	// edges (2 patterns for each square)
	for(i=16; i < 24; i += 2) {
		
		if (!board->hasPiece(map[i][0], piece_type))
			continue;
			
		// check both patterns
		if (!aiBlockPattern(map[i]) && 
            !aiBlockPattern(map[i+1])) {
			return map[i][0];
		}
	}
	
	// corners (3 patterns for each square)
	for(i=4; i < 16; i += 3) {
		
		if (!board->hasPiece(map[i][0], piece_type))
			continue;
				
		if (!aiBlockPattern(map[i]) && 
            !aiBlockPattern(map[i+1]) &&
            !aiBlockPattern(map[i+2])) {
			return map[i][0];
		}
	}
	
	// middle
	if (board->hasPiece(4, piece_type) &&
        !aiBlockPattern(map[0]) &&
        !aiBlockPattern(map[1]) &&
        !aiBlockPattern(map[2]) &&
        !aiBlockPattern(map[3])) {
		return 4;
	}
	
	// select a square at random
	return aiRandom();
}

int Computer_Player::aiTo(int index)
{
	int i;
	
	// begin by check if a win pattern exist
	for(i=0; i < 24; i++) {
				
		if (map[i][0] == index)
			continue;
				
		// if this is a win pattern, return first index
		if (aiWinPattern(map[i]))
			return map[i][0];
	}
	
	// if no win pattern was found, try to block
	for(i=0; i < 24; i++) {
		
		if (map[i][0] == index)
			continue;
		
		if (!board->isFree(map[i][0]))
			continue;
		
		// if this is a block pattern, return first index
		if (aiBlockPattern(map[i]))
			return map[i][0];
	}
	
	return aiBestMove(index);
}

void Computer_Player::makeMove()
{
	int from = -1;
	int to;
	
	// remove one square
	if (board->numberOfPieces(piece_type) >= 3) {
		from = aiFrom();
		
		board->delPiece(from);
	}
	
	// find a square to move to
	to = aiTo(from);

	if (to == -1) {
		cerr << "AI ERROR: can't make move" << endl;
		return;
	}
	
	// make move
	board->setPiece(to, piece_type);
}
