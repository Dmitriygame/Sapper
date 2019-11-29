/*
	Name: Sapper
	Copyright: Dmitry Omelchenko
	Author: Dmitry Omelchenko
	Date: 29.11.19 21:42 (end)
	Description: it's a game
*/
#define rows 9
#define columns 9
#define bombs 15

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <unistd.h>
#include <ctime>
using namespace std;
///////////////////////////////////////
char main_field [rows][columns];
int  auxiliary_field [rows][columns];
bool END = false;
bool victory = false, lose = false;
bool verify;
int  x_bomb, y_bomb, x, y, open_OR_flag;
char YoN;
int  numberOfClosedCells, numbersOfFlags;
//////////////////////////////////////
void welcome(), 							//basic
	congratulations(),
	newGame(),
	output_main_field(),
	open();
void ranking_numbers(int num1,int num2), 	//subordinate
	pranyk(),
	Input_Error();
///////////////////////////////////////
int main() {
	system( "color 89" );
	srand(time(0));
	cout << "Welcome to game 'Sapper'!\n";
	cout << "This game is very popular, because I won't describe the rules.\n\n\n";
	pranyk();
	while (END == false) {
		newGame();
		while (victory == false && lose == false) {
			system( "cls" );
			output_main_field();
			cout << "Enter the row and column number:\n";
			cin >> x >> y;
			if (x<1 || x>rows || y<1 || y>columns) {
				Input_Error();
			}
			else {
				cout << "Choose open cell or put a flag(1/2)\n";
				cin >> open_OR_flag;
				--x; --y;
				switch(open_OR_flag) {
					case 1:
					{	
						open();
						break;
					}
					case 2:
					{
						main_field[x][y] = char(16);
						break;
					}
					default:
					{
						Input_Error();
						break;
					}
				}
			}
			numberOfClosedCells = 0;
			for (int i = 0; i < rows; i++) {
				for(int j = 0; j < columns; j++) {
					if (main_field[i][j] == char(219)  ||  main_field[i][j] == char(16))
						++numberOfClosedCells;
				}
			}
			if (numberOfClosedCells == bombs) {
				victory = true;
				for (int i = 0; i < rows; i++) {
					for(int j = 0; j < columns; j++) {
						if (main_field[i][j] == char(219)  ||  main_field[i][j] == char(16))
							main_field[i][j] = char(16);
					}
				}
			}
		}
		if (lose == true) {
			system("cls");
			output_main_field();
			cout << "\n\n";
			pranyk();
			system("cls");
			cout << "Hahahaha!\nYou are LOSER!\n\n\n";
			cout << "To play again? (y/n):";
			cin >> YoN;
			if (YoN == 'n')
				END = true;
		}
		else {
			system("cls");
			output_main_field();
			cout << "\n\n";
			pranyk();
			system("cls");
			cout << "Congratulations!\nYou won!\n\n\n";
			cout << "To play again? (y/n):";
			cin >> YoN;
			if (YoN == 'n')
				END = true;
		}		
	}
	return 0;
}
///////////////////////////////////////
void pranyk() {
	cout << "Press any key to continue";
	getch();	
};
void ranking_numbers(int num1, int num2) {
		if (auxiliary_field[num1][num2] != 9)
			auxiliary_field[num1][num2] = auxiliary_field[num1][num2] + 1;
}
void Input_Error() {
	system("cls");
	cout << "Input Error!\n";
	sleep(2);
}

