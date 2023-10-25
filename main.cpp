// tetris using c++ and raylib
// game will have 20 rows and 10 columns
// 7 different colored blocks (1-7), 0 is neutral
// 7 shapes called tetrominos
// rotations are handled through updating states 

#define _CRT_SECURE_NO_WARNINGS
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
	InitWindow(500, 620, "Tetris"); // sets the width and height of the game screen and initializes it
	SetTargetFPS(60); // game will run on 60fps
	
	Font font = LoadFontEx("Font/cabin.ttf", 64, 0, 0);

	Game game = Game();


	while (WindowShouldClose() == false) { // loop will continue till escape key or close icon is pressed
		game.handleInput();
		if (eventTriggered(0.3)) {
			game.moveBlockDown();
		}
		BeginDrawing(); // draw on canvas
		ClearBackground(navyBlue);
		DrawTextEx(font, "Score", { 365,15 }, 38, 2, WHITE);
		DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
		if (game.gameover)
		{
			DrawTextEx(font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
		}
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightblue);
		char scoreText[10];
		sprintf(scoreText, "%d", game.score);
		Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

		DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, WHITE);
		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightblue);
		game.draw();
		EndDrawing(); // end the drawing
	}

	CloseWindow(); // closes the window
}