//an array that contains a struct or class

//some snippets from the book were used as a note
//some parts of the program will not work properly

#include <iostream>
using namespace std;

int main (int argc, char ** argv) {

	struct student {
		int grade;
		int student_ID;
		string name;
	};

	const int ARRAY_SIZE = 10;

	student student_array [ARRAY_SIZE] = {
		{87, 10001, "Fred"},
		{28, 10002, "Tom"},
		{100, 10003, "Alistair"},
		{78, 10004, "Sasha"},
		{84, 10005, "Erin"},
		{98, 10006, "Belinda"},
		{75, 10007, "Leslie"},
		{70, 10008, "Candy"},
		{81, 10009, "Aretha"},
		{68, 10010, "Veronica"}
	};

	for (student x : student_array) {
		cout << x.name << endl;
		cout << x.student_ID << endl;
		cout << x.grade << endl << endl;
	}

	const int NUM_AGENTS = 3;
	const int NUM_MONTHS = 12;

	int sales[NUM_AGENTS][NUM_MONTHS] = {
		{1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
		{5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
		{23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
	};

	for (int x : sales[0]) { //when you pass a a dimension the succeeding array 
		//will be referenced
		cout << x << endl;
	}

	//without the use of range based loop
	for (int index = 0; index < ARRAY_SIZE; ++index) {
		cout << sales[1][index] << endl;
	}

	//allocate the size of an array dynamically
	cout << "Enter the size of array: ";
	int alloc_size;
	cin >> alloc_size;

	int alloc_arr [alloc_size];

	//allocate the size of an array using a pointer and the new keyword
	int* surveyData = new int[ARRAY_SIZE];

	//to deallocate use the delete keyword
	delete[] surverData;

	return 0;
}