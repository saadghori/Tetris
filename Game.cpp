#include "Game.h"
#include <random>

Game::Game() {
	grid = Grid();
	blocks = getAllBlocks();
	currentBlock = getRandomBlock();
	nextBlock = getRandomBlock();
	gameover = false;
	score = 0;
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
	currentBlock.draw(11, 11);
	switch (nextBlock.id)
	{
	case 3:
		nextBlock.draw(255, 290);
		break;
	case 4:
		nextBlock.draw(255, 280);
		break;
	default:
		nextBlock.draw(270, 270);
		break;
	}
}

void Game::handleInput()
{
	int keyPressed = GetKeyPressed();
	if (gameover && keyPressed != 0)
	{
		gameover = false;
		reset();
	}
	switch (keyPressed)
	{
	case KEY_LEFT:
		moveBlockLeft();
		break;
	case KEY_RIGHT:
		moveBlockRight();
		break;
	case KEY_DOWN:
		moveBlockDown();
		updateScore(0, 1);
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
	for (Position item : tiles)
	{
		grid.grid[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if (blockFits() == false)
	{
		gameover = true;
	}
	nextBlock = getRandomBlock();
	int rowsCleared = grid.clearFullRows();
	if (rowsCleared > 0)
	{
		updateScore(rowsCleared, 0);
	}


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
	score = 0;
}

void Game::updateScore(int linesCleared, int moveDownPoints)
{
	switch (linesCleared)
	{
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	default:
		break;
	}

	score += moveDownPoints;
}
