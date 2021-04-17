/*Tic Tac Toe Written in C++ */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <vector>

using namespace std;

char board[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void draw_board();
void who_first();
void random_int();
void get_ran_move();
void random_board();
void get_p_move();
void check_if_win();

int i;
int new_r;
int move_r;
int first;
int space;
int round_check;

int main(){
	srand(time(0));
	cout << "Tic Tac Toe" << endl;
	who_first();
	if(first == 1)
		round_check = 1;
	else if(first == 0)
		round_check = 0;

	//Main loop
	do {
		switch(round_check){
			case 1:
				cout << "Select space: ";
				cin >> space;
				get_p_move();
				round_check = 0;
			case 0:
				get_ran_move();
				round_check = 1;
		}

		/* if(first == 1){
			cout << "Select space: ";
			cin >> space;
			get_p_move();
		} else if(first == 0)
			get_ran_move();*/
		check_if_win();
		draw_board();
	} while (i == -1);
	draw_board();
	switch(i){
		case 0:
			cout << "There is no winner";
		case 1:
//You have to somewhat make this work and stop crashing it self up
//You have to fix winner detection and crashes probably made by checking for game status
//Fix starting player
			cout << "no u";
	}
/*	if(i == 0){
		cout << "There is no winner" << endl;
	}else if(i == 1 || i == 2){
		if(first == 1 && i == 1){
			cout << "Player";
		}else if(first == 0 && i == 2){
			cout << "Bot";
		}
		cout << " is the winner" << endl;
//		if(first == 1 && i == 1)
	} */
}

//Used to get bot move
void get_ran_move(){
	random_board();
	if(board[move_r] == 'X' || board[move_r] == 'O'){
//		get_ran_move();
		random_board();
	}else if(board[move_r] != 'X' || board[move_r] != 'O'){
		if(first == 1)
			board[move_r] = 'X';
		else if(first == 0)
			board[move_r] = 'O';
	}
}

//Used to get player move
void get_p_move(){
	if(board[space] == 'X' || board[space] == 'O'){
		cout << "Please select again: ";
		cin >> space;
		get_p_move();
	}else if(board[space] != 'X' || board[space] != 'O'){
		if(first == 1)
			board[space] = 'O';
		else if(first == 0)
			board[space] = 'X';
	}

}

//Selects who goes first
void who_first(){
	random_int();
	if(new_r == 50 || new_r == 100 || new_r == 150){
		cout << "Player starts as O" << endl;
		first = 1;
	} else if(new_r != 50 || new_r != 100 || new_r != 150){
		cout << "Bot starts as O" << endl;
		first = 0;
	}
}

//Generates random number in range for selecting where to place X/O by bot
void random_board(){
//	srand(time(0));
	move_r = (rand() % 9);
}

//Generates random number in range for who_first()
void random_int(){
//	srand(time(0));
	new_r = (rand() % 150 + 1);
}

//Checks for winner

// return 1 (Win & Ended)
// return -1 (In progress)
// return 0 (No win & Ended)

void check_if_win(){
	//→
	if(board[1] == board[2] && board[2] == board[3]){
		i = 1;
	}else if(board[4] == board[5] && board[5] == board[6]){
		i = 1;
	}else if(board[7] == board[8] && board[8] == board[9]){
		i = 1;
	//↓
	}else if(board[1] == board[4] && board[4] == board[7]){
		i = 1;
	}else if(board[2] == board[5] && board[5] == board[8]){
		i = 1;
	}else if(board[3] == board[6] && board[6] == board[9]){
		i = 1;
	//↓→
	}else if(board[1] == board[5] && board[5] == board[9]){
		i = 1;
	//←↓
	}else if(board[3] == board[5] && board[5] == board[7]){
		i = 1;
	}else if(board[1] != '1' && board[2] != '2' && board[3] != '3' && board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && board[8] != '8' && board[9] != '9'){
		i = 0;
	}else
		i = -1;
/*
	//→
	if(board[1] == board[2] == board[3]){
		i = 1;
	}else if(board[4] == board[5] == board[6]){
		i = 1;
	}else if(board[7] == board[8] == board[9]){
		i = 1;
	//↓
	}else if(board[1] == board[4] == board[7]){
		i = 1;
	}else if(board[2] == board[5] == board[8]){
		i = 1;
	}else if(board[3] == board[6] == board[9]){
		i = 1;
	//↓→
	}else if(board[1] == board[5] == board[9]){
		i = 1;
	//←↓
	}else if(board[3] == board[5] == board[7]){
		i = 1;
	}else if(board[1] != '1' && board[2] != '2' && board[3] != '3' && board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && board[8] != '8' && board[9] != '9'){
		i = 0;
	}else
		i = -1;
*/
}


//Displaying board
void draw_board(){
/*	#ifdef _WIN32
	system("cls");
	#endif
	#ifdef __linux__
	system("clear");
	#endif
*/	cout << "   |   |   " << endl;
	cout << " " << board[1] << " | " << board[2] << " | " << board[3] << endl;
	cout << "___|___|___" << endl;
	cout << "   |   |   " << endl;
	cout << " " << board[4] << " | " << board[5] << " | " << board[6] << endl;
	cout << "___|___|___" << endl;
	cout << "   |   |   " << endl;
	cout << " " << board[7] << " | " << board[8] << " | " << board[9] << endl;
	cout << "   |   |   " << endl;
}
