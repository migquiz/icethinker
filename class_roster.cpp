/*************************
* Author : Miguel Quizon *
**************************/

//From the Class Roster Problem
/*
Design a class or set of classes for use in a program 
that maintains a class roster. For each student, store
the student’s name, ID, and final grade score in the 
range 0–100. The program will allow student records to
be added or removed; display the record of a particular 
student, identified by ID, with the grade displayed as 
a number and as a letter; and display the average score
for the class.
*/

#include <iostream>
using namespace std;

class studentRecord {
	public:
   		studentRecord();
		studentRecord(int newGrade, int newID, string newName);
		void setGrade(int newGrade);
		void setStudentID(int newID);
		void setName(string newName);
		int studentID();
		int grade();
		bool isValidGrade(int grade);
		string name();
		string letterGrade();
	private:
		int _grade;
		int _studentID;
		string _name;
};

int studentRecord::grade() {
	return _grade;
}

int studentRecord::studentID() {
	return _studentID;
}

string studentRecord::name() {
	return _name;
}

void studentRecord::setStudentID(int newID) {
	_studentID = newID;
}

void studentRecord::setGrade(int newGrade) {
	if (isValidGrade(newGrade))
	_grade = newGrade;
}

void studentRecord::setName (string newName){
	_name = newName;
}

studentRecord::studentRecord (int newGrade, int newID, string newName) {
	setGrade (newGrade);
	setStudentID (newID);
	setName (newName);
}

studentRecord::studentRecord () {
	setGrade(0);
	setStudentID(-1); //set to illegitimate value not to confuse
	setName("");
}

bool studentRecord::isValidGrade(int grade) {
	if ((grade >= 0) && (grade <= 100)){
		return true;
	} else {
		return false;
	}
}

//take note of this implementation
//instead of if else or switch
string studentRecord::letterGrade() {
	const int NUMBER_OF_CATEGORIES = 11;
	const string GRADE_LETTER[] = {"F","D","D+","C-","C","C+","B-","B","B+","A-","A"};
	const int LOWEST_GRADE_SCORE[] = {0,60,67,70,73,77,80,83,87,90,93};
	int category = 0;

	while (category < NUMBER_OF_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade) {
		category++;
	}
	
	return GRADE_LETTER[category - 1];
}

int main (int argc, char ** argv) {

	//declare like a normal datatype with the default constructor
	studentRecord fooStudentRecord;
	cout << fooStudentRecord.name() << endl;
	//declare like what we have on the definition
	studentRecord booStudentRecord(90,123,"Miggy");
	cout << booStudentRecord.letterGrade() << endl;
	return 0;
}
