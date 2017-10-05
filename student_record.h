//another header file for the
//student record
#include <iostream>
using namespace std;

class studentRecord {
public:
	studentRecord ();
	studentRecord (int newGrade, int newID, string newName);
	void setGrade (int newGrade);
	void setStudentID (int newID);
	void setName (string newName);
	int studentID ();
	int grade ();
	bool isValidGrade (int grade);
	string name ();
	string letterGrade ();
private:
	int _grade;
	string _name;
	int _studentID;
};