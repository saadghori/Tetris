#pragma once
#include "grid.h"
#include "Blocks.cpp"


//this module is used to organise the game better and improve readibility


class Game
{
public:
	Game();
	Grid grid;
	Block getRandomBlock();
	std::vector<Block> getAllBlocks();
	void draw();
	void handleInput();
	void moveBlockLeft();
	void moveBlockRight();
	void moveBlockDown();
	bool gameover;
	int score;
private:
	bool isBlockOutside();
	void RotateBlock();
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
	void lockBlock();
	bool blockFits();
	void reset();
	void updateScore(int linesCleared, int moveDownPoints);
};