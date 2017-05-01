/*************************
* Author : Miguel Quizon *
**************************/

#include <iostream>
using namespace std;

int doubleDigitValue (int digit) {
	
	int doubleDigit = digit * 2;
	int sum;
	
	if (doubleDigit > 10)  {
		sum = 1 + doubleDigit % 10;
	} else {
		sum = doubleDigit;
	}

	return sum;
}

int main (int argc , char ** argv) {

	char digit;
	int oddLengthChecksum = 0; //To track the state of input if an odd or even length.
	int evenLengthChecksum = 0;
	int position = 1;

	cout << "Enter a number: ";
	digit = cin.get();

	while (digit != 10) { // to check if the character is an endline
		if (position % 2 == 0) {
			oddLengthChecksum += doubleDigitValue(digit - '0');
			evenLengthChecksum += digit - '0';
		} else {
			evenLengthChecksum += doubleDigitValue(digit - '0');
			oddLengthChecksum += digit - '0';
		}
		digit = cin.get();
		position++;
	}

	int checksum;

	if ((position - 1) % 2 == 0)
		checksum = evenLengthChecksum;
	else 
		checksum = oddLengthChecksum;

	cout << "Checksum is " << checksum << ".\n";

	if (checksum % 10 == 0) {
		cout << "Checksum is divisible by 10. Valid. \n";
	} else {
		cout << "Check is not divisible by 10. Invalid. \n";
	}

	return 0;
}