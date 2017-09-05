//Decode a Message Problem
/*************************
* Author : Miguel Quizon *
**************************/
#include <iostream>
using namespace std;

char num2alpha_upp (int number) {
	return number + 'A' - 1;
}

char num2alpha_low (int number) {
	return number + 'a' - 1;
}

char num2punc (int number) {
	switch (number) {
		case 1: return '!'; break;
		case 2: return '?'; break;
		case 3: return ','; break;
		case 4: return '.'; break;
		case 5: return ' '; break;
		case 6: return ';'; break;
		case 7: return '"'; break;
		case 8: return '\''; break;
	}
}

int mod27 (int number) {
	return number % 27;
}

int mod9 (int number) {
	return number % 9;
}



int main (int argc, char ** argv) {

	enum modType { //modulus type, state of decoding
		UPPERCASE, LOWERCASE, PUNCTUATION
	};

	modType mode = UPPERCASE;

	char digitChar;

	do {
		
		digitChar = cin.get(); //first digit
		int number = (digitChar - '0'); //convert to int
		digitChar = cin.get(); //next digit

		while ((digitChar != 10) && (digitChar != ',')) { // converting into number and comma/eof delimiter
			number = number * 10 + (digitChar - '0');
			digitChar = cin.get();
		}

		int mod_res; //modulus value

		switch (mode) {

			case UPPERCASE :
			mod_res = mod27(number);
			if (mod_res == 0) {
				mode = LOWERCASE;
			} else {
				cout << num2alpha_upp (mod_res);
			}
			break; //exits/go to the end of the switch

			case LOWERCASE :
			mod_res = mod27(number);
			if (mod_res == 0) {
				mode = PUNCTUATION;
			} else {
				cout << num2alpha_low (mod_res);
			}
			break;

			case PUNCTUATION :
			mod_res = mod9(number);
			if (mod_res == 0) {
				mode = UPPERCASE;
			} else {
				cout << num2punc (mod_res);
			}
			break;

		}

	} while (digitChar != 10); //to check the end line , prioritized last because have to checked last
	
	return 0;
}
