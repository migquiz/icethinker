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
	//the head pointer will hold the address of the firs node
	head_pointer = first_node;

	cout << head_pointer << " " << first_node << endl;

	node * new_node = new node;
	new_node->num = 10;
	new_node->next = head_pointer;
	head_pointer = new_node; //head pointer gets a new address.


	node * test_node = NULL;
	test_node = first_node; //"take this address", said to test_node;
	test_node->next = second_node->next; //"using that address point to the
	delete second_node; //third note then delete the second node.

	//Test Loop
	node * iterator = NULL;
	iterator = head_pointer;
	while (iterator != NULL) {
		cout << iterator->num << endl;
		iterator = iterator->next;
	}

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