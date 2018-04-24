/*=======================================================
name: Edward Koroteev
date: 2/3/2015
purpose: assign each of the tetrimino a certain color
and a location on the grid
=======================================================*/
#include"Well.h"
#include"Tetrimino.h"
#include"Game.h"
#include<iostream>

using namespace std;

/*======================================================
Function Name: Well (CLASS)
Arguements: None
Return: None
Purpose: Is a class and initalizes the Well of Tetris
         to all blank spots
========================================================*/
Well::Well()
{
	//variables
	int Width = WELL_WIDTH;
	int Height = WELL_HEIGHT;

	//loop through the 2D array and initialize
	//every spot to blanks ' '
	for(int row = 0; row < Height; row++)
	{
		for(int col = 0; col < Width; col++)
		{
			WellArray[row][col] = ' ';
		}
	}
}


/*============================================================
Function Name: TetriminoFit	(bool)
Arguements: Tetrimino	(TETRIMINO) Struct
return: True/False
purpose: Determine if the tetrimino in the current location
		 fits on the well
=============================================================*/
bool Well::TetriminoFit(Tetrimino TetrisPiece)
{
	//variables
	Location TetriminoLocation = TetrisPiece.getLocation();
	int TetriminoGrid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
	TetrisPiece.getGrid(TetriminoGrid);

	//Loop through tetrimino block and retrive 1s
	for(int row = 0; row < TETRIMINO_GRID_SIZE; row++)
	{
		for (int column = 0; column < TETRIMINO_GRID_SIZE; column++)
		{
			//Test if the current index of array is 1
			if (TetriminoGrid[row][column] == 1)
			{
				if(row + TetriminoLocation.row >= WELL_HEIGHT)
				{
					return false;
				}
				//If the piece fits in the columns
				if(column + TetriminoLocation.col < 0 || column + TetriminoLocation.col >= WELL_WIDTH)
				{
					return false;
				}
				//If the piece fits in the rows
				if(WellArray[row + TetriminoLocation.row][column + TetriminoLocation.col] != ' ')
				{
					return false;
				}
			}
		}
	}

	return true;
}


/*=======================================================
Function Name: AddTetriminoToWell	(VOID)
Arguements: Tetrimino (Struct)
return: none
purpose: Add a tetris piece into the well
=======================================================*/
void Well::AddTetriminoToWell(Tetrimino TetrisPiece)
{
	//variables
	int TetriminoGrid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
	TetrisPiece.getGrid(TetriminoGrid);
	Location TetriminoLocation = TetrisPiece.getLocation();


	//if(TetrisPiece == true)
	{
		for(int row = 0; row < TETRIMINO_GRID_SIZE; row++)
		{
			for (int column = 0; column < TETRIMINO_GRID_SIZE; column++)
			{
				if (TetriminoGrid[row][column] == 1)
				{
					WellArray[row + TetriminoLocation.row][column + TetriminoLocation.col] = 
						TetrisPiece.getColor();
				}
			}
		}
	}
}


/*=======================================================
Function Name: ClearFullRows	(INT)
Arguements: none
return: CounterRow
purpose: Clears the row that are full and determins the
		 amount of rows cleared
=======================================================*/
int Well::ClearFullRows()
{
	//variables
	int CounterRow = 0;

	for (int row = 0; row < WELL_HEIGHT; row++)
	{
		if(RowIsFull(row))
		{
			MoveRowsDown(row-1);
			CounterRow++;
		}
	}
	return CounterRow;
}


/*=======================================================
Function Name: RowIsFull	(BOOL)
Arguements: Row	(INT)
return: True/False
purpose: Determines if a row is full
=======================================================*/
bool Well::RowIsFull(int Row)
{
	for(int column = 0; column < WELL_WIDTH; column++)
	{
		if (WellArray[Row][column] == ' ')
		{
			return false;
		}
	}
	return true;
}


/*=============================================
Function Name: MoveRowsDown	(VOID)
Arguements: FirstRowToMove	(INT)
return: None
Purpose: Whenever a row is full, this function
		 moves the rows down that are clear
================================================*/
void Well::MoveRowsDown(int FirstRowToMove)
{
	for(int col = 0; col < WELL_WIDTH; col++)
	{
		for(int row = FirstRowToMove; row >= 0; row--)
		{
			WellArray[row+1][col] = WellArray[row][col];
		}
	}

	for(int col = 0; col < WELL_WIDTH; col++)
	{
		WellArray[0][col] = ' ';
	}
}


/*===========================================
Function Name: TopReached	(BOOL)
Arguements: None)
return: True/False
Purpose: returns a true of false if the top
		 row is full 
============================================*/
bool Well::TopReached()
{
	for(int col = 0; col < WELL_WIDTH; col++)
	{
		if(WellArray[0][col] != ' ')
		{
			return true;
		}
	}
	return false;
}


/*============================================
Funcion Name: GetBoard	(VOID)
Arguements: BoardOut	(CHAR) 2D Array
return: None
Purpose: Copies the well array into the new
		 modified well array
=============================================*/
void Well::GetBoard(char BoardOut[][WELL_WIDTH])
{
	for(int row = 0; row < WELL_HEIGHT; row++)
	{
		for (int column = 0; column < WELL_WIDTH; column++)
		{
			BoardOut[row][column] = WellArray[row][column];
		}
	}
}


/*====================================
Function Name: BoardDump	(VOID)
Arguements: None
return: None
Purpose: Cout of the Well Array
====================================*/
void Well::BoardDump()
{
	//variables
	char BoardArray[WELL_HEIGHT][WELL_WIDTH];
	
	//Store data into the variable
	GetBoard(BoardArray);

	for (int row = 0; row < WELL_HEIGHT; row++)
	{
		for (int col = 0; col < WELL_WIDTH; col++)
		{
			cout << BoardArray[row][col];
		}
		cout << endl;
	}
}

/*
void main()
{
	Tetrimino MyPiece(0);
	Well Board;

	MyPiece.setLocation(21,0);
	Board.AddTetriminoToWell(MyPiece);
	MyPiece.setLocation(21,4);
	Board.AddTetriminoToWell(MyPiece);
	Board.BoardDump();

	cout << "___________________________________________" << endl;

	MyPiece.rotateLeft();
	MyPiece.setLocation(19,0);
	Board.AddTetriminoToWell(MyPiece);
	Board.BoardDump();

	cout << "-------------------------------------------------"<< endl;
	Board.ClearFullRows();
	Board.BoardDump();
	cout << "Test Clear Full Rows" << endl;

	cout << "_________________________________________________"<<endl;

		cin.get();
		cin.ignore();
}
*/