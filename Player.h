#pragma once
#include "DateTime.h"
using namespace utility;
class Player
{
private:
	int score;
	int totalTime;

public:
	Player();
	void updateScore();
	int getScore();
	int getTimePlayer();
	void setTime(int);
};

