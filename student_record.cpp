//this is where the implementation of
//student record header will be located
#include "student_record.h"

int studentRecord::grade () {
	return _grade;
}

int studentRecord::studentID () {
	return _studentID;
}

string studentRecord::name () {
	return _name;
}

void studentRecord::setStudentID (int newID) {
	_studentID = newID;
}

void studentRecord::setGrade (int newGrade) {
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

bool studentRecord::isValidGrade (int grade) {
	if ((grade >= 0) && (grade <= 100)){
		return true;
	} else {
		return false;
	}
}

//take note of this implementation
//instead of if else or switch
string studentRecord::letterGrade () {
	const int NUMBER_OF_CATEGORIES = 11;
	const string GRADE_LETTER[] = {"F","D","D+","C-","C","C+","B-","B","B+","A-","A"};
	const int LOWEST_GRADE_SCORE[] = {0,60,67,70,73,77,80,83,87,90,93};
	int category = 0;

	while (category < NUMBER_OF_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade) {
		category++;
	}
	
	return GRADE_LETTER[category - 1];
}