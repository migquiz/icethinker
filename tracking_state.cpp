#include <iostream>
using namespace std;

int main (int argc, char ** argv) {
	
	//char to digit any length
	cout << "Enter a number : ";
	char digitChar = cin.get();
	int number = (digitChar - '0');
	digitChar = cin.get();

	while (digitChar != 10) {
		number = number * 10 + (digitChar - '0');
		digitChar = cin.get();
	}

	cout << number << endl;

	return 0;
}