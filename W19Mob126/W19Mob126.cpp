// W19Mob126.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//  We are playing the mob programming game from Willem Larsen:
//		https://github.com/willemlarsen/mobprogrammingrpg
//  We are playing tic-tac-toe or noughts and crosses  https://en.wikipedia.org/wiki/Tic-tac-toe

#include "pch.h"
#include <iostream>
using namespace std;

const int WIN = 1;
const int LOSE = 2;
const int DRAW = 3;

const char BLANK{ '-' };
const char EX { 'X' };
const char OH { 'O' };

const int BOARD_SIZE = 3;

void start_game(char GameBoard[][BOARD_SIZE]);
void print_game(const char GameBoard[][BOARD_SIZE]);
// void play_round(char GameBoard[][BOARD_SIZE]);
//int get_game_status(const gar  GameBoard[][BOARD_SIZE]);

int main()
{
	char GameBoard[3][3] {'-'};

	start_game(GameBoard);
	print_game(GameBoard);
   
}

void print_game(const char GameBoard[][BOARD_SIZE])
{
	for (int r = 0; r < BOARD_SIZE; r++) {
		cout << " ";
		for (int c = 0; c < BOARD_SIZE; c++) {
			cout << GameBoard[r][c];
			if (c < (BOARD_SIZE -1))
				cout << " | ";
		}
		if (r < (BOARD_SIZE - 1))
			cout << endl << "-----------" << endl;
		else
			cout << endl;
	}
}

void start_game(char GameBoard[][BOARD_SIZE])
{
	for (int r = 0; r < BOARD_SIZE; r++) 
		for (int c = 0; c < BOARD_SIZE; c++)
			GameBoard[r][c] = BLANK;
	
}