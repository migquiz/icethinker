//this is to convert a string to an int;
//it's a series of trial and error

#include <iostream>
using namespace std;

int length(string num_in_string) {
	int i = 0;
	while (num_in_string[i] != NULL) {
		i++;
	}
	return i;
}

int toInt(string num_in_string) {
	int i = 0;
	int sum = 0;
	int mod;
	while (num_in_string[i] != NULL && mod != 0) {

	}
}

string reverse (string num) {
	string reversal;
	int str_length = length(num);
	int counter = 0;
	while (counter < str_length) {
		reversal += num[str_length-counter - 1];
		++counter;
	}
	return reversal;
}

string toString(int num) {
	
	string result;
	char tmp;
	int mod;
	
	while (num != 0) {
		mod = num % 10;
		tmp = mod + '0';
		result += tmp;
		num = num /10;
	}

	return reverse(result);
}

int main (int argc, char ** argv) {

	cout << length ("miguel") << endl;
	cout << "to String | " << toString(1234) << endl;
	return 0;
}