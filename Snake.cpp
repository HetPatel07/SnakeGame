#include "Snake.h"

Snake::Snake(Region map)
	:length(0),
	speed(Coordinate(1, 1)),
	map(map),
	head(Coordinate(0, 0)),
	tail(Coordinate(0, 0)),
	direction('U'),
	prevDirection(direction),
	status(true)
{
	for (int i = 0; i < 10; i++) {
		this->snakePosition.push_back(Coordinate(40, 15 + i));
	}
	head = snakePosition[0];
	tail = snakePosition[size(this->snakePosition) - 1];
	length = size(this->snakePosition);
}

Coordinate Snake::getHead()
{
	return head;
}

Coordinate Snake::getTail()
{
	return tail;
}

//Coordinate Snake::getTargetPosition()
//{
//	Coordinate targetPosition;
//	if (direction == 'U') {
//		
//	}
//	return targetPosition;
//}

int Snake::getLength()
{
	return length;
}

void Snake::changeDirection(char direction)
{
	prevDirection = this->direction;
	this->direction = direction;
}

char Snake::getDirection()
{
	return direction;
}


vector<Coordinate> Snake::getSnakePosition()
{
	return snakePosition;
}


void Snake::move()
{
	
		Coordinate targetPosition = { 0, 0 };
		if (direction == 'U') {
			Coordinate prevPosition = head;
			for (int i = 0; i < speed.Y; i++) {
				prevPosition = snakePosition[i];
				snakePosition[i].Y = snakePosition[i].Y - speed.Y;
				targetPosition = snakePosition[0] - Coordinate(0, speed.Y);
			}
			for (int i = speed.Y; i < length; i++) {
				Coordinate temp = snakePosition[i];
				snakePosition[i] = prevPosition;
				prevPosition = temp;
			}
		}
		else if (direction == 'L') {
			Coordinate prevPosition = head;
			for (int i = 0; i < speed.Y; i++) {
				prevPosition = snakePosition[i];
				snakePosition[i].X = snakePosition[i].X - speed.X;
				targetPosition = snakePosition[0] - Coordinate(0, speed.X);
			}
			for (int i = speed.Y; i < length; i++) {
				Coordinate temp = snakePosition[i];
				snakePosition[i] = prevPosition;
				prevPosition = temp;
			}
		}
		else if (direction == 'D') {
			Coordinate prevPosition = head;
			for (int i = 0; i < speed.Y; i++) {
				prevPosition = snakePosition[i];
				snakePosition[i].Y = snakePosition[i].Y + speed.Y;
				targetPosition = snakePosition[0] + Coordinate(0, speed.Y);
			}
			for (int i = speed.Y; i < length; i++) {
				Coordinate temp = snakePosition[i];
				snakePosition[i] = prevPosition;
				prevPosition = temp;
			}
		}
		else if (direction == 'R') {
			Coordinate prevPosition = head;
			for (int i = 0; i < speed.Y; i++) {
				prevPosition = snakePosition[i];
				snakePosition[i].X = snakePosition[i].X + speed.X;
				targetPosition = snakePosition[0] + Coordinate(0, speed.X);
			}
			for (int i = speed.Y; i < length; i++) {
				Coordinate temp = snakePosition[i];
				snakePosition[i] = prevPosition;
				prevPosition = temp;
			}
		}

		head = snakePosition[0];
		tail = snakePosition[size(this->snakePosition) - 1];
		//std::cout << map.getLe() << std::endl;
		if (targetPosition.Y == 31 || targetPosition.Y == 0|| targetPosition.X == 1 || targetPosition.X == 80) {
			status = false;
		}
		for (int i = 1; i < length; i++) {
			if (head == snakePosition[i]) {
				status = false;
			}
		}
	}
//HET
void Snake::grow()
{
	snakePosition.push_back(snakePosition[length - 1]);
	length++;
	tail = snakePosition[length - 1];
}
//HET
void Snake::setStatus(bool status)
{
	this->status = status;
}
