/*
двузначные числа двигают массив
макс. ширина массива - 38.

проигрыш, выигрыш
*/
#include <iostream>

using namespace std;

int main() {

	return 0;
}

/*
// не смог соседи-ноль
//along the edges
			//left side
				else if (x > 0 && x < rows-1 && y == 0) {
					const int X=x, Y=y;
					--x; open();
					x=X;
					--x; ++y; open();
					x=X; y=Y;
					++y; open();
					x=X; y=Y;
					++x; open();
					x=X;
					++x; ++y; open();
				}
					//right side
				else if (x > 0 && x < rows-1 && y == columns-1) {
					x=x-1; open();
					x=x-1; y=y-1; open();
					y=y-1; open();
					x=x+1; open();
					x=x+1; y=y-1; open();
				}
					//up side
				else if (y > 0 && y < columns-1 && x == 0) {
					y=y+1; open();
					y=y-1; open();
					x=x+1; y=y-1; open();
					x=x+1; open();
					x=x+1; y=y+1; open();
				}
					//down side
				else if (y_bomb > 0 && y_bomb < columns-1 && x == rows-1) {
					y=y+1; open();
					y=y-1; open();
					x=x-1; y=y-1; open();
					x=x-1; open();
					x=x-1; y=y+1; open();
				}
				else {
					x=x+1; open();
					x=x+1; y=y+1; open();
					x=x+1; y=y-1; open();
					x=x-1; open();
					x=x-1; y=y+1; open();
					x=x-1; y=y-1; open();
					y=y+1; open();
					y=y-1; open();
				}
		
	open_all();
		for (int i = 0; i < rows; i++) {
			for(int j = 0; j < columns; j++) {
				x=i; y=j;
				open();
			}
		}
*/				
/*
void output_auxiliary_field() {
	cout << "   ";
	for (int i = 0; i < columns; i++) {
		cout << i+1 << ' ';
	}
	cout << endl << endl;
	
	for (int i = 0; i < rows; i++) {
		cout << i+1 << ' ';
		for(int j = 0; j < columns; j++) {
			cout << ' ' << auxiliary_field[i][j];
		}
	cout << endl << endl;
	}
}			
*/
