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
void RotateTetrminoRight(int TetriminoArray[][ARRAY_SIZE], int ArraySize);

void main ()
{
	
	//_______________CREATION OF ARRAYS BELOW_________________
	// I shaped Tetrimino
	int ITetrimino[ARRAY_SIZE][ARRAY_SIZE] =
	{
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0}
	};

	// J shaped tetrimino
	int JTetrimino[ARRAY_SIZE][ARRAY_SIZE] =
	{
		{0,0,0,0},
		{0,1,0,0},
		{0,1,1,1},
		{0,0,0,0},
	};

	// L shaped Tetrimino
	int LTetrimino[ARRAY_SIZE][ARRAY_SIZE] =
	{
		{0,0,0,0},
		{0,0,1,0},
		{1,1,1,0},
		{0,0,0,0},
	};

	// O shaped tetrimino
	int OTetrimino[ARRAY_SIZE][ARRAY_SIZE] =
	{
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0},
	};

	// S shaped tetrimino
	int STetrimino[ARRAY_SIZE][ARRAY_SIZE] =
	{
		{0,0,0,0},
		{0,0,1,1},
		{0,1,1,0},
		{0,0,0,0},
	};

	//T shaped Tetrimino
	int TTetrimino[ARRAY_SIZE][ARRAY_SIZE] =
	{
		{0,0,0,0},
		{0,0,1,0},
		{0,1,1,1},
		{0,0,0,0},
	};

	// Z shaped tetrimino
	int ZTetrimino [ARRAY_SIZE][ARRAY_SIZE] =
	{
		{0,0,0,0},
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0},
	};
	//____________END OF ARRAY CREATION__________________________
	
	// Print and rotate the I shaped tetrimino Left and right
		//Print original
		cout << "The I shaped Tetrimino is:" << endl;	
		PrintTetrimino(ITetrimino,ARRAY_SIZE);

		// Rotate tetrimino to the right
		cout << "The I shaped Tetrimino rotated 90 degrees to the right is:" << endl;
		RotateTetrminoRight(ITetrimino,ARRAY_SIZE);
		PrintTetrimino(ITetrimino,ARRAY_SIZE);

		// Rotate tetrimino to the left
		cout << "The I shaped Tetrimino rotated 90 degrees to the left is:" << endl;
		RotateTetrminoLeft(ITetrimino, ARRAY_SIZE);
		RotateTetrminoLeft(ITetrimino, ARRAY_SIZE);
		PrintTetrimino(ITetrimino,ARRAY_SIZE);

		cout << "_____________________________________________________________________" << 
			endl << endl;
	//Print and rotate the J shaped tetrimino left and right
		//print original
		cout << "The J shaped Tetrimino is:" << endl;
		PrintTetrimino(JTetrimino,ARRAY_SIZE);

		//rotate tetrimino to the right
		cout << "The J shaped Tetrimino rotated 90 degrees to the right is:" << endl;
		RotateTetrminoRight(JTetrimino, ARRAY_SIZE);
		PrintTetrimino(JTetrimino,ARRAY_SIZE);

		//Rotate tetrimino to the left
		cout << "The I shaped Tetrimino rotated 90 degrees to the left is:" << endl;
		RotateTetrminoLeft(JTetrimino, ARRAY_SIZE);
		RotateTetrminoLeft(JTetrimino, ARRAY_SIZE);
		PrintTetrimino(JTetrimino,ARRAY_SIZE);

		cout << "_____________________________________________________________________" << 
			endl << endl;

	//Print and rotate the L shaped Tetrimino left and right
		//Print original
		cout << "The L shaped Tetrimino is:" << endl;
		PrintTetrimino(LTetrimino, ARRAY_SIZE);
		
		// rotate tetrimino to the right
		cout << "The L shaped Tetrimino rotated 90 degrees to the right is:" << endl;
		RotateTetrminoRight(LTetrimino,ARRAY_SIZE);
		PrintTetrimino(LTetrimino,ARRAY_SIZE);

		// rotate tetrimino to the left
		cout << "The L shaped Tetrimino rotated 90 degrees to the Left is:" << endl;
		RotateTetrminoLeft(LTetrimino,ARRAY_SIZE);
		RotateTetrminoLeft(LTetrimino,ARRAY_SIZE);
		PrintTetrimino(LTetrimino,ARRAY_SIZE);

		cout << "_____________________________________________________________________" << 
			endl << endl;

	//Print and rotate the O Shaped tetrimino left and right
		//print original
		cout << "The O shaped Tetrimino is:" << endl;
		PrintTetrimino(OTetrimino,ARRAY_SIZE);

		// rotate tetrimino to the right
		cout << "The O shaped Tetrimino rotated 90 degrees to the right is:" << endl;
		RotateTetrminoRight(OTetrimino,ARRAY_SIZE);
		PrintTetrimino(OTetrimino,ARRAY_SIZE);

		// rotate tetrimino to the left
		cout << "The O shaped Tetrimino rotated 90 degrees to the left is:" << endl;
		RotateTetrminoLeft(OTetrimino,ARRAY_SIZE);
		RotateTetrminoLeft(OTetrimino,ARRAY_SIZE);
		PrintTetrimino(OTetrimino,ARRAY_SIZE);

		cout << "_____________________________________________________________________" << 
			endl << endl;

	//Print and rotate the S shaped tetrimino left and right
		//print original
		cout << "The S shaped Tetrimino is:" << endl;
		PrintTetrimino(STetrimino,ARRAY_SIZE);

		// rotate tetrimino to the right
		cout << "The S shaped Tetrimino rotated 90 degrees to the right is:" << endl;
		RotateTetrminoRight(STetrimino,ARRAY_SIZE);
		PrintTetrimino(STetrimino,ARRAY_SIZE);

		// rotate tetrimino to the left
		cout << "The S shaped Tetrimino rotated 90 degrees to the left is:" << endl;
		RotateTetrminoLeft(STetrimino,ARRAY_SIZE);
		RotateTetrminoLeft(STetrimino,ARRAY_SIZE);
		PrintTetrimino(STetrimino,ARRAY_SIZE);

		cout << "_____________________________________________________________________" << 
			endl << endl;

	//Print and rotate the T shaped tetrimino left and right
		//print original
		cout << "The T shaped Tetrimino is:" << endl;
		PrintTetrimino(TTetrimino,ARRAY_SIZE);

		//rotate tetrimino to the right
		cout << "The T shaped Tetrimino rotated 90 degrees to the right is:" << endl;
		RotateTetrminoRight(TTetrimino,ARRAY_SIZE);
		PrintTetrimino(TTetrimino,ARRAY_SIZE);

		//rotate tetrimino to the right
		cout << "The T shaped Tetrimino rotated 90 degrees to the left is:" << endl;
		RotateTetrminoLeft(TTetrimino,ARRAY_SIZE);
		RotateTetrminoLeft(TTetrimino,ARRAY_SIZE);
		PrintTetrimino(TTetrimino,ARRAY_SIZE);

		cout << "_____________________________________________________________________" << 
			endl << endl;

	//Print and rotate the Z tetrimino left and right
		//print original
		cout << "The Z shaped Tetrimino is:" << endl;
		PrintTetrimino(ZTetrimino,ARRAY_SIZE);

		// rotate tetrimino to the right
		cout << "The Z shaped Tetrimino rotated 90 degrees to the right is:" << endl;
		RotateTetrminoRight(ZTetrimino,ARRAY_SIZE);
		PrintTetrimino(ZTetrimino,ARRAY_SIZE);

		// rotate tetrimino to the left
		cout << "The Z shaped Tetrimino rotated 90 degrees to the left is:" << endl;
		RotateTetrminoLeft(ZTetrimino,ARRAY_SIZE);
		RotateTetrminoLeft(ZTetrimino,ARRAY_SIZE);
		PrintTetrimino(ZTetrimino,ARRAY_SIZE);

	cin.get();
	cin.ignore();
}


