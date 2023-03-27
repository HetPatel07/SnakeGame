#pragma once
#include "Region.h"
#include "ConsoleReader.h"
#include "ConsoleWriter.h"
#include "Snake.h"
#include "Apple.h"
#include "Player.h"
#include "DateTime.h"
using namespace utility;
class SnakeGame
{
private:
	Snake snake;
	Region map;
	ConsoleReader reader;
	ConsoleWriter writer;
	Apple apple;
	Player player;
	int startTime;

	
public:
	SnakeGame();
	void start();  
	void eraseObjects();
	void handleInput();
	void updateObjects();
	void displayObjects();

};

