#include <stdio.h>
#include "Window.h"
#include "Board.h"

int main()
{
	WM_Open("Testing", 800, 600);
	Board board = Bd_NewBoard();
	while (!WM_ShouldClose())
	{
		Bd_DrawBoard(board);
		WM_Update();
	}
	WM_Close();
	return 0;
}