/*==============================================================================
Function Name: RotateTetrminoLeft
Description: This will rotate the tetrimino left when the Tetrmino is sent in.
Arguements:
	-	Tetrimino[][ARRAY_SIZE] (int)
	-	ArraySize (int)	
==================================================================================*/
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

	//initalize the temp to orinigal to it can be passed by reference
	for(int row = 0; row < ArraySize; row++)
	{
		for (int column = 0; column < ArraySize; column++)
		{
			TetriminoArray[row][column] = TempArray[row][column];
		}
	}

}


/*==============================================================================
Function Name: RotateTetrminoRight
Description: This will rotate the tetrimino Right when the Tetrmino is sent in.
Arguements:
	-	Tetrimino[][ARRAY_SIZE] (int)
	-	ArraySize (int)
==============================================================================*/
void RotateTetrminoRight(int TetriminoArray[][ARRAY_SIZE], int ArraySize)
{
	//variables
	int TempArray[ARRAY_SIZE][ARRAY_SIZE];

	//loop through the individual spots of an array and rotate it
	for(int row = 0; row < ArraySize; row++)
	{
		for(int column = 0; column < ArraySize; column++)
		{
			TempArray[row][column] = TetriminoArray[ArraySize - 1 - column][row];
		}
	}

	//initalize the temp to orinigal to it can be passed by reference
	for(int row = 0; row < ArraySize; row++)
	{
		for(int column = 0; column < ArraySize; column++)
		{
			TetriminoArray[row][column] = TempArray [row][column];
		}
	}
	
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




