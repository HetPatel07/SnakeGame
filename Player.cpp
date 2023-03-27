#include "Player.h"


Player::Player()
	:score(0),
	totalTime(0)
{
}

void Player::updateScore() {
	score++;
}

int Player::getScore() {
	return score;
}

int Player::getTimePlayer()
{
	return totalTime;
}

void Player::setTime(int startTime)
{
	totalTime = DateTime::getNow().getSecond() - startTime;
}
