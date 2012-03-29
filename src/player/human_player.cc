/* human_player.cc - Human player using the keyboard as input.
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
#include "human_player.h"
#include <gfx/Input/Mouse.h>

using namespace std;

Human_Player::Human_Player(SquareType piece_type) : Player(piece_type)
{
}

Human_Player::~Human_Player()
{
}

bool Human_Player::makeMove()
{
	MouseState *mouse = Mouse::getState();

	if (mouse->State == ButtonState::Up && mouse->Button == MouseButtons::Left) {

		for(int i = 0; i < N_SQUARES; i++) {
			Square *s = board->getSquare(i);

			if (s->Intersect(mouse->point) && s->isFree()) {
				s->setType(piece_type);
				return true;
			}
		}
	}
	return false;
}
