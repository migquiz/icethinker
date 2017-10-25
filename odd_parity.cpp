//Determine if a binary string has odd parity
//meaning that the number of 1 is odd
#include <iostream>
using namespace std;

bool hasOddParity (char bin [], int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (bin[i] == '1') {
			count++;
		}
	}
	if (count % 2 == 0) {
		return false;
	}
	return true;
}

void displayBits(char bin[], int size) {
	if (size == 0) {
		return;
	}
	displayBits (bin, size - 1);
	cout << bin [size - 1] << endl;
}

bool recurOddParity (int bin [], int size, int sum) {
	if (size == 0) {  //take note of things at the end.
		if (sum % 2 == 0) {
			return false;
		}
		return true;
	}
	cout << bin [size - 1];
	sum += bin [size - 1];
	cout << " sum : " << sum << endl;
	recurOddParity (bin, size - 1, sum);
}

int main (int argc, char ** argv) {

	int sum = 0;
	int binary_string [8] = {0,1,1,1,0,0,1,1};
	cout << recurOddParity (binary_string,8,sum) << endl;
	return 0;
}