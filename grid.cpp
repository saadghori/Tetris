#include <iostream>
#include "grid.h"
#include "Colors.h"

using namespace std;

Grid::Grid() {
	numOfRows = 20;
	numOfCols = 10;
	cellSize = 30;
	init();
	colors = getCellColors();
}

void Grid::init() {
	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < numOfCols; j++) {
			grid[i][j] = 0;
		}
	}
}

void Grid::print() {
	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < numOfCols; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}


void Grid::draw() {
	for (int y = 0; y < numOfRows; y++) {
		for (int x = 0; x < numOfCols; x++) {
			int cellValue = grid[y][x];
			DrawRectangle(x * cellSize + 1, y * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]); // leaving 1px margin
		}
	}
}

bool Grid::isCellOutside(int row, int column)
{
	bool outside = true;
	if (row >= 0 && row < numOfRows && column >= 0 && column < numOfCols) {
		outside = false;
	}
	
	return outside;
}
