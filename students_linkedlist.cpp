//this program is for tracking an unknown quantity
//no. of students using linked list
//pros - growable and shrinkable

#include <iostream>
using namespace std;

//a linked list composes one or more nodes

//might be confusing at first
//structure in terms of itself

struct listNode {
	int student_Num;
	int grade;
	listNode * next; //pointer to a node
};

//type definiition of collection of students of linked list
typedef listNode * studentCollection; 


void addRecord (studentCollection& stud_collection, int student_num, int grades) {
	listNode * newNode = new listNode;
	newNode->student_Num = student_num;
	newNode->grade = grades;
	//listNode is a pointer itself , assign the address of original collection
	//pointer that has a pointer
	newNode->next = stud_collection;
	//assigned the newNode as new head pointer
	stud_collection = newNode;
}

void averageRecord (studentCollection stud_collection) {

}

double averageRecord_double (studentCollection stud_collection) {
	int count = 0;
	double sum = 0;
	listNode * loopPtr = stud_collection;
	while (loopPtr != NULL) {
		sum += loopPtr->grade;
		count++;
		loopPtr->next;
	}
	double average = sum/count;
	return average;
}

int main (int argc, char ** argv) {

	//get used into user-defined types
	//this has no attribute value for num and grade
	//only a node that points to next
	studentCollection student_collection;

	listNode * node1 = new listNode; 
	node1->student_Num = 1001; //pointed by a pointer to a field then "->"
	node1->grade = 78; //or (*node1).grade 

	listNode * node2 = new listNode;
	node2->student_Num = 1012;
	node2->grade = 93;

	listNode * node3 = new listNode;
	node3->student_Num = 1076;
	node3->grade = 85;

	student_collection = node1; //only points to the first node
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	//add Record Function here

	//average Record Function Here
	int average = averageRecord(student_collection);

	//to avoid cross linking and to clean up
	node1 = node2 = node3 = NULL;
	
	return 0;
}