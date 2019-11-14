//дебил, [][], а не [,]
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
int x_bomb, y_bomb;
//////////////////////////////////////			


int x, y;
///////////////////////////////////////
int main() {
	system( "color 89" );
	srand(time(0));
	
	char a = char(16);
	
	for (int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			main_field[i][j] = char(219);
		}
	}
	
	main_field[2][2] = a;
	main_field[2][3] = a;
	main_field[4][2] = a;

cout << "   1 2 3 4 5\n\n";
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ' ';
		for(int j = 0; j < 5; j++) {
			cout << ' ' << main_field[i][j];
		}
	cout << endl << endl;
	}

	return 0;
}
///////////////////////////////////////
