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

#define DIR_UP    0
#define DIR_DOWN  1
#define DIR_LEFT  2
#define DIR_RIGHT 3
void Bd_Move(Board* board, int dir);

#endif //BOARD_H

