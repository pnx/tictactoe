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
	player[0] = new Human_Player(CROSS_PIECE);
	player[1] = new Computer_Player(CIRCLE_PIECE);
	
	// pass board to players
	player[0]->setBoard(board);
	player[1]->setBoard(board);

    txt = new Texture("resources/bg.png");
    txt1 = new Texture("resources/circle.png");
    txt2 = new Texture("resources/cross.png");
}

void Game::Exit()
{
	delete player[0];
	delete player[1];
	delete board;
	delete txt;
	delete txt1;
	delete txt2;
}

void Game::Update()
{
    if (mouse.state == SDL_RELEASED && mouse.button == SDL_BUTTON_LEFT) {
        moves++;
        cout << "Moves: " << moves << endl;
    }
}

void Game::Render()
{
    txt->Draw(0, 0);
    txt1->Draw(txt->getWidth() + 1, 0);
    txt2->Draw((txt1->getWidth() + 1) * 2, 0);
}
