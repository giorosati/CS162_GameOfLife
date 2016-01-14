/*********************************************************************
** Program Filename: array.hpp
** Author: Giovanni Rosati
** Date: 2016-01-13
** Description: Header file for the array class
** Input: na
** Output: na
*********************************************************************/

#ifndef ARRAY_HPP
#define ARRAY_HPP

//function prototypes

void displayEntireArray(int(*array)[80]);

void displayVisibleArray(int (*array)[80]);

void runGame(int (*array)[80], int (*arrayTemp)[80]);

void swapArray(int(*array)[80], int(*arrayTemp)[80]);

#endif
