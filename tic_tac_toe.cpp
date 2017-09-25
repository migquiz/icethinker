/*************************
* Author : Miguel Quizon *
**************************/

//A simple console-based tic-tac-toe game
//The input would be a coordinate in a 3 by 3
//matrix

#include <iostream>
using namespace std;

void drawTicTacToe (const int MATRIX_SIZE, char  tictactoe_matrix[3][3]) {
	for (int x = 0; x < MATRIX_SIZE; ++x) {
		for (int y = 0; y < MATRIX_SIZE; ++y) {
			cout << tictactoe_matrix[x][y];
		}
		cout << endl;
	}
}

int main (int argc, char ** argv) {
	
	const int MATRIX_SIZE = 3;
	char tictactoe_matrix [MATRIX_SIZE][MATRIX_SIZE]; //drawing of the matrix
	int x , y;
	cout << endl; //just to make the console output clean

	int turns = 0;
	
	while (turns < 3) {
		cout << "Enter the coordinates: ";
		cin >> x >> y;
		tictactoe_matrix[x][y] = '0';
		++turns;
	}

	cout << endl; 
	//output of the matrix
	drawTicTacToe (MATRIX_SIZE, tictactoe_matrix);
	

	return 0;
}