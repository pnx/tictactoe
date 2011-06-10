
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

    mouse.button = 0;
    mouse.state = 0;

    while(SDL_PollEvent(&event)) {

        switch(event.type) {
        case SDL_QUIT :
            isActive = false;
            break;
        case SDL_MOUSEBUTTONUP :
            mouse.button = event.button.button;
            mouse.x = event.motion.x;
            mouse.y = event.motion.y;
            mouse.state = event.button.state;
            break;
        case SDL_VIDEORESIZE:
            graphics->ResizeScreen(event.resize.w, event.resize.h);
            break;
        case SDL_VIDEOEXPOSE:
            // Rerender screen
            graphics->ClearScreen();
            DoRender();
            break;
        }
    }
}

void Engine::DoRender()
{
    Render();
    graphics->Draw();
}

void Engine::DoUpdate()
{
    Update();
}
