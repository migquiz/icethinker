#include <iostream>
using namespace std;

int main (int argc, char ** argv) {
	
	char digitChar;

	do {
		
		digitChar = cin.get();
		int number = (digitChar - '0');
		digitChar = cin.get();

		while ((digitChar !=  10) && (digitChar != ',')) {
			number = number * 10 + (digitChar -'0');
			digitChar = cin.get();
		}

	} while (digitChar != 10);

	cout << digitChar << endl;

	return 0;
}