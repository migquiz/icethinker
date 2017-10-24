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
#include <string.h>
using namespace std;

//this was the result of poor code structuring
//i'm not able to track the past exerices
//so i'm going to put it in here .

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

//this class involves "composition"
//when an object needs other to complete itself
//in designing a class , ask what should i send out
//question is helpful.

typedef bool (* firstStudentPolicy) (studentRecord r1, studentRecord r2);

bool higherGrade (studentRecord r1, studentRecord r2) {
	return r1.grade() > r2.grade();
}

bool lowerStudentNumber (studentRecord r1, studentRecord r2) {
	return r1.studentID() < r2.studentID();
}

bool nameComesFirst (studentRecord r1, studentRecord r2) {
	return strcmp(r1.name().c_str(), r2.name().c_str()) < 0;
}

class studentCollection {
private:
	struct studentNode {
		studentRecord studentData;
		studentNode * next;
	};
public:
	studentCollection ();
	~studentCollection ();
	studentCollection(const studentCollection &original);
	studentCollection & operator= (const studentCollection & rhs);
	void addRecord (studentRecord newStudent);
	studentRecord recordWithNumber (int student_ID);
	void removeRecord (int student_ID);
	void setFirstStudentPolicy(firstStudentPolicy f);
	studentRecord firstStudent();
	friend class scIterator;
private:
	firstStudentPolicy _currentPolicy;
	typedef studentNode * studentList;
	studentList _listHead;
	void deleteList (studentList &listPtr);
	studentList copiedList(const studentList original);
};

studentRecord studentCollection::firstStudent () {
	if (_listHead == NULL || _currentPolicy == NULL) {
		studentRecord dummyRecord (-1, -1, "");
		return dummyRecord;
	}
	studentNode * loopPtr = _listHead;
	studentRecord first = loopPtr->studentData;
	loopPtr = loopPtr->next;
	while (loopPtr != NULL) {
		if (_currentPolicy(loopPtr->studentData, first)) {
			first = loopPtr->studentData;
		}
		loopPtr = loopPtr->next;
	}
	return first;
}

class scIterator {
	studentCollection::studentNode * current;
	studentRecord student();
public:
	scIterator();
	scIterator(studentCollection::studentNode * initial);
};

studentRecord scIterator::student() {
	if (current == NULL) {
		studentRecord dummyRecord (-1, -1 , "");
		return dummyRecord;
	} else {
		return current->studentData;
	}
}

scIterator::scIterator() {
	current = NULL;
}

scIterator::scIterator(studentCollection::studentNode * initial) {
	current = initial;
}

void studentCollection::setFirstStudentPolicy (firstStudentPolicy f) {
	_currentPolicy = f;
}

studentCollection::studentCollection () {
	_listHead = NULL;
	_currentPolicy = NULL;
}

studentCollection::~studentCollection () {
	deleteList (_listHead);
}


//copy constructor
//in copying you use the operator loading as exposed by the use
//of "=" sign operator. So whenever this constructor is executed
//either explicitly or implicitly. the overload operator will
//do its function. here we pass the "object" as a reference in const
//to avoid altering the "object's" value that was referenced.
studentCollection::studentCollection (const studentCollection &original) {
	_listHead = copiedList(original._listHead);
}

//operator overloading, folks.
//the right hand side is the parameter, the left hand is a reference
//to data members of the class and the instance(object) of the class
//referencing makes an impact to the value it references.
studentCollection & studentCollection::operator = (const studentCollection & rhs) {
	if(this != &rhs) { //this is a pointer to the type (value is an address to a type(class))
		deleteList(_listHead);
		_listHead = copiedList(rhs._listHead);//entirely new list with different address in the memory		
	}
	//return the new copied list from the right hand side , this is type StudentCollection
	return *this;
}

studentCollection::studentList	studentCollection::copiedList(const studentList original) {
	if (original == NULL) {
		return NULL;
	}
	studentList newList = new studentNode; //allocate a space in memory which stores an address
	newList->studentData = original->studentData; //go to the address it points to and store the studentData which is a record
	studentNode * oldLoopPtr = original->next; //store the value of "next" which an address that points to node
	studentNode * newLoopPtr = newList; //store the value of newList which is an address that points to a node
	//because the newLoopPtr shares the same value (address) that the newList holds. It can manipulate the list
	//indirectly but the information and data still remains on the newlist even if the loopPtr value changes because
	//it is not binded with it(newList). This is clearly leveraged crosslinking
	while (oldLoopPtr != NULL) {
		newLoopPtr->next = new studentNode; //new node , an address in the memory
		newLoopPtr = newLoopPtr->next; //newLoopPtr value(address that points to) will be replaced
		//don't be confused with the newlist. The list will build up eventually because the newList
		//next pointer still retains it's value. After a new node was made up in the line above. The newLoopPtr
		//will have it new value (address) because the ->next value(address) is assigned into it.
		//so for the next iteration the the newLoopPtr will have it's next data member and so on.
		//REMEMBER : if you're assigning to a pointer : you're not altering the value itself
		//but the address it holds.
		newLoopPtr->studentData = oldLoopPtr->studentData;
		oldLoopPtr = oldLoopPtr->next;
	}
	newLoopPtr->next = NULL;
	return newList;
}

void studentCollection::deleteList (studentList &listPtr) {
	while (listPtr != NULL) {
		studentList temp = listPtr; 
		listPtr = listPtr->next;
		delete temp;
	}
}

void studentCollection::addRecord (studentRecord newStudent) { //inserting a node in the front
	studentNode * newNode = new studentNode; //make a node
	newNode->studentData = newStudent; //assign the data to the newnode's payload
	newNode->next = _listHead; //next node is the listhead
	_listHead = newNode; //head pointer is the new node
}

studentRecord studentCollection::recordWithNumber (int student_number) {
	studentNode * loopPtr = _listHead; //to traverse the list

	//if the list still null , no nodes at all
	while (loopPtr != NULL && loopPtr->studentData.studentID() != student_number) {
		loopPtr = loopPtr->next;
	}
	if (loopPtr == NULL) { //if the list is still null , no nodes at all
		studentRecord dummyRecord (-1, -1, ""); //return a dummy record
	} else {
		return loopPtr->studentData;
	}
	return loopPtr->studentData;
}

//how the trailing pointer manages to manipulate the whole linked list?
//trailing is a pointer that points to a node
//pointer is a compound data type that holds the address of a value.

//pointers can be used to alter/disturb a structure
//using an address, likewise if i use your
//adress in a delivery i can force you to receive an item

void studentCollection::removeRecord (int student_ID) {
	//traverse the link list
	//if the node is found delete it -->
	//think of the pointers here as addresses
	//trailing node pointer must be renamed into "previous" node
	studentNode * loopPtr = _listHead;
	studentNode * trailing = NULL; //a pointer to the node in the original linked list 
	while (loopPtr != NULL && loopPtr->studentData.studentID() != student_ID) {
		trailing = loopPtr; //somewhere in the memory points in here
		//loopPtr : i have the address of the head pointer
		//trailing : cool, i'll keep it
		//loopPtr : i'll be deleted or deallocated in the heap memory
		//trailing : the preceding pointer should point to me
		//loopPtr : take note of us, we're pointing to a node pointer
		//not really the address , an address is not the same with a data type
		//that holds an address remember that.
		loopPtr = loopPtr->next; //next is also a node 
	}
	if (loopPtr == NULL) return;
	if (trailing == NULL) {
		_listHead = _listHead->next;
	} else {
		trailing->next = loopPtr->next;
	} //the previous node "next" attribute assigned with the node after the node to be del...
	delete loopPtr; //memory deallocation
}

int main (int argc, char ** argv) {

	//declare like a normal datatype with the default constructor
	studentRecord fooStudentRecord;
	cout << fooStudentRecord.name () << endl;
	//declare like what we have on the definition
	studentRecord booStudentRecord (90,123,"Miggy");
	cout << booStudentRecord.letterGrade () << endl;
	studentCollection student_collection;
	student_collection.addRecord(booStudentRecord);
	studentCollection boo_collection(student_collection);
	cout << student_collection.recordWithNumber(123).name() << endl;
	cout << boo_collection.recordWithNumber(123).name() << endl;
	return 0;
}
