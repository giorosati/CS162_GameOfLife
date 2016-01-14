/*********************************************************************
** Program Filename: array.cpp
** Author: Giovanni Rosati
** Date: 2016-01-13
** Description: array class
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
** Author: Giovanni Rosati
** Date: 2016-01-13
** Parameters: a pointer to an array of 40 columns
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void displayVisibleArray(int(*array)[80])
{
	for (int i = 19; i < 39; i++)		//loop through each line
	{
		for (int j = 19; j < 59; j++)	//loop through each column
		{
			if (array[i][j] == 1)
			{
				cout << "*";
				if (j == 58)
				{
					cout << endl;
				}
			}
			else
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

//for testing
void displayEntireArray(int(*array)[80])
{
	for (int i = 0; i < 60; i++)		//loop through each line
	{
		for (int j = 0; j < 80; j++)	//loop through each column
		{
			cout << array[i][j];
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

//this version does not process perimeter cells to avoid going out of bounds
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

//processes all cells, including the perimeter
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