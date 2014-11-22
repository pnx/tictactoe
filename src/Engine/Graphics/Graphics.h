
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

	void InitWindow();
	void InitGL();
public:
	Graphics(int width, int height, int bpp);
	~Graphics();

	void SetTitle(const std::string& title);

	bool IsResizeAble();
	void SetResizeAble(bool value);

	void ResizeScreen(int width, int height);

	void ClearScreen();

	void Draw();
};

#endif /* ENGINE_GRAPHICS_GRAPHICS_H */
