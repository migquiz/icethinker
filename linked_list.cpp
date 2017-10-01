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

	//***********NOTE*************
	//no memory allocation happened
	//no address was assigned
	linked_list head_pointer = NULL;

	cout << "---------------" << endl;

	node * first_node = new node;
	node * second_node = new node;
	node * third_node = new node;

	first_node->num = 9;
	second_node->num = 5;
	third_node->num = 3;

	first_node->next = second_node;
	second_node->next = third_node;
	third_node->next = NULL;

	//until an address was pointed out
	//to here. Head Pointer and First Node
	//has the same pointer value.
	//It's different the memory address in the
	head_pointer = first_node;

	cout << head_pointer << " " << first_node << endl;

	node * new_node = new node;
	new_node->num = 10;
	new_node->next = head_pointer;
	head_pointer = new_node; //head pointer gets a new address.

	node * node_for_insert = NULL;

	cout << head_pointer << endl;

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