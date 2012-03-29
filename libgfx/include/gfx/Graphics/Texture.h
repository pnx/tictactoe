
#ifndef ENGINE_GRAPHICS_TEXTURE_H
#define ENGINE_GRAPHICS_TEXTURE_H

#include "internal.h"

class Texture {

private :
	GLuint id;
	int width;
	int height;
	std::string filename;

public :
	Texture();
	Texture(std::string filename);
	~Texture();

	int getWidth() { return width; };
	int getHeight() { return height; };

	void Load(std::string filename);

	void Reload();

	void Delete();

	void Draw(GLint x, GLint y, unsigned height = 0, unsigned width = 0);
};

#endif /* ENGINE_GRAPHICS_TEXTURE_H */
