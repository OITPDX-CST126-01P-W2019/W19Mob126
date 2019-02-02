//  .h for our structure / soon to be class... gameboard 
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
const int BOARD_SIZE = 3;
const char EX{ 'X' };
const char OH{ 'O' };

struct ttt { // ttt - Tic Tac Toe

	char gb[BOARD_SIZE][BOARD_SIZE];  // gb = Game Board

};

void start_game(char GameBoard[][BOARD_SIZE]);
void print_game(const char GameBoard[][BOARD_SIZE]);
void play_move(char GameBoard[][BOARD_SIZE], char player);
void play_round(char GameBoard[][BOARD_SIZE]);
bool check_winner(const char  GameBoard[][BOARD_SIZE]);
bool check_draw(const char  GameBoard[][BOARD_SIZE]);
void get_row_col(int move, int & row, int & col);
bool ok_move(const char GameBoard[][BOARD_SIZE], int move);
#endif