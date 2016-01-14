/*********************************************************************
** Program Filename: Main.cpp
** Author: Giovanni Rosati
** Date: 2016-01-13
** Description: Main function for CS162_400 Project 1
** Input:
** Output:
*********************************************************************/
#include <iostream>
#include <thread>
#include <chrono>
#include "array.hpp"

using std::cout;
using std::cin;
using std::endl;
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

	//user input of  x cycles
	double cycles = 0;
	int speed = 300;
	cout << "Please enter the number of cycles to run: " << endl;
	cin >> cycles;
	int startValue = cycles;

	//user input of starting location
	//check to see that it is within the visible bounds
	int row = 0;
	int col = 0;

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

	//populate cells with the oscillator
	// this needs to force them enough inside to show the entire starting pattern

	for (int i = row; i < row + 1; i++)		//loop through one line
	{
		for (int j = col; j < col + 3; j++)	//loop through four columns
		{
			array[i + 19][j + 19] = 1;
		}
	}

	//iterare the game
	while (cycles != 0, cycles--)
	{
		if (startValue = cycles)
		{
			system("CLS");
			displayVisibleArray(array);
		}

		runGame(array, arrayTemp);

		//display arrayTemp
		displayVisibleArray(arrayTemp);

		//tranpose arrayTemp to array
		swapArray(array, arrayTemp);

		std::this_thread::sleep_for(std::chrono::milliseconds(speed));
		system("CLS");

		//system("pause");

		//cout << "This is the processed arrayTemp" << endl;
		//system("pause");
	}

	return 0;
}