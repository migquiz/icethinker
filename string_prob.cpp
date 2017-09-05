//Problem under the string length variable

#include <iostream>
using namespace std;

//define a type string
typedef char * arrayString; //size unknown

char characterAt (arrayString s, int position) {
	
	return s[position];
}

int getlength(arrayString s) {
	int count = 0;

	while (s [count] != 0) {
		++count;
	}

	return count;
}

void append (arrayString & s, char c) { //allocated heap memory on the parameter

	int length = getlength (s);

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
	//get the length of the two strings

	int first_string_length = getlength (s1);
	int second_string_length = getlength (s2);
	int concatenated_string_length = first_string_length + second_string_length;

	arrayString new_string = new char [concatenated_string_length + 1]; //to add null or 0 character

	for (int i = 0; i < first_string_length; ++i) { //copy the characters into the new_string
		new_string[i] = s1[i];
	}

	for (int i = 0; i < second_string_length; ++i) {
		new_string[first_string_length + i] = s2[i];
	}

	new_string[concatenated_string_length] = 0;
	delete [] s1;
	s1 = new_string;

}


int main (int argc, char ** argv) {

	arrayString param_string = "miguel";

	append (param_string , 'c');

	cout << param_string << " | " << &param_string << endl;

	arrayString concat_first = "concat", concat_second = "enate";

	concatenate (concat_first , concat_second);

	cout << "RESULT : " << concat_first << endl; //concatenation complete

	return 0;
}