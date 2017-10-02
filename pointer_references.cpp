/*************************
* Author : Miguel Quizon *
**************************/

//This source code is intended for the exercise of
//use of pointers and references. Tweaks and intended
//hacks with various types were unknown but meant
//to be known in this journey.

#include <iostream>
using namespace std;

int main (int argc, char ** argv) {

	//A pointer is a compound data type that holds the
	//address of a value . It is not clear what value it
	//is. It may be an int, char, string, float, double
	//or other types , it may be even be a null, I'm not
	//sure. One thing to be sure, it's a data type that 
	//holds an address of a value. The value which is
	//located on that address. So when you declare a pointer,
	//you say "i want this address to ...", notice the elipsis?
	//It depends on how you use it, whether it's for allocation
	//or memory manipulation through the use of address. It is
	//worth noting that it can also store adresses.

	//References in the other way is only an alias of a type
	//You manipulate this compound data type and it will make
	//an impact or change on the original variable.

	cout << endl;	
	cout << "=========== Pointer to Pointer ============" << endl;
		
	//pointer to a pointer
	int num = 18;
	//now this is a single level pointer
	//this pointer holds the address of a value
	int * first_level_pointer = &num;
	//this pointer holds the address of a pointer
	cout << "Number Variable Memory Address: " << &num << endl;
	cout << "First Level Pointer Memory Address: " << &first_level_pointer << endl;
	
	//this pointer holds an address of a pointer which holds the
	//address of a value.
	int ** second_level_pointer = &first_level_pointer;

	//to see the address that level 1 pointer , dereference it to get it's value
	//and address of to get the address.
	//the address should be the same the adress of above
	cout << "Second Level Pointer Memory Address (Stage 1) : " << &*second_level_pointer << endl;
	cout << "Second Level Pointer Memory Address (Stage 2) : " << &**second_level_pointer << endl;

	cout << "=========== ================== ============" << endl;
	
	cout << "Number Variable Value: " << num << endl;
	cout << "First Level Pointer Value: " << *first_level_pointer << endl;
	cout << "Second Level Pointer Value (Stage 1) : " << *second_level_pointer << endl;
	cout << "Second Level Pointer Value (Stage 2) : " << **second_level_pointer << endl; 

	cout << "=========== ================== ============" << endl;

	return 0;
}