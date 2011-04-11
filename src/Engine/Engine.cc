
#include "Engine.h"

#include <iostream>
using std::cerr;
using std::endl;

Engine::Engine()
{
    graphics = new Graphics(640, 480, 16);
    isActive = false;
}

Engine::~Engine()
{
    delete graphics;
}

void Engine::Start() {

    Init();
    
    isActive = true;
    for(;;) {
        HandleInput();

        if (!isActive) {
            break;
        }

        // update and render
        DoUpdate();
        DoRender();
    }

    Exit();
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
