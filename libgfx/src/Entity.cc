
#include "Entity.h"

Entity::Entity()
{
	height = 0;
	width = 0;
}

Entity::Entity(unsigned width, unsigned height)
{
	this->height = height;
	this->width = width;
}

bool Entity::Intersect(cord2f &point)
{
	cord2f p2(position.x + height,
		position.y + width);

	return point >= position && point <= p2;
}

void Entity::Draw(Texture *texture)
{
	texture->Draw(position.x, position.y, height, width);
}