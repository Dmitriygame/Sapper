//62
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
using namespace std;
///////////////////////////////////////
char field [5][5];
bool victory = false;
///////////////////////////////////////
void pranyk(),
	welcome(),
	congratulations(),
	newGame(),
	output(),
	Artin() //artificial Intelligence
	;
///////////////////////////////////////
int main() {
	system( "color 89" );
	srand(time(0));
	welcome();
	newGame();
	output();
	return 0;
}
///////////////////////////////////////
void pranyk() {
	cout << "Press any key to continue";
	getch();	
};
void welcome() {
	cout << "Welcome to game 'Sapper'!\n";
	cout << "This game is very popular, so I won't describe the rules.\n\n\n";
	pranyk();
}
void congratulations() {
	system("cls");
	cout << "Congratulations!\nYou won!\n\n\n";
	pranyk();
}

void newGame() {
	system("cls");
	//create empty field
	for (int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			field[i][j] = char(219);
		}
	}
	//create bombs
	int x_bomb = 1 + rand() % 8;
	int y_bomb = 1 + rand() % 8;
	char bomb1 = field[x_bomb][y_bomb];
	bool single = false;
	while (single == false) {
		int x_bomb = 1 + rand() % 8;
		int y_bomb = 1 + rand() % 8;
		char bomb2 = field[x_bomb][y_bomb];
		if (bomb2 != bomb1) {
			single = true;
		}
	}
	single = false;
	while (single == false) {
		int x_bomb = 1 + rand() % 8;
		int y_bomb = 1 + rand() % 8;
		char bomb3 = field[x_bomb][y_bomb];
		if (bomb3 != bomb1 && bomb3 != bomb2) {
			single = true;
		}
	}
	single = false;
	while (single == false) {
		int x_bomb = 1 + rand() % 8;
		int y_bomb = 1 + rand() % 8;
		char bomb4 = field[x_bomb][y_bomb];
		if (bomb4 != bomb1 && bomb4 != bomb2 && bomb4 != bomb3) {
			single = true;
		}
	}
	single = false;
	while (single == false) {
		int x_bomb = 1 + rand() % 8;
		int y_bomb = 1 + rand() % 8;
		char bomb5 = field[x_bomb][y_bomb];
		if (bomb5 != bomb1 && bomb5 != bomb2 && bomb5 != bomb3&& bomb5 != bomb4) {
			single = true;
		}
	}
	
}
void output() {
	cout << "   1 2 3 4 5\n\n";
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ' ';
		for(int j = 0; j < 5; j++) {
			cout << ' ' << field[i][j];
		}
	cout << endl << endl;
	}
}
