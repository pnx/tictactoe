
#include "Engine.h"

#include <iostream>
using std::cerr;
using std::endl;

Engine::Engine()
{
	graphics = new Graphics(640, 480, 16);
	isActive = false;
	FixedStep = true;
	FixedStepInterval = 10;
}

Engine::~Engine()
{
	delete graphics;
}

void Engine::Start() {

	Init();

	SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);

	LastTick = SDL_GetTicks();

	isActive = true;
	while(isActive) {
		if (FixedStep) {
			long delta = SDL_GetTicks() - LastTick;
			if (delta >= FixedStepInterval) {
				Tick();
			}
		} else {
			Tick();
		}
		SDL_Delay(1);
	}

	Exit();
}

void Engine::Tick()
{
	HandleInput();

	if (!isActive) {
		return;
	}

	// update and render
	DoUpdate();
	DoRender();

	LastTick = SDL_GetTicks();
}

void Engine::HandleInput()
{
	SDL_Event event;

	Mouse::Update();

	while(SDL_PollEvent(&event)) {

		switch(event.type) {
		case SDL_QUIT :
			isActive = false;
			break;
		case SDL_VIDEORESIZE:
			graphics->ResizeScreen(event.resize.w, event.resize.h);
			break;
		case SDL_VIDEOEXPOSE:
			// Rerender screen
			DoRender();
			break;
		}
	}
}

void Engine::DoRender()
{
	graphics->ClearScreen();
	Render();
	graphics->Draw();
}

void Engine::DoUpdate()
{
	Update();
}
