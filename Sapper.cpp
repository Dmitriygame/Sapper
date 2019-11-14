//120
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
using namespace std;
///////////////////////////////////////
char main_field [5][5];
int auxiliary_field [5][5];
bool victory = false;
bool verify;
int x_bomb, y_bomb, x, y, open_OR_flag;
//////////////////////////////////////
void pranyk(), //basic
	welcome(),
	congratulations(),
	newGame(),
	output_main_field(),
	output_auxiliary_field(),
	open_cell()
	;
void ranking_numbers(int num1,int num2) //subordinate
	;
///////////////////////////////////////
int main() {
	system( "color 89" );
	srand(time(0));
	//welcome();
	newGame();
	while (1==1) {
	system( "cls" );
	output_main_field();
	cout << "\n\n";
	output_auxiliary_field();
	open_cell();
}
	return 0;
}
///////////////////////////////////////
void pranyk() {
	cout << "Press any key to continue";
	getch();	
};
void welcome() {
	cout << "Welcome to game 'Sapper'!\n";
	cout << "This game is very popular, because I won't describe the rules.\n\n\n";
	pranyk();
}
void congratulations() {
	system("cls");
	cout << "Congratulations!\nYou won!\n\n\n";
	pranyk();
}

void newGame() {
	system("cls");
	//create empty main field
	for (int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			main_field[i][j] = char(219);
		}
	}
	//create empty auxiliary field
	for (int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			auxiliary_field[i][j] = 0;
		}
	}
	//create bombs
	for (int i = 0; i < 5; i++) {
		verify = false;
		while(verify == false) {
			x_bomb = 1 + rand() % 3;
			y_bomb = 1 + rand() % 3;
			if (auxiliary_field[x_bomb][y_bomb] != 6) {
				auxiliary_field[x_bomb][y_bomb] = 6;
				
				ranking_numbers(x_bomb+1,y_bomb);
				ranking_numbers(x_bomb+1,y_bomb+1);
				ranking_numbers(x_bomb+1,y_bomb-1);
				ranking_numbers(x_bomb-1,y_bomb);
				ranking_numbers(x_bomb-1,y_bomb+1);
				ranking_numbers(x_bomb-1,y_bomb-1);
				ranking_numbers(x_bomb,y_bomb+1);
				ranking_numbers(x_bomb,y_bomb-1);
				verify = true;
			}
		}
	}
}

void output_main_field() {
	cout << "   1 2 3 4 5\n\n";
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ' ';
		for(int j = 0; j < 5; j++) {
			cout << ' ' << main_field[i][j];
		}
	cout << endl << endl;
	}
}

void output_auxiliary_field() {
	cout << "   1 2 3 4 5\n\n";
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ' ';
		for(int j = 0; j < 5; j++) {
			cout << ' ' << auxiliary_field[i][j];
		}
	cout << endl << endl;
	}
}

void open_cell() {
	cout << "Enter the row and column number:\n";
	cin >> x >> y;
	cout << "Choose open cell or put a flag(1/2)\n";
	cin >> open_OR_flag;
	//
	main_field[x-1][y-1] = char(16);
}

void ranking_numbers(int num1, int num2) {
		if (auxiliary_field[num1][num2] == 6) {	
		}
		else {
			auxiliary_field[num1][num2] = auxiliary_field[num1][num2] + 1;
		}
}
