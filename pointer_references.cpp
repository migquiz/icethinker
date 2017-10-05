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
	//the address should be the same the adress of of the &first_level_pointer
	cout << "Second Level Pointer Memory Address (Stage 0) : " << &second_level_pointer << endl;
	cout << "Second Level Pointer Memory Address (Stage 1) : " << &*second_level_pointer << endl;
	cout << "Second Level Pointer Memory Address (Stage 2) : " << &**second_level_pointer << endl;

	cout << "=========== ================== ============" << endl;
	
	cout << "Number Variable Value: " << num << endl;
	cout << "First Level Pointer Value: " << first_level_pointer << endl;
	cout << "Second Level Pointer Value (Stage 1) : " << *second_level_pointer << endl;
	cout << "Second Level Pointer Value (Stage 2) : " << **second_level_pointer << endl; 

	cout << "=========== ================== ============" << endl;

	//sample crosslinking

	int crosslinked_num = 5;
	int * orig_pt = &crosslinked_num;
	int * accidental_pt = &crosslinked_num; //the right hand operand can be orig_pt

	cout << "Crosslinked Number's Address: " << &crosslinked_num << endl;
	cout << "Original Pointer's Address: " << &orig_pt << endl;
	cout << "Original Pointer's Value: " << orig_pt << endl;
	cout << "Original Pointer's Dereferenced Value: " << *orig_pt << endl;

	cout << "=========== ================== ============" << endl;	

	cout << "Crosslinked Number's Address: " << &crosslinked_num << endl;
	cout << "Accidental Pointer's Address: " << &accidental_pt << endl;
	cout << "Accidental Pointer's Value: " << accidental_pt << endl;
	cout << "Accidental Pointer's Dereferenced Value: " << *accidental_pt << endl;

	cout << "=========== ================== ============" << endl;	

	int other_num = 10;
	accidental_pt = &crosslinked_num;
	cout << "Accidental Pointer's Dereferenced Value: " << accidental_pt << endl;
	delete orig_pt;
	cout << "Original Pointer's Value: " << orig_pt << endl;
	cout << "Accidental Pointer's Dereferenced Value: " << *accidental_pt << endl;
 
	return 0;
}