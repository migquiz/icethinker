//To refresh the mind from a pointer
//to an array in type int
#include <iostream>
using namespace std;

int main (int argc, char** argv) {

	//an array of integer
	//as with the latest standard
	//we can initialized by the use of curly brackets
	int array_of_num[5] = {1,2,3,4,5};

	//an int pointer to an array
	//since an array is a collection in a memory
	//the name of the variable without the "[]"
	//square braces references the first element
	//or the address in the memory which is stored
	//in the pointer
	//conclusion is array are pointers too.
	int* pt_array = array_of_num;

	int num = 9;
	int* pointer = &num;

	cout << "Num | " << num << endl;
	cout << "Num Pointer | " << *pointer << endl;
	cout << "Num Address | " << &num << endl;
	cout << "Num Pointer Address | " << pointer << endl;
	cout << "------------------------------------------" << endl;

	int& num_ref = *pointer;

	num_ref = 3;

	cout << "Num | " << num << endl;
	cout << "Num Pointer | " << *pointer << endl;
	cout << "Num Address | " << &num << endl;
	cout << "Num Pointer Address | " << pointer << endl;

	return 0;
}