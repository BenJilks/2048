#include <stdio.h>
#include <sys/time.h>
#include "Window.h"
#include "Board.h"

void TestKey(Board* board, int key, int dir, int* cooldown)
{
	if (WM_IsKeyDown(key) && !(*cooldown))
	{
		Bd_Move(board, dir);
		*cooldown = 1;
	}
}

int main()
{
	WM_Open("2048", 800, 600);

	int cooldown = 0;
	Board board = Bd_NewBoard();
	while (!WM_ShouldClose())
	{
		TestKey(&board, KEY_UP, DIR_UP, &cooldown);
		TestKey(&board, KEY_DOWN, DIR_DOWN, &cooldown);
		TestKey(&board, KEY_LEFT, DIR_LEFT, &cooldown);
		TestKey(&board, KEY_RIGHT, DIR_RIGHT, &cooldown);
		if (!WM_IsKeyDown(KEY_UP) && !WM_IsKeyDown(KEY_DOWN) && 
			!WM_IsKeyDown(KEY_LEFT) && !WM_IsKeyDown(KEY_RIGHT))
		{
			cooldown = 0;
		}
		WM_ClearInputBuffer();
		
		Bd_DrawBoard(board);
		WM_Update();
	}
	
	WM_Close();
	return 0;
}

