
#include "engine.h"

#include <iostream>
using std::cerr;
using std::endl;

Engine::Engine()
{
    screen = NULL;
    
	// Initialize SDL video
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "Unable to init SDL: " << SDL_GetError() << endl;
		exit(1);
	}

    SetSize(480, 640);
}

Engine::~Engine()
{
    if (screen) {
        SDL_FreeSurface(screen);
    }
    SDL_Quit();
}

void Engine::SetSize(int height, int width)
{
    height = (unsigned) height;
    width = (unsigned) width;
    
    SDL_Surface *newscreen = SDL_SetVideoMode(width, height, 0, SDL_SWSURFACE);
	if (newscreen == NULL) {
        if (screen == NULL) {
            cerr << "Unable to set up video: " << SDL_GetError() << endl;
            exit(1);
        }
        cerr << "Unable to change size: " << SDL_GetError() << endl;
        return;
	}
    
    if (screen) {
        SDL_FreeSurface(screen);
    }
    screen = newscreen;
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
        }
    }
}

void Engine::DoRender()
{
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

    Render(screen);

    SDL_Flip(screen);
}

void Engine::DoUpdate()
{
    Update();
}
