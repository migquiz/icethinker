//Problem under the string length variable

#include <iostream>
using namespace std;

//define a type string
typedef char * arrayString;

char characterAt (arrayString s, int position) {
	
	return s[position];
}

int length(arrayString s) {
	int count = 0;

	while (s [count] != 0) {
		++count;
	}

	return count;
}

void append (arrayString & s, char c) {

	int length = length (s);

	cout << "Append | Length | " << length << endl;

	arrayString new_string = new char [length + 2]; //allocate a memory for string

	for (int i = 0; i < length; ++i) {
		new_string [i] = s [i]; //copy the characters in the string s
	}

	new_string [length] = c;
	new_string [length + 1] = 0;
	delete [] s;
	s = new_string;

	cout << &s << " | " << &new_string << endl;
}

void concatenate (arrayString & s1, arrayString s2) {
		
}


int main (int argc, char ** argv) {

	arrayString param_string = "miguel";

	append (param_string , 'c');

	cout << param_string << " | " << &param_string << endl;

	return 0;
}