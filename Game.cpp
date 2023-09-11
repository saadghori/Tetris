#include "Game.h"
#include <random>

Game::Game() {
	grid = Grid();
	blocks = getAllBlocks();
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
	gameover = false;
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
	if (gameover && keyPresed != 0) {
		gameover = false;
		reset();
	}
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
	if (!gameover) {
		currentBlock.move(0, -1);
		if (isBlockOutside() || blockFits() == false) {
			currentBlock.move(0, 1);
		}
	}
}

void Game::moveBlockRight()
{
	if (!gameover) {
		currentBlock.move(0, 1);
		if (isBlockOutside() || blockFits() == false) {
			currentBlock.move(0, -1);
		}
	}
	
}

void Game::moveBlockDown()
{
	if (!gameover) {
		currentBlock.move(1, 0);
		if (isBlockOutside() || blockFits() == false) {
			currentBlock.move(-1, 0);
			lockBlock();
		}
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
	if (!gameover) {
		currentBlock.rotate();
		if (isBlockOutside() || blockFits() == false) {
			currentBlock.undoRotation();
		}
	}
}

void Game::lockBlock()
{
	std::vector<Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles) {
		grid.grid[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if (blockFits() == false) {
		gameover = true;
	}
	nextBlock = getRandomBlock();
	grid.clearFullRows();


}

bool Game::blockFits()
{
	std::vector<Position> tiles = currentBlock.getCellPositions();
	for (Position item : tiles) {
		if (grid.isCellEmpty(item.row, item.column) == false) {
			return false;
		}
	}
	return true;
}

void Game::reset()
{
	grid.init();
	blocks = getAllBlocks();
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
}
