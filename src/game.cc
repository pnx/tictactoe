/* game.cc - Overall game logic
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

#include <iostream>

#include "game.h"
#include "player/computer_player.h"
#include "player/human_player.h"
#include "square.h"

using std::cout;
using std::endl;

void Game::Init()
{
	graphics->SetResizeAble(false);
	graphics->SetTitle("TicTacToe");

	moves = 0;

	inProgress = true;

	// create a board
	board = new Board();

	// create players
	player[0] = new Human_Player(SQUARE_CIRCLE);
	player[1] = new Computer_Player(SQUARE_CROSS);

	// pass board to players
	player[0]->setBoard(board);
	player[1]->setBoard(board);

	current_player = 0;

	bg = new Texture("resources/bg.png");
	cross = new Texture("resources/cross.png");
	circle = new Texture("resources/circle.png");

	// setup squares
	for(int i = 0; i < N_SQUARES; i++) {
		Square *s = board->getSquare(i);
		cord2f pos;

		s->height = bg->getHeight();
		s->width = bg->getWidth();

		pos.x = (bg->getWidth() + 1) * (i % 3);
		pos.y = (bg->getHeight() + 1) * (i / 3);

		s->setPosition(pos);
	}
}

void Game::Exit()
{
	delete player[0];
	delete player[1];
	delete board;
	delete bg;
	delete cross;
	delete circle;
}

void Game::Update()
{
	if (!inProgress) {
		return;
	}

	if (player[current_player]->makeMove()) {
		moves++;

		if (player[current_player]->isWinner() || board->isDraw()) {
			inProgress = false;
		}
		current_player = (current_player + 1) % N_PLAYERS;
	}
}

void Game::Render()
{
	// TODO: needs refactoring.
	for(int i=0; i < N_SQUARES; i++) {
		Texture *t = bg;
		Square *s = board->getSquare(i);

		if (s->getType() == SQUARE_CROSS) {
			t = cross;
		} else if (s->getType() == SQUARE_CIRCLE) {
			t = circle;
		}

		s->Draw(t);
	}
}