void newGame() {
	system("cls");
	//create empty main field
	for (int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			main_field[i][j] = char(219);
		}
	}
	//create empty auxiliary field
	for (int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			auxiliary_field[i][j] = 0;
		}
	}
	//create bombs
	for (int i = 0; i < bombs; i++) {
		verify = false;
		while(verify == false) {
			x_bomb = rand() % rows;
			y_bomb = rand() % columns;
			if (auxiliary_field[x_bomb][y_bomb] != 9) {
				auxiliary_field[x_bomb][y_bomb] = 9;
				//in the corners
				if (x_bomb == 0 && y_bomb == 0) {
					ranking_numbers(1,0);
					ranking_numbers(0,1);
					ranking_numbers(1,1);
				}
				else if (x_bomb == 0 && y_bomb == columns-1) {
					ranking_numbers(0,columns-2);
					ranking_numbers(1,columns-1);
					ranking_numbers(1,columns-2);
				}
				else if (x_bomb == rows-1 && y_bomb == 0) {
					ranking_numbers(rows-2,0);
					ranking_numbers(rows-2,1);
					ranking_numbers(rows-1,1);
				}
				else if (x_bomb == rows-1 && y_bomb == columns-1) {
					ranking_numbers(rows-2,columns-1);
					ranking_numbers(rows-2,columns-2);
					ranking_numbers(rows-1,columns-2);
				}
				//along the edges
					//left side
				else if (x_bomb > 0 && x_bomb < rows-1 && y_bomb == 0) {
					ranking_numbers(x_bomb-1,y_bomb);
					ranking_numbers(x_bomb-1,y_bomb+1);
					ranking_numbers(x_bomb,y_bomb+1);
					ranking_numbers(x_bomb+1,y_bomb);
					ranking_numbers(x_bomb+1,y_bomb+1);
				}
					//right side
				else if (x_bomb > 0 && x_bomb < rows-1 && y_bomb == columns-1) {
					ranking_numbers(x_bomb-1,y_bomb);
					ranking_numbers(x_bomb-1,y_bomb-1);
					ranking_numbers(x_bomb,y_bomb-1);
					ranking_numbers(x_bomb+1,y_bomb);
					ranking_numbers(x_bomb+1,y_bomb-1);
				}
					//up side
				else if (y_bomb > 0 && y_bomb < columns-1 && x_bomb == 0) {
					ranking_numbers(x_bomb,y_bomb+1);
					ranking_numbers(x_bomb,y_bomb-1);
					ranking_numbers(x_bomb+1,y_bomb-1);
					ranking_numbers(x_bomb+1,y_bomb);
					ranking_numbers(x_bomb+1,y_bomb+1);
				}
					//down side
				else if (y_bomb > 0 && y_bomb < columns-1 && x_bomb == rows-1) {
					ranking_numbers(x_bomb,y_bomb+1);
					ranking_numbers(x_bomb,y_bomb-1);
					ranking_numbers(x_bomb-1,y_bomb-1);
					ranking_numbers(x_bomb-1,y_bomb);
					ranking_numbers(x_bomb-1,y_bomb+1);
				}
				else {
					ranking_numbers(x_bomb+1,y_bomb);
					ranking_numbers(x_bomb+1,y_bomb+1);
					ranking_numbers(x_bomb+1,y_bomb-1);
					ranking_numbers(x_bomb-1,y_bomb);
					ranking_numbers(x_bomb-1,y_bomb+1);
					ranking_numbers(x_bomb-1,y_bomb-1);
					ranking_numbers(x_bomb,y_bomb+1);
					ranking_numbers(x_bomb,y_bomb-1);
				}
				verify = true;
			}
		}
	}
	victory = false;
	lose = false;
}

void output_main_field() {
	numbersOfFlags = 0;
	for (int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if (main_field[i][j] == char(16))
				++numbersOfFlags;
		}
	}
	numbersOfFlags = bombs - numbersOfFlags;
	cout << "   ";
	for (int i = 0; i < columns; i++) {
		cout << i+1 << ' ';
	}
	cout << "   Flags: " << numbersOfFlags;
	cout << endl << endl;
	
	for (int i = 0; i < rows; i++) {
		cout << i+1 << ' ';
		for(int j = 0; j < columns; j++) {
			cout << ' ' << main_field[i][j];
		}
		cout << ' ' << i+1;
	cout << endl << endl;
	}
	cout << "   ";
	for (int i = 0; i < columns; i++) {
		cout << i+1 << ' ';
	}
	cout << endl << endl;
}

void open() {
	if (auxiliary_field[x][y] > 0 && auxiliary_field[x][y] < 9) {
		main_field[x][y] = (char)(auxiliary_field[x][y]+48);
	}
	else if (auxiliary_field[x][y] == 0) {
		main_field[x][y] = char(0);
		
		//in the corners
				if (x == 0 && y == 0) {
					x=1; y=0; open();
					x=0; y=1; open();
					x=1; y=1; open();
				}
				else if (x == 0 && y == columns-1) {
					x=0;y=columns-2; open();
					x=1;y=columns-1; open();
					x=1;y=columns-2; open();
				}
				else if (x == rows-1 && y == 0) {
					x=rows-2; y=0; open();
					x=rows-2; y=1; open();
					x=rows-1; y=1; open();
				}
				else if (x == rows-1 && y == columns-1) {
					x=rows-2; y=columns-1; open();
					x=rows-2; y=columns-2; open();
					x=rows-1; y=columns-2; open();
				}
	}
	else {
		main_field[x][y] = char(15);
		lose = true;
	}
}
