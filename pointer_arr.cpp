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
	cout << "Num Memory Address | " << &num << endl;
	cout << "Num Pointer's Memory Address | " << &pointer << endl;
	cout << "Num Pointer Value (Address) | " << pointer << endl;
	cout << "------------------------------------------" << endl;

	int& num_ref = *pointer;

	num_ref = 3;

	cout << "Num | " << num << endl;
	cout << "Num Pointer | " << *pointer << endl;
	cout << "Num Memory Address | " << &num << endl;
	cout << "Num Pointer Value (Address) | " << pointer << endl;
	cout << "Num Reference | " << num_ref << endl;
	cout << "Num Reference Memory Address | " << &num_ref << endl;

	//they should change all their values.
	//how references work is an alias.
	//it is a type that holds the same address of the thing it references
	//if you change the value of the "reference" it will also change the value
	//of the variable it references.
	*pointer = 2;
	num_ref = *pointer;
	cout << num << endl;
	cout << num_ref << endl;
	cout << *pointer << endl;

	return 0;
}