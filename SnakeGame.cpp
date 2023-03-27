#include "SnakeGame.h"

SnakeGame::SnakeGame()
	:
	map(Coordinate(1, 1), Coordinate(80, 30)),
	reader(),
	writer(),
	snake(map),
	apple(map),
	player(),
	startTime(DateTime::getNow().getSecond())
{
}

void SnakeGame::start()
{
	// Initialize  
	writer.drawRectangle(map.getTopLeft() - Coordinate(1,1), map.getBottomRight() +Coordinate(1, 1));
	writer.setWindowSize(83, 40);
	//player.setTime(0);
	while (true)
	{
		eraseObjects();
		handleInput();
		updateObjects();
		displayObjects();
		Sleep(100);
	}
}

void SnakeGame::eraseObjects()
{
	for (int i = 0; i < snake.getLength(); i++) {
		writer.clearRegion(snake.getSnakePosition()[i], snake.getSnakePosition()[i]);
	}
		
}

void SnakeGame::handleInput()
{

	// Use reader to check up/down arrow keys
	if (reader.isUpArrowPressed()) {
		if(snake.getDirection() != 'D')
			snake.changeDirection('U');

	}
	else if (reader.isDownArrowPressed()) {
		if (snake.getDirection() != 'U')
			snake.changeDirection('D');

	}
	else if (reader.isLeftArrowPressed()) {
		if (snake.getDirection() != 'R')
			snake.changeDirection('L');
	}
	else if (reader.isRightArrowPressed()) {
		if (snake.getDirection() != 'L')
			snake.changeDirection('R');
	}

	if (snake.status == true) {
		snake.move();
	}
	if (snake.status == false && (reader.isKeyPressed('L') || reader.isKeyPressed('R') || reader.isKeyPressed('U') || reader.isKeyPressed('D'))) {
		std::cout << "ho";
		snake.setStatus(true);
		snake.changeDirection('R');
	}
		
}		

void SnakeGame::updateObjects()
{
	if (snake.getHead() == apple.getPosition()) {
		snake.grow();
		apple.newPosition();
		player.updateScore();
		player.setTime(startTime);
	}
	writer.setCursorPosition(1, 32);    
	writer.writeLine("Player Score : ");
	writer.setCursorPosition(1, 33);
	writer.write(player.getScore());
	writer.setCursorPosition(40, 32);
	writer.writeLine("Time Played: ");
	writer.setCursorPosition(40, 33);
	if(snake.status)
		writer.write(DateTime::getNow().getSecond());
	else
		writer.write(player.getTimePlayer());
	writer.setCursorPosition(0,0);
}

void SnakeGame::displayObjects()
{
	for (int i = 0; i < snake.getLength(); i++) {
		writer.fillRegion('O', snake.getSnakePosition()[i], snake.getSnakePosition()[i]);
	}
	writer.fillRegion('H', snake.getHead(), snake.getHead());
	writer.fillRegion('T', snake.getTail(), snake.getTail());
	writer.fillRegion('A', apple.getPosition(), apple.getPosition());
	if (snake.status == false) {
		writer.setCursorPosition(30, 32);
		writer.write("Game Over");
		writer.setCursorPosition(20, 36);
		writer.write("Press esc to exit or press enter key to continue ");
	}
}
