#include "Apple.h"

Apple::Apple(Region map)
	:map(map),
	position(Coordinate(0,0))
{
	int randomX = Random::getInteger(map.getLeft(),map.getRight());
	int randomY = Random::getInteger(map.getTop(), map.getBottom());
	position = Coordinate(randomX, randomY);
}

Coordinate Apple::getPosition()
{
	return position;
}

void Apple::newPosition()
{
	int randomX = Random::getInteger(map.getLeft(), map.getRight());
	int randomY = Random::getInteger(map.getTop(), map.getBottom());
	position = Coordinate(randomX, randomY);
}



