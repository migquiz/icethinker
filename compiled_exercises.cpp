//Compiled Exercises
/*************************
* Author : Miguel Quizon *
**************************/

#include <iostream>
#include <cmath>
using namespace std;

int main (int argc, char ** argv) {

	//Solution for the inverted pyramid
	for (int y = 0; y <= 4; ++y) {
		for (int x = 0; x <= 7 - (2 * y); ++x) {
			cout << "#";
		}
		cout << endl;
		for (int space = 0; space <= y; ++space) {
			cout << ' ';
		}
		
	}


	cout << endl;

	//Solution for Diamond
	for (int y = 0; y <= 3; ++y) {
		
		for (int spaces = y; spaces <= 2; ++spaces) {
			cout << ' ';
		}
		for (int x = 0; x <= y + 1 + (1 * y); ++x) {
			cout << "#";
		}
		cout << endl;

	}
	for (int y = 0; y <= 3; ++y) {
		
		for (int x = 0; x <= 7 - (2 * y); ++x) {
			cout << "#";
		}
		cout << endl;
		for (int space = 0; space <= y; ++space) {
			cout << ' ';
		}
	}

	//Solution for the half-square problem
cout << endl;
	for (int y = 0; y <= 6; ++y) {
		for (int x = 0; x <= 3 - abs(3-y); ++x) {
			cout << "#";
		}
		cout << endl;
	}

	return 0;
}