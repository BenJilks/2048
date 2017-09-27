#include "Board.h"
#include "Window.h"
#include "Colour.h"
#include <memory.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Rendering info */
#define WIDTH 600
#define HEIGHT 600
#define BOARDER 10
Vec2f container = {0.5f, 0.0f};
Vec3f colours[] = {GREY, LIGHT_GRAY, FOUR, LIGHT_ORANGE, ORANGE, DARK_ORANGE};

Board Bd_NewBoard()
{
	Board board;
	memset(board.tiles, 0, SIZE * sizeof(int));
	
	int i;
	srand(time(0));
	for (i = 0; i < SIZE; i++)
	{
		board.tiles[i] = rand() % 10;
		/*if (rand() % 4 == 0)
		{
			board.tiles[i] = 1;
			if (rand() % 4 == 0)
				board.tiles[i] = 2;
		}*/
	}
	return board;
}

void DrawBackground()
{
	Vec2i start = {-(WIDTH/2.0f), 0};
	Vec2i size = {WIDTH, HEIGHT};
	WM_DrawRect(start, size, DarkGrey);
}

void DrawTile(int index, int value)
{
	/* Draw box */
	int tileWidth = ((WIDTH - BOARDER) / ROWS) - (BOARDER);
	int tileHeight = ((HEIGHT - BOARDER) / COLUMNS) - (BOARDER);
	int stepX = tileWidth + BOARDER;
	int stepY = tileHeight + BOARDER;
	int x = (int)((index % ROWS) * stepX) - (WIDTH/2) + BOARDER;
	int y = (int)(index / ROWS) * stepY + BOARDER;
	Vec2i start = {x, y};
	Vec2i size = {tileWidth, tileHeight};
	WM_DrawRect(start, size, value <= 5 ? colours[value] : Yellow);
	
	if (value > 0)
	{
		/* Draw number */
		char numberStr[80];
		sprintf(numberStr, "%i", (int)pow(2, value));
		Vec2i textPosition = {x + (tileWidth / 2.0f), y + (tileHeight / 2.0f)};
		WM_DrawText(numberStr, textPosition, "Testing.ttf", 60, 
			value <= 2 ? FirstNumber : White);
	}
}

void Bd_DrawBoard(Board board)
{
	int i;
	WM_StartContainer(container);
	DrawBackground();
	for (i = 0; i < SIZE; i++)
		DrawTile(i, board.tiles[i]);
}

void ScanTiles(Board* board, int from, int step, int dir)
{
	int x, y;
	for (x = 0; x < ROWS; x++)
	{
		for (y = from; y < COLUMNS && y >= 0; y += step)
		{
			ProcessTile(board, x, y);
		}
	}
}

void ScanColumns(Board* board, int from, int step)
{
	int x, y;
	for (y = 0; y < COLUMNS; y++)
		for (x = from; x < ROWS && x >= 0; x += step)
			ProcessTile(board, x, y);
}

void Bd_Move(Board* board, int dir)
{

}
