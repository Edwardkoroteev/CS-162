/*====================================================================
 Programmer: Edward Koroteev
 Program Name: Multi-Dimensional Arrays
 Date: 1/17/2015
 Purpose: Create tetrenino (tetirs blocks) using multi demsnional arrys
 ======================================================================*/
#include<iostream>

using namespace std;

//constants
const int ARRAY_SIZE = 4;

//Function Prototypes
void PrintTetrimino(int TetriminoArray[][ARRAY_SIZE], int ArraySize);
void RotateTetrminoLeft(int TetriminoArray[][ARRAY_SIZE], int ArraySize);
void RotateTetrminoLeft(int TetriminoArray[][ARRAY_SIZE], int ArraySize);

void main ()
{
	//Arrays
	//flat Tetrimino
	int FlatTetrimino[ARRAY_SIZE][ARRAY_SIZE] =
	{
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0}
	};
	// L shaped tetrimino
	int LTetrimino[ARRAY_SIZE][ARRAY_SIZE] =
	{
		{0,0,0,0},
		{0,1,0,0},
		{0,1,1,1},
		{0,0,0,0},
	};
	int TTetriminoTemp[ARRAY_SIZE][ARRAY_SIZE];
	int TTetrimino[ARRAY_SIZE][ARRAY_SIZE] =
	{
		{0,0,0,0},
		{0,0,1,0},
		{0,1,1,1},
		{0,0,0,0},
	};

	
	cin.get();
	cin.ignore();
}


/*==============================================
Function Name: RotateTetrminoLeft
Description: This will rotate the tetrimino left when it is sent in.
Arguements:
	-	Tetrimino[][ARRAY_SIZE] (int)
	-	ArraySize (int)
	-	
================================================*/
void RotateTetrminoLeft(int TetriminoArray[][ARRAY_SIZE], int ArraySize)
{
	//varibales
	int TempArray[ARRAY_SIZE][ARRAY_SIZE];

	//Loop through the individual spots of an array and rotate it
	for(int row = 0; row < ArraySize; row++)
	{
		for (int column = 0; column < ArraySize; column++)
		{
			TempArray[row][column] = TetriminoArray[column][3-row];
		}
	}

	for(int row = 0; row < ArraySize; row++)
	{
		for (int column = 0; column < ArraySize; column++)
		{
			TetriminoArray[row][column] = TempArray[row][column];
		}
	}
	/*for (int row = 0; row < ArraySize; row++)
	{
		for(int column = 0; column < ARRAY_SIZE; column++)
		{
			cout << TempArray[row][column] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	
}


void PrintTetrimino(int TetriminoArray[][ARRAY_SIZE], int ArraySize)
{
	//loop through and print each element
	for (int row = 0; row < ArraySize; row++)
	{
		for(int column = 0; column < ARRAY_SIZE; column++)
		{
			cout << TetriminoArray[row][column] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
