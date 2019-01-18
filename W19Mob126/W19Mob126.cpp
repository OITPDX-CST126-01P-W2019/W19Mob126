// W19Mob126.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//  We are playing the mob programming game from Willem Larsen:
//		https://github.com/willemlarsen/mobprogrammingrpg
//  We are playing tic-tac-toe or noughts and crosses  https://en.wikipedia.org/wiki/Tic-tac-toe

#include "pch.h"
#include <iostream>
using namespace std;


const char EX { 'X' };
const char OH { 'O' };

const int BOARD_SIZE = 3;

void start_game(char GameBoard[][BOARD_SIZE]);
void print_game(const char GameBoard[][BOARD_SIZE]);
void play_move(char GameBoard[][BOARD_SIZE], char player);
void play_round(char GameBoard[][BOARD_SIZE]);
bool check_winner(const char  GameBoard[][BOARD_SIZE]);
bool check_draw(const char  GameBoard[][BOARD_SIZE]);
void get_row_col(int move, int & row, int & col);
bool ok_move(const char GameBoard[][BOARD_SIZE], int move);

int main()
{
	char GameBoard[3][3];

	start_game(GameBoard);
	
	while (!check_winner(GameBoard) && !check_draw(GameBoard))
	{
		play_round(GameBoard);
	}

	if (check_winner(GameBoard))
		cout << "We've got a winner" << endl;
	else if (check_draw(GameBoard))
		cout << "It's A Draw!" << endl;

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
			cout << endl << "---+---+---" << endl;
		else
			cout << endl;
	}
}

void start_game(char GameBoard[][BOARD_SIZE])
{
	char position = '1';
	for (int r = 0; r < BOARD_SIZE; r++) 
		for (int c = 0; c < BOARD_SIZE; c++)
			GameBoard[r][c] = position++ ;
	
}

bool check_winner(const char  GameBoard[][BOARD_SIZE])
{
	//bool win = false;

	int count {0};
	bool same = true;

	// look for row win
	for (int r = 0; r < BOARD_SIZE ; r++) {
		if (GameBoard[r][0] == GameBoard[r][1] &&
			GameBoard[r][0] == GameBoard[r][2])
			return true;

	}
	// look for column win
	count = 0;
	for (int c = 0; c < BOARD_SIZE; c++)
	{
		if (GameBoard[0][c] == GameBoard[1][c] &&
			GameBoard[0][c] == GameBoard[2][c])
			return true;
	}
	return false;
}
bool check_draw(const char  GameBoard[][BOARD_SIZE])
{
	int count = 0;
	for (int r = 0; r < BOARD_SIZE; r++)
		for (int c = 0; c < BOARD_SIZE; c++)
			if (GameBoard[r][c] == EX || GameBoard[r][c] == OH)
				count++;

	if (count < (BOARD_SIZE * BOARD_SIZE))
		return false;
	else
		return true;
}

void get_row_col(int move, int & row, int & col)
{
// code that I used to test the board square to row column conversion  
//int c = 0, r = 0;
//for (int m = 1; m < 10; m++) {
//	r = (m - 1) / BOARD_SIZE;
//	c = m - r * BOARD_SIZE - 1;
//	cout << "(" << r << "," << c << ")   ";
//}
//cout << endl;
	 row = (move - 1) / BOARD_SIZE;
	 col = move - row * BOARD_SIZE - 1;
}

bool ok_move(const char GameBoard[][BOARD_SIZE],int move)
{
	if(move < 1 || move > 9)
	{
		cout << "Pick a space between 1 & 9" << endl;
		return false;
	}

	int row{ 0 }, col{ 0 };
	get_row_col(move, row, col);
	// cout << row << "," << col << endl;
	
	// cout << row << " , " << col << endl;
	if (GameBoard[row][col] == EX || GameBoard[row][col] == OH) {
		cout << "Pick a blank spot please." << endl;
		return false;
	}

	return true;

}
void play_move(char GameBoard[][BOARD_SIZE],char player)
{
	int move{ 0 };
	int row{ 0 }, col{ 0 };

	cout << endl;
	print_game(GameBoard);

	do {
		cout << "Player " << player <<  ", which square do you want (1/9)" << endl;
		cin >> move;
	} while (!ok_move(GameBoard, move));

	get_row_col(move, row, col);
	GameBoard[row][col] = player;
}
void play_round(char GameBoard[][BOARD_SIZE])
{
	play_move(GameBoard, EX);
	if (!check_winner(GameBoard) && !check_draw(GameBoard))
		play_move(GameBoard, OH);
}


