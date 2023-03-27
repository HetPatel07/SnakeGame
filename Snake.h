#pragma once
#include "Coordinate.h"
#include "Region.h"
#include <vector>
using std::vector;
class Snake
{
private:
	vector<Coordinate> snakePosition;
	int length;
	Coordinate speed;
	Region map;
	Coordinate head;
	Coordinate tail;
	char direction;
	char prevDirection;
	
public:

	Snake(Region);
	Coordinate getHead();
	Coordinate getTail();
	int getLength();
	void changeDirection(char);
	char getDirection();
	vector<Coordinate> getSnakePosition();
	void move();
	void grow();
	void setStatus(bool);
	bool status;

//
//private:
//	void setPosition;
};

