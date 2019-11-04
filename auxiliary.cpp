//first end on 120 str
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
///////////////////////////////////////
void pranyk(),
	welcome(),
	congratulations(),
	newGame(),
	output(),
	Artin() //artificial Intelligence
	;
///////////////////////////////////////
class BOMB {
	public:
		void setup() {
			x_bomb = 1 + rand() % 3;
			y_bomb = 1 + rand() % 3;
		}
		/*char &location = main_field[x_bomb][y_bomb];
		void open() {
			field[x_bomb][y_bomb] = '*';
		}*/
	private:
		int x_bomb, y_bomb;
};
///////////////////////////////////////
int main() {
	system( "color 89" );
	srand(time(0));
	//welcome();
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
	/*
	BOMB bomb1;
	BOMB bomb2;
	bool verify = false;
	while (verify == false) {
		bomb2.setup();
		if (bomb2.location != bomb1.location) {
			verify = true;
		}
	}
	BOMB bomb3;
	verify = false;
	while (verify == false) {
		bomb3.setup();
		if (bomb3.location != bomb1.location && bomb3.location != bomb2.location) {
			verify = true;
		}
	}
	BOMB bomb4;
	verify = false;
	while (verify == false) {
		bomb4.setup();
		if (bomb4.location != bomb1.location && bomb4.location != bomb2.location && bomb4.location != bomb3.location) {
			verify = true;
		}
	}
	BOMB bomb5;
	verify = false;
	while (verify == false) {
		bomb5.setup();
		if (bomb5.location != bomb1.location && bomb5.location != bomb2.location && bomb5.location != bomb3.location && bomb5.location != bomb4.location) {
			verify = true;
		}
	}
	*/
}
void output() {
	cout << "   1 2 3 4 5\n\n";
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ' ';
		for(int j = 0; j < 5; j++) {
			cout << ' ' << main_field[i][j];
		}
	cout << endl << endl;
	}
}

//second attempt to do working algorithm

/*
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
///////////////////////////////////////
void pranyk(),
	welcome(),
	congratulations(),
	newGame(),
	output(),
	Artin() //artificial Intelligence
	;
///////////////////////////////////////
class BOMB {
	public:
		int location;
		void setup() {
			x_bomb = 1 + rand() % 3;
			y_bomb = 1 + rand() % 3;
			this -> location = auxiliary_field[x_bomb][y_bomb];
		}
		//void open() {
		//	field[x_bomb][y_bomb] = '*';
		//}
	private:
		int x_bomb, y_bomb;
};
///////////////////////////////////////
int main() {
	system( "color 89" );
	srand(time(0));
	//welcome();
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
	//create bomds
	BOMB bomb1;
	BOMB bomb2;
	bool verify = false;
	while (verify == false) {
		bomb2.setup();
		if (bomb2.location != bomb1.location) {
			verify = true;
		}
	}
	BOMB bomb3;
	verify = false;
	while (verify == false) {
		bomb3.setup();
		if (bomb3.location != bomb1.location && bomb3.location != bomb2.location) {
			verify = true;
		}
	}
	BOMB bomb4;
	verify = false;
	while (verify == false) {
		bomb4.setup();
		if (bomb4.location != bomb1.location && bomb4.location != bomb2.location && bomb4.location != bomb3.location) {
			verify = true;
		}
	}
	BOMB bomb5;
	verify = false;
	while (verify == false) {
		bomb5.setup();
		if (bomb5.location != bomb1.location && bomb5.location != bomb2.location && bomb5.location != bomb3.location && bomb5.location != bomb4.location) {
			verify = true;
		}
	}
}
void output() {
	cout << "   1 2 3 4 5\n\n";
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ' ';
		for(int j = 0; j < 5; j++) {
			cout << ' ' << main_field[i][j];
		}
	cout << endl << endl;
	}
}
*/
