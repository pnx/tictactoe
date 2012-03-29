
#include <iostream>
#include "SDL.h"
#include "Input/Mouse.h"

MouseState Mouse::mState = {
	MouseButtons::None, ButtonState::None
};

MouseState* Mouse::getState()
{
	return &mState;
}

void Mouse::Update()
{
	int x, y;
	Uint8 mask;

	SDL_PumpEvents();

	mask = SDL_GetMouseState(&x, &y);

	mState.point.x = (float) x;
	mState.point.y = (float) y;

	if (mask) {
		mState.State = ButtonState::Down;
		if (mask & SDL_BUTTON_LMASK) {
			mState.Button = MouseButtons::Left;
		} else if (mask & SDL_BUTTON_RMASK) {
			mState.Button = MouseButtons::Right;
		} else if (mask & SDL_BUTTON_MMASK) {
			mState.Button = MouseButtons::Middle;
		}
	} else if (mState.State == ButtonState::Down) {
		// trigger Up state one time after Down.
		mState.State = ButtonState::Up;
	} else {
		mState.Button = MouseButtons::None;
		mState.State = ButtonState::None;
	}
}