/*********************************************************************
** Program Filename: array.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-01-13
** Description: array function definitions
** Input: na
** Output: na
*********************************************************************/

#include <iostream>
#include "array.hpp"

using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
** Function: displayVisibleArray
** Description: Used to display to the screen an "inner" array of
** 20 rows of 40 columns each.
** Parameters: a pointer to a 40 x 80 array of ints
** Pre-Conditions: 
** Post-Conditions:
*********************************************************************/
void displayVisibleArray(int(*array)[80])
{
	for (int i = 19; i < 39; i++)		//loop through each line
	{
		for (int j = 19; j < 59; j++)	//loop through each column
		{
			if (array[i][j] == 1)       //if value is 1 output a *
			{
				cout << "*";
				if (j == 58)
				{
					cout << endl;
				}
			}
			else                       // if value is not 1, output a space
			{
				cout << " ";
				if (j == 58)
				{
					cout << endl;
				}
			}
		}
		if (i == 38)
		{
			cout << endl;
			cout << endl;
		}
	}
}

/*********************************************************************
** Function: displayEntireArray
** Description: Used during testing to display to the screen the 
** entire array of 40 rows of 80 columns each.
** Parameters: a pointer to a 40 x 80 array of ints
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void displayEntireArray(int(*array)[80])
{
	for (int i = 0; i < 60; i++)		//loop through each line
	{
		for (int j = 0; j < 80; j++)	//loop through each column
		{
			cout << array[i][j];        //display content of each position
			if (j == 79)
			{
				cout << endl;
			}
		}
		if (i == 59)
		{
			cout << endl;
			cout << endl;
		}
	}
}

/*********************************************************************
** Function: runGame
** Description: Advances the game one iteration using rules provided.
** Creates the new values at each matrix position in a new temp array. 
** After displaying the new temp array, the temp array is copied to the
** original array. To avoid referencing an array position that is "out of
** bounds this code does not process the perimeter cells of the entire 
** 60 x 80 grid. The user only sees an inner grid of 20 x 40, 
** which allows a buffer of 20 cells on each side.
** Parameters: pointers to two 40 x 80 arrays of ints
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/

void runGame(int(*array)[80], int(*arrayTemp)[80])
{
	for (int i = 1; i < 59; i++)		//loop through each line
	{
		for (int j = 1; j < 79; j++)	//loop through each column

		//count the live cells touching a cell
		{
			int liveCells = 0;
			if (array[i - 1][j - 1] == 1) liveCells = liveCells + 1;
			if (array[i - 1][j] == 1) liveCells = liveCells + 1;
			if (array[i - 1][j + 1] == 1) liveCells = liveCells + 1;
			if (array[i][j - 1] == 1) liveCells = liveCells + 1;
			if (array[i][j + 1] == 1) liveCells = liveCells + 1;
			if (array[i + 1][j - 1] == 1) liveCells = liveCells + 1;
			if (array[i + 1][j] == 1) liveCells = liveCells + 1;
			if (array[i + 1][j + 1] == 1) liveCells = liveCells + 1;

			//for testing
			//cout << "Cell just tested is row-column: " << i << " - " << j << endl;
			//cout << "Content of this cell: " << array[i][j] << endl;
			//cout << "Live cell count for this cell is : " << liveCells << endl;
			//system("pause");

			//modify the cell in the temp array based upon number of live touching cells
			if (liveCells <= 1) arrayTemp[i][j] = 0;
			if (liveCells == 2) arrayTemp[i][j] = array[i][j];
			if (liveCells == 3) arrayTemp[i][j] = 1;
			if (liveCells >= 4) arrayTemp[i][j] = 0;
		}
	}
}

/*********************************************************************
** Function: swapArray
** Description: Replaces the contents of array with the contents of arrayTemp
** All cells are copied.
** Parameters: pointers to two 40 x 80 arrays of ints
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void swapArray(int(*array)[80], int(*arrayTemp)[80])
{
	for (int i = 0; i < 60; i++)		//loop through each line
	{
		for (int j = 0; j < 80; j++)	//loop through each column
		{
			array[i][j] = arrayTemp[i][j];
		}
	}
}