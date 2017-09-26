#ifndef BOARD_H
#define BOARD_H

#define ROWS 4
#define COLUMNS 4
#define SIZE ROWS * COLUMNS

typedef struct Board
{
	int tiles[SIZE];
} Board;

Board Bd_NewBoard();
void Bd_DrawBoard(Board board);

#endif //BOARD_H

