#include "Board.h"
#include "Window.h"
#include "Colour.h"
#include <memory.h>
#include <time.h>
#include <stdlib.h>

/* Rendering info */
#define WIDTH 500
#define HEIGHT 500
#define BOARDER 10
Vec2f container = {0.5f, 0.0f};

Board Bd_NewBoard()
{
	Board board;
	memset(board.tiles, 0, SIZE * sizeof(int));
	
	int i;
	srand(time(0));
	for (i = 0; i < SIZE; i++)
		if (rand() <= 0.2)
			board.tiles[i] = 2;
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
	int tileWidth = WIDTH - (BOARDER * ROWS);
	int tileHeight = HEIGHT - (BOARDER * COLUMNS);
	int xstep = tileWidth / ROWS;
	int ystep = tileHeight / COLUMNS;
	int x = (int)(index % ROWS) * xstep + BOARDER;
	int y = (int)(index / ROWS) * ystep + BOARDER;
	Vec2i start = {x, y};
	Vec2i size = {tileWidth, tileHeight};
	WM_DrawRect(start, size, Grey);
}

void Bd_DrawBoard(Board board)
{
	int i;
	WM_StartContainer(container);
	DrawBackground();
	for (i = 0; i < SIZE; i++)
		DrawTile(i, 2);
}

