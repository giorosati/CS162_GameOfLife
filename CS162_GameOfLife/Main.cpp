/*********************************************************************
** Program Filename: Main.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-01-13
** Description: Main function for CS162_400 Project 1
** Input:
** Output:
*********************************************************************/
#include <iostream>

//used in windows
//#include <thread>
//#include <chrono>

//used on FLIP
#include <unistd.h>
#include <stdlib.h>

#include "array.hpp"

using std::cout;
using std::cin;
using std::endl;
//using std::system("clear");

//using std::this_thread::sleep_for;

int main()
{
	//create a starting array
	int array[60][80];

	//fill the array with live cells
	for (int i = 0; i < 60; i++)		//loop through each line
	{
		for (int j = 0; j < 80; j++)	//loop through each column
		{
			array[i][j] = 1;
		}
	}

	//for testing - initialize the array with an oscillating pattern
	//first fill the array with dead cells
	//them populate just the cells that are live

	//kill all cells
	for (int i = 0; i < 60; i++)		//loop through each line
	{
		for (int j = 0; j < 80; j++)	//loop through each column
		{
			array[i][j] = 0;
		}
	}

	//display entire array
	//displayEntireArray(array);

	//display visible array
	//cout << "Starting array:" << endl;
	//cout << endl;
	//displayVisibleArray(array);

	//system("pause");

	//create a temp array and populate with dead cells
	int arrayTemp[60][80];
	for (int i = 0; i < 60; i++)		//loop through each line
	{
		for (int j = 0; j < 80; j++)	//loop through each column
		{
			arrayTemp[i][j] = 0;
		}
	}

	//display arrayTemp
	//displayEntireArray(arrayTemp);

	//cout << "This is the starting arrayTemp" << endl;
	//system("pause");

	//user entry number of cycles to run
	double cycles = 0;
	int speed = 500;
	cout << "Please enter the number of cycles to run: " << endl;
	cin >> cycles;
	double startValue = cycles;

	//user input of starting location
	//check to see that it is within the visible bounds
	int row = 0;  //row is the user chosen row of the visible matrix
	int col = 0;  //col is the user chosen column of the visible matrix

	cout << "You will now choose the starting position of the object." << endl;
	cout << "You will choose where the top left of the starting pattern" << endl;
	cout << "will be placed in the grid. First you will choose the row #," << endl;
	cout << "then you will choose the column #. " << endl;
	cout << endl;

	while (row < 1 || row > 20)
	{
		cout << "Please enter the starting row # (1-20): " << endl;
		cin >> row;
	}

	while (col < 1 || col > 40)
	{
		cout << "Please enter the starting column # (1-40): " << endl;
		cin >> col;
	}
	cout << endl;

	//user entry of initial object to populate the grid
	int startObject = 0;
	while (startObject != 1 && startObject != 2 && startObject !=3)
	{
		cout << "You will now choose an initial object to populate the grid." << endl;
		cout << endl;
		cout << "Please enter:" << endl;
		cout << "1 for a simple two line oscillator" << endl;
		cout << "2 for a figure 8 oscillator" << endl;
		cout << "3 for a glider" << endl;
		cin >> startObject;
		cout << endl;
	}

	//oscillator test one
	//populate cells with a one line four cell wide oscillator
	// this needs to force them enough inside to show the entire starting pattern

	//for (int i = row; i < row + 1; i++)		//loop through one line
	//{
	//	for (int j = col; j < col + 3; j++)	//loop through four columns
	//	{
	//		array[i + 19][j + 19] = 1;
	//	}
	//}

	//two line oscillator
	if (startObject == 1)
	{
		for (int i = row; i < row + 1; i++)		//do once
		{
			for (int j = col; j < col + 3; j++)	//loop through three columns
			{
				array[i + 19][j + 19] = 1;
				array[i + 20][j + 18] = 1;
			}
		}
	}

	//figure eight oscillator
	if (startObject == 2)
	{
		//make two squares
		for (int i = row; i < row + 3; i++)		//three rows
		{
			for (int j = col; j < col + 3; j++)	//loop through three columns
			{
				array[i + 20][j + 20] = 1;
				array[i + 23][j + 23] = 1;
			}
		}
	}

	//glider
	if (startObject == 3)
	{
		array[row + 20][col + 21] = 1; //top row, middle column
		array[row + 21][col + 22] = 1; //middle row, right column
		array[row + 22][col + 20] = 1; //bottom row, left column
		array[row + 22][col + 21] = 1; //bottom row, middle column
		array[row + 22][col + 22] = 1; //bottom row, right column
	}

	//display the initial grid state

//clear screen for windows
//system("CLS");

//clear screen for FLIP
//system("clear");

	displayVisibleArray(array);

	//initial delay for windows
	//system("pause");

	//delay for FLIP
	cout << "Press enter to display the next iteration.";
	cin.get();

	//iterare the game
	while (cycles != 0, cycles--)
	{
		//if (startValue = cycles)  //to display the initial grid state
		//{
		//	//clear screen for windows
		//	//system("CLS");

		//	//clear screen for FLIP
		//	system("clear");

		//	displayVisibleArray(array);

		//	//initial delay for windows
		//	//system("pause");

		//	//initial delay for FLIP
		//	cout << "Press enter to display the next iteration.";
		//	cin.get();
		//}

		runGame(array, arrayTemp);

		//display arrayTemp
		displayVisibleArray(arrayTemp);

		//system("pause");

		//tranpose arrayTemp to array
		swapArray(array, arrayTemp);

		//delay for windows
		// std::this_thread::sleep_for(std::chrono::milliseconds(speed));

		//delay options for FLIP
		//usleep(speed);
		cout << "Press enter to display the next iteration." << endl;
		cin.get();

		//clear screen for windows
		//system("CLS");

		//clear screen for FLIP
		//system("clear");

		//cout << "This is the processed arrayTemp" << endl;
		//system("pause");
	}

	return 0;
}