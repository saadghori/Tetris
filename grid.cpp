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
			DrawRectangle(x * cellSize + 11, y * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]); // leaving 1px margin
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

bool Grid::isCellEmpty(int row, int column)
{
	if (grid[row][column] == 0) {
		return true;
	}
	return false;
}

int Grid::clearFullRows()
{
	int completed = 0;
	for (int row = numOfRows - 1; row >= 0; row--) {
		if (isRowFull(row)) {
			clearRow(row);
			completed++;
		}
		else if(completed > 0)
		{
			moveRowDown(row, completed);
		}
	}
	return completed;
}

bool Grid::isRowFull(int row)
{
	for (int column = 0; column < numOfCols; column++) {
		if (grid[row][column] == 0) {
			return false;
		}
	}
	return true;
}

void Grid::clearRow(int row)
{
	for (int col = 0; col < numOfCols; col++) {
		grid[row][col] = 0;
	}
}

void Grid::moveRowDown(int row, int numOfRows)
{
	for (int col = 0; col < numOfCols; col++) {
		grid[row + numOfRows][col] = grid[row][col];
		grid[row][col] = 0;
	}
}
