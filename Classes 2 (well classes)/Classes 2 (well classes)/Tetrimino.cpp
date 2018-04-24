/*=======================================================
name: Edward
date: 2/3/2015
purpose: assign each of the tetrimino a certain color
and a location on the grid
=======================================================*/
#include<iostream>
#include<ctime>
#include "Tetrimino.h"

using namespace std;

/*===========================================
class name: Tetrimino
arguements: 
	(int)	- type
purpose: Create a class and initialize the
color to the color and tetrimino block
==============================================*/
Tetrimino::Tetrimino (int type)
{
	//Temperary variables
	for(int row = 0; row < TETRIMINO_GRID_SIZE; row++)
	{
		for (int column = 0; column < TETRIMINO_GRID_SIZE; column++)
		{
			grid[row][column]= 0;
		}
	}
	if (type < 0 || type > 6)
	{	
		int high = 6; // valid max Tetrimino type
		int low = 0; // valid min Tetrimino type
		srand( static_cast<unsigned int>(time(NULL)) ); // seed the random number generator
		type = rand() % (high-low+1) + low; // generate a random num between low and high
	}

	//check and see the type of tetrimino
	switch(type)
	{
	case 0:
		//
		grid [1][0] = 1;
		grid [1][1] = 1;
		grid [1][2] = 1;
		grid [1][3] = 1;
		color = 'r';
		break;
	case 1:
		grid [1][1] = 1;
		grid [2][1] = 1;
		grid [2][2] = 1;
		grid [2][3] = 1;
		color = 'y';
		break;
	case 2: 
		grid [1][2] = 1;
		grid [2][0] = 1;
		grid [2][1] = 1;
		grid [2][2] = 1;
		color = 't';
		break;
	case 3:
		grid [1][1] = 1;
		grid [1][2] = 1;
		grid [2][1] = 1;
		grid [2][2] = 1;
		color = 'b';
		break;
	case 4:
		grid [1][2] = 1;
		grid [1][3] = 1;
		grid [2][1] = 1;
		grid [2][2] = 1;
		color = 'o';
		break;
	case 5:
		grid [1][2] = 1;
		grid [2][1] = 1;
		grid [2][2] = 1;
		grid [2][3] = 1;
		color = 'g';
		break;
	case 6:
		grid [1][0] = 1;
		grid [1][1] = 1;
		grid [2][1] = 1;
		grid [2][2] = 1;
		color = 'p';
		break;

	default:
		break;
	}

	//set location
	location.col = 0;
	location.row = 0;
};


/*====================================================
function name: getColor	(char)
arguements: none
return: color
purpose: returns the color of the current tetrimino
=====================================================*/
char Tetrimino::getColor()
{
	return color;
}


/*=======================================================
function name: getLocation	(struct)
arguements: none
return: location
purpose: returns the location of the current tetrimino
========================================================*/
Location Tetrimino::getLocation()
{
	return location;
}


/*============================================
function name: getGrid	(void)
arguements: gridOut	- (2D array)
return: -	void
prupose: initializes the gridOut to grid
=============================================*/
void Tetrimino::getGrid(int gridOut[][TETRIMINO_GRID_SIZE])
{
	//loop
	for(int row = 0; row < TETRIMINO_GRID_SIZE; row++)
	{
		for (int column = 0; column < TETRIMINO_GRID_SIZE; column++)
		{
			gridOut[row][column] = grid[row][column];
		}
	}

}


/*=====================================================
function name: setLocation
arguements: newLocation	(struct)
return:	void
purpose: sets the current location to a new location
======================================================*/
void Tetrimino::setLocation(Location newLocation)
{
	location.col = newLocation.col;
	location.row = newLocation.row;
}


/*======================================================
function name: setLocation
arguements: row	(int)
			col	(int)
return:	void
purpose: set the current location and assigns it with
row and column
======================================================*/
void Tetrimino::setLocation(int row, int col)
{
	location.col = col;
	location.row = row;
}


/*==============================================================================
Function Name: RotateTetrminoLeft
Description: This will rotate the tetrimino left when the Tetrmino is sent in.
Arguements:
	-	Tetrimino[][ARRAY_SIZE] (int)
	-	ArraySize (int)	
==================================================================================*/
void Tetrimino::rotateLeft()
{
	//varibales
	int TempArray[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];

	//Loop through the individual spots of an array and rotate it
	for(int row = 0; row < TETRIMINO_GRID_SIZE; row++)
	{
		for (int column = 0; column < TETRIMINO_GRID_SIZE; column++)
		{
			TempArray[row][column] = grid[column][3-row];
		}
	}

	//initalize the temp to orinigal to it can be passed by reference
	for(int row = 0; row < TETRIMINO_GRID_SIZE; row++)
	{
		for(int column = 0; column < TETRIMINO_GRID_SIZE; column++)
		{
			grid[row][column] = TempArray[row][column];
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
void Tetrimino::rotateRight()
{
	//variables
	int TempArray[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];

	//loop through the individual spots of an array and rotate it
	for(int row = 0; row < TETRIMINO_GRID_SIZE; row++)
	{
		for(int column = 0; column < TETRIMINO_GRID_SIZE; column++)
		{
			TempArray[row][column] = grid[TETRIMINO_GRID_SIZE - 1 - column][row];
		}
	}

	//initalize the temp to orinigal to it can be passed by reference
	for(int row = 0; row < TETRIMINO_GRID_SIZE; row++)
	{
		for(int column = 0; column < TETRIMINO_GRID_SIZE; column++)
		{
			grid[row][column] = TempArray [row][column];
		}
	}
	
}


/*============================================
function name: moveLeft
arguements: none
return:	void
purpose: moving your entire tetrmimno left
============================================*/
void Tetrimino::moveLeft()
{
	location.col = location.col - 1;
}


/*============================================
function name: moveRight
arguements: none
return:	void
purpose: moving your entire tetrmimno right
============================================*/
void Tetrimino::moveRight()
{
	location.col = location.col + 1;
}


/*============================================
function name: moveDown
arguements: none
return:	void
purpose: moving your entire tetrmimno down
============================================*/
void Tetrimino::moveDown()
{
	location.row = location.row + 1;
}


/*============================================
function name: moveUp
arguements: none
return:	void
purpose: moving your entire tetrmimno Up
============================================*/
void Tetrimino::moveUp()
{
	location.row = location.row - 1;
}


/*================================================
function name: dataDump
arguements: none
return:	void
purpose: will display the tetrimino along with the
		color and location
=================================================*/
void Tetrimino::dataDump()
{
	//loop through and display 
	for(int row = 0; row < TETRIMINO_GRID_SIZE; row++)
	{
		for(int column = 0; column < TETRIMINO_GRID_SIZE; column++)
		{
			cout << grid[row][column] << " ";
		}
	cout << endl;
	}

	//display color
	cout << "The color is: " << color << endl;

	//display location
	cout << "The location is: (" << location.col << "," <<
		location.row << ")" << endl;
}

/*
void main()
{
	//variables
	Tetrimino piece;

	piece.dataDump();

	cout << endl;

	piece.moveDown();
	cout << endl;

	piece.dataDump();
	cout << endl;

	piece.rotateLeft();
	cout << endl;

	piece.dataDump();
	cout << endl;

	piece.rotateRight();
	cout << endl << "rotate right" << endl;

	piece.dataDump();
	cout << endl;

	piece.moveUp();
	cout << endl;

	piece.dataDump();
	cout << endl;

	piece.moveLeft();
	cout << endl;
	
	piece.dataDump();
	cout << endl;

	cin.get();
	cin.ignore();
}


*/