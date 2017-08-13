//CS50 Week 5 Data Structures
//This contains short source code from the lecture

#include <iostream>
using namespace std;

int main (int argc, char **argv) {
	
	typedef struct node {
		int num;
		struct node *next;
	}

	//searching

	bool search (int n, node *list) {
		node *ptr = list;
		while (ptr!= NULL) {
			if (ptr->num ==n) { //when accessing a data 
				//in a struct/class through a pointer
				//use this ->
				return true;
			}
			ptr = ptr->next;
		}
		return false;
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