
#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include "Graphics/Texture.h"
#include "Math/MathTypes.h"

class Entity {

private:
	// the texture this entety currently has.
	Texture *texture;

	cord2f position;

public:
	unsigned width;

	unsigned height;

	Entity();

	Entity(unsigned width, unsigned height);

	void setPosition(cord2f position) { this->position = position; };

	cord2f getPosition() { return position; };

	void setTexture(Texture *texture) { this->texture = texture; };

	Texture* getTexture(void) { return texture; };

	bool Intersect(cord2f &point);

	void Draw(Texture *texture);
};

#endif /* ENGINE_ENTITY_H */