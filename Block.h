#pragma once
#include <vector>
#include <map>
#include "Position.h"
#include "Colors.h"

class Block
{
public:
	Block();
	int id; // id of each block
	std::map<int, std::vector<Position>> cells;
	void draw();
	void move(int rows, int columns);
	std::vector<Position> getCellPositions();
	void rotate();
	void undoRotation();
private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
	int rowOffset;
	int columnOffset;

};

