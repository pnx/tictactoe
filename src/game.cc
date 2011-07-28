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
    moves = 0;

	// create a board
	board = new Board();

	// create players
	player[0] = new Human_Player(SQUARE_CIRCLE);
	player[1] = new Computer_Player(SQUARE_CROSS);

	// pass board to players
	player[0]->setBoard(board);
	player[1]->setBoard(board);

    bg = new Texture("resources/bg.png");
    cross = new Texture("resources/circle.png");
    circle = new Texture("resources/cross.png");
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
    MouseState *mouse = Mouse::getState();

    if (mouse->State == ButtonState::Up && mouse->Button == MouseButtons::Left) {
        moves++;
        cout << "Moves: " << moves << endl;
        cout << "Mouse cords: x = " << mouse->x << ", y = " << mouse->y << endl;

        // shift middle square between two pieces.
        // (just to make something happend on input)
        if (board->hasPiece(4, SQUARE_CROSS)) {
            board->setPiece(4, SQUARE_CIRCLE);
        } else {
            board->setPiece(4, SQUARE_CROSS);
        }
    }
}

void Game::Render()
{
    // TODO: needs refactoring.
    for(int i=0; i < N_SQUARES; i++) {

        Texture *txt;

        if (board->hasPiece(i, SQUARE_CROSS)) {
            txt = cross;
        } else if (board->hasPiece(i, SQUARE_CIRCLE)) {
            txt = circle;
        } else {
            txt = bg;
        }

		txt->Draw((txt->getWidth() + 1) * (i % 3), (txt->getHeight() + 1) * (i / 3));
	}
}
