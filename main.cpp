//for the student record test on a main function
//i don't know if this is right haha.
//this is my first try without looking any references
//except for the debug
#include "student_record.cpp"
#include <iostream>
using namespace std;

int main (int argc, char ** argv) {
	studentRecord first_record(98,1304,"Michael");
	cout << first_record.studentID() << endl;
	return 0;
}