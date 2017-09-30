//CS50 Week 5 Data Structures
//This contains short source code from the lecture

#include <iostream>
using namespace std;

int main (int argc, char **argv) {
	
	struct node {
		int num;
		node * next;
	};

	typedef node * linked_list;

	linked_list head_pointer = NULL;

	cout << "---------------" << endl;

	node * first_node = new node;
	cout << &first_node << " first_node address" << endl;

	node * dummy = new node;
	cout << &dummy << " dummy node address" << endl;

	cout << "----------------" << endl;
	dummy = first_node;
	cout << &dummy << " dummy node address" << endl;
	cout << &first_node << " first_node adress" << endl;

	first_node->num = 9;
	first_node->next = head_pointer;
	head_pointer = first_node;

	node * loop_pointer = head_pointer;

	if (loop_pointer != NULL) {
		cout << "loop pointer not null" << loop_pointer << endl;
	} else {
		cout << "ala e' null" << endl;
	}

	if (NULL == 0) {
		cout << "null is zero" << endl;
	}

	loop

	cout << "loop_pointer : " << &loop_pointer << endl;
	cout << "head_pointer : " << &head_pointer << endl;
	cout << loop_pointer->num << endl;

	cout << "------------" << endl;
	cout << &first_node << endl;
	cout << &head_pointer << endl;
	cout << &dummy << endl;

	return 0;
}

//if im going to declare the primitive data structure 
//it would be like this
//int array [10]
//node new_node;
//int linked_list 

//inserting
	//allocate memory
	//get the pointer of the previos node
	//assign to new node
	//assign the pointer of new node to previous node


//deleting