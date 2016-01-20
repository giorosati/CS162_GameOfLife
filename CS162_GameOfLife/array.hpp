/*********************************************************************
** Program Filename: array.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-01-13
** Description: Header file for array.cpp
*********************************************************************/

#ifndef ARRAY_HPP
#define ARRAY_HPP

//function prototypes

void displayEntireArray(int(*array)[80]);

void displayVisibleArray(int (*array)[80]);

void runGame(int (*array)[80], int (*arrayTemp)[80]);

void swapArray(int(*array)[80], int(*arrayTemp)[80]);

#endif
