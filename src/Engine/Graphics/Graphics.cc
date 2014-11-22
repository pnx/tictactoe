
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

	SetTitle("Window");

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
}

Graphics::~Graphics()
{
	if (screen) {
		SDL_FreeSurface(screen);
	}

	SDL_Quit();
}

void Graphics::InitWindow()
{
	SDL_Surface *newscreen = SDL_SetVideoMode(width, height, bpp, SDLflags);
	if (newscreen == NULL) {
		if (screen == NULL) {
			std::cerr << "Unable to set up video: " << SDL_GetError() << std::endl;
			exit(1);
		}
		std::cerr << "Unable to change size: " << SDL_GetError() << std::endl;
		return;
	}

	if (screen) {
		SDL_FreeSurface(screen);
	}
	screen = newscreen;

	InitGL();
}

void Graphics::InitGL()
{
	// setup opengl.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// disable depth and light.
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// setup ortho
	glOrtho(0.0f, this->width, this->height, 0.0f, -1.0f, 1.0f);
	glViewport(0, 0, this->width, this->height);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Graphics::SetTitle(const std::string& title)
{
	SDL_WM_SetCaption(title.c_str(), NULL);
}

bool Graphics::IsResizeAble()
{
	return SDLflags & SDL_RESIZABLE;
}

void Graphics::SetResizeAble(bool value)
{
	SDLflags = (value) ? SDLflags | SDL_RESIZABLE
			: SDLflags & ~SDL_RESIZABLE;

	// Initialize window with new flags
	InitWindow();
}

void Graphics::ResizeScreen(int width, int height)
{
	if (height < 64) {
		height = 64;
	}

	if (width < 64) {
		width = 64;
	}

	this->height = height;
	this->width = width;

	InitWindow();

#ifndef NDEBUG
	std::cout << "Windowsize: " << this->width << "x" << this->height << std::endl;
#endif
}

void Graphics::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Graphics::Draw()
{
	SDL_GL_SwapBuffers();
	SDL_Delay(1);
}
