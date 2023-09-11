#pragma once
#include <raylib.h>
#include <vector>

class Grid
{
public:
	Grid(); // sets the number of rows and columns in the grid. Also the cell size in pixels.
	void init(); // sets all the elements in the grid array to 0
	int grid[20][10]; // 20 rows and 10 columns
	void print(); // prints the grid on the screen
	void draw(); // draw squares using raylib library (DrawRectangle)
	bool isCellOutside(int row, int column);
	bool isCellEmpty(int row, int column);
	int clearFullRows();
private:
	bool isRowFull(int row);
	void clearRow(int row);
	void moveRowDown(int row, int numOfRows);
	int numOfRows;
	int numOfCols;
	int cellSize;
	std::vector<Color> colors; // dynamic array
};


