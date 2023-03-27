#pragma once
#include "Region.h"
#include "Coordinate.h"
#include "Random.h"
using namespace utility;
class Apple
{
private:
	Region map;
	Coordinate position;
public: 
	Apple(Region);

	Coordinate getPosition();
	void newPosition();
};

