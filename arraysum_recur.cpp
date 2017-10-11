//this code uses recursion in computing the
//summation of interger stored in an array
#include <iostream>
using namespace std;

int recursive_sum(int num[], int size) {

	cout << "this is a test if called before | size: " << size << endl;
	if (size == 0) {
		cout << endl;
		return 0;
	}

	int last_num = num [size-1];
	int the_rest = recursive_sum (num, size-1);
	//when the return value is 0 , below will be executed.
	cout << "this is a test if called after | size: " << size << endl;
	return last_num + the_rest; //this will not be called unless the 
	//preceding returning value of the function in the active
	//record (function in the stack needs to be popped out) is completed.
	//that's how functions are stored in the memory
}

int main (int argc, char ** argv) {

	int num[10] = {1,2,3,4,5,6,7,8,9,10};
	cout << "The Summation: " << recursive_sum(num,10) << endl;
	
	return 0;
}