
#ifndef ENGINE_GRAPHICS_GRAPHICS_H
#define ENGINE_GRAPHICS_GRAPHICS_H

#include "internal.h"

class Graphics
{
private:
	int height;
	int width;
	int bpp;
	unsigned SDLflags;
	SDL_Surface* screen;

	void InitGL();
public:
	Graphics(int width, int height, int bpp);
	~Graphics();

	bool IsResizeAble();
	void SetResizeAble(bool value);

	void ResizeScreen(int width, int height);

	void ClearScreen();

	void Draw();
};

#endif /* ENGINE_GRAPHICS_GRAPHICS_H */
