
#include "Graphics.h"
#include "Texture.h"

Graphics::Graphics(int width, int height, int bpp)
{
    const SDL_VideoInfo* videoInfo;

	// Initialize SDL video
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Unable to init SDL: " << SDL_GetError() << std::endl;
		exit(1);
	}

    SDLflags = SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_HWPALETTE | SDL_RESIZABLE;

    videoInfo = SDL_GetVideoInfo();
    if (videoInfo->hw_available) {
        SDLflags |= SDL_HWSURFACE;
    } else {
	    SDLflags |= SDL_SWSURFACE;
    }

    // check hardware blitting support
    if (videoInfo->blit_hw) {
        SDLflags |= SDL_HWACCEL;
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    atexit(SDL_Quit);

    this->bpp = bpp;
    this->screen = NULL;

    ResizeScreen(width, height);

    SDL_WM_SetCaption("Title", NULL);
}

Graphics::~Graphics()
{
    SDL_Quit();
}

void Graphics::InitGL()
{
    // setup opengl.
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(0.0f);
    glViewport(0, 0, this->width, this->height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glLoadIdentity();
    glPushMatrix();

    // setup ortho
    glOrtho(0.0f, this->width, this->height, 0.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
}

void Graphics::ResizeScreen(int width, int height)
{
    SDL_Surface *newscreen;

    if (height < 64) {
        height = 64;
    }

    if (width < 64) {
        width = 64;
    }

    this->height = height;
    this->width = width;

    newscreen = SDL_SetVideoMode(this->width, this->height, this->bpp, this->SDLflags);
	if (newscreen == NULL) {
        if (screen == NULL) {
            std::cerr << "Unable to set up video: " << SDL_GetError() << std::endl;
            exit(1);
        }
        std::cerr << "Unable to change size: " << SDL_GetError() << std::endl;
        return;
	}

    if (this->screen) {
        SDL_FreeSurface(this->screen);
    }
    this->screen = newscreen;

    InitGL();
}

void Graphics::Draw()
{
    SDL_GL_SwapBuffers();
    SDL_Delay(1);
}