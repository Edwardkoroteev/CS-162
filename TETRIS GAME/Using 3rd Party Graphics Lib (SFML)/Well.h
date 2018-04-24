#ifndef TETRIS_WELL
#define TETRIS_WELL
#include "Tetrimino.h"

//constant
const int WELL_WIDTH = 12;
const int WELL_HEIGHT = 24;

class Well 
{
private: 
	int Width;
	int Height;
	char WellArray[WELL_HEIGHT][WELL_WIDTH];

public:
	//constructor
	Well();

	//Accessors
	int GetBoard();

	//Mutators
	void AddTetriminoToWell(Tetrimino TetrisPiece);
	int ClearFullRows();
	void MoveRowsDown(int FirstRowToMove);

	//Other
	bool RowIsFull(int Row); 
	bool TetriminoFit(Tetrimino TetrisPiece);
	bool TopReached();
	void GetBoard(char BoardOut[][WELL_WIDTH]);
	void BoardDump();
};

#endif