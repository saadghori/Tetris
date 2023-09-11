#include "Game.h"
#include <random>

Game::Game() {
	grid = Grid();
	blocks = getAllBlocks();
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
}

Block Game::getRandomBlock() { //each block will appear once randomly before the cycle repeats
	
	if (blocks.empty()) {
		blocks = getAllBlocks();
	}
	int randomIndex = rand() % blocks.size(); // we get a random number within the array size (0-6)
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;

}

std::vector<Block> Game::getAllBlocks() {
	return { Ishape(), Jshape(), Lshape(), Oshape(), Tshape(), Zshape(), Sshape() };
}

void Game::draw() {
	grid.draw();
	currentBlock.draw();
}

void Game::handleInput()
{
	int keyPresed = GetKeyPressed();
	switch (keyPresed)
	{
	case KEY_LEFT:
		moveBlockLeft();
		break;
	case KEY_RIGHT:
		moveBlockRight();
		break;
	case KEY_DOWN:
		moveBlockDown();
		break;
	case KEY_UP:
		RotateBlock();
		break;
	}
}

void Game::moveBlockLeft()
{
	currentBlock.move(0, -1);
	if (isBlockOutside()) {
		currentBlock.move(0, 1);
	}
}

void Game::moveBlockRight()
{
	currentBlock.move(0, 1);
	if (isBlockOutside()) {
		currentBlock.move(0, -1);
	}
}

void Game::moveBlockDown()
{
	currentBlock.move(1, 0);
	if (isBlockOutside()) {
		currentBlock.move(-1, 0);
	}
}

bool Game::isBlockOutside()
{
	bool outside = false;
	std::vector<Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles) {
		if (grid.isCellOutside(item.row, item.column)) {
			outside = true;
		}
	}

	return outside;
}

void Game::RotateBlock()
{
	currentBlock.rotate();
	if (isBlockOutside()) {
		currentBlock.undoRotation();
	}
}
