// tetris using c++ and raylib
// game will have 20 rows and 10 columns
// 7 different colored blocks (1-7), 0 is neutral
// 7 shapes called tetrominos
// rotations are handled through updating states 

#include <raylib.h>
#include "Game.h"

double lastUpdateTime{ 0 };
bool eventTriggered(double interval){ // function that delays the freefall movement of the blocks
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}

	return false;
}

int main() {

	Color navyBlue = { 18, 0, 82, 255 }; // initializing the color struct
	InitWindow(300, 600, "Tetris"); // sets the width and height of the game screen and initializes it
	SetTargetFPS(60); // game will run on 60fps
	
	Game game = Game();

	while (WindowShouldClose() == false) { // loop will continue till escape key or close icon is pressed
		game.handleInput();
		if (eventTriggered(0.3)) {
			game.moveBlockDown();
		}
		BeginDrawing(); // draw on canvas
		ClearBackground(navyBlue);
		game.draw();
		EndDrawing(); // end the drawing
	}

	CloseWindow(); // closes the window
}