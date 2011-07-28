
#include <iostream>
#include "Mouse.h"
#include "SDL.h"

MouseState Mouse::mState = {
	MouseButtons::None, ButtonState::None, 0, 0
};

MouseState* Mouse::getState()
{
	return &mState;
}

void Mouse::Update()
{
	Uint8 mask;

	SDL_PumpEvents();

	mask = SDL_GetMouseState(&mState.x, &mState.y);
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