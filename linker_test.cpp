//this source code is for testing only
//data structure : linked list

/*************************
* Author : Miguel Quizon *
**************************/

#include <iostream>
using namespace std;

//construct a linked list

struct node {
	int id;
	node * next;
};

typedef node * linked_list_id;

void insertAtFront (linked_list_id & idees, int id) { //references to make impact	
	//make a new node
	node * new_node = new node;
	new_node->id = id;
	//get the linked list for the insertion
	new_node->next = idees;
	idees = new_node;
}

int main (int argc, char ** argv) {

	node * first_node = new node;
	first_node->id = 9;

	node * second_node = new node;
	second_node->id = 8;

	node * third_node = new node;
	third_node->id = 1;

	linked_list_id idees;

	idees = first_node;
	first_node->next = second_node;
	second_node->next = third_node;
	third_node->next = NULL;


	cout << "Linked List Head Pointer : " << idees << endl << endl;
	cout << "Name of Node | " << " ID | " << " Address " << endl;
	cout << "First Node   | " <<  first_node->id << " | " << first_node << endl;
	cout << "Second Node  | " << second_node->id << " | " << second_node << endl;
	cout << "Third Node   | " << third_node->id <<  " | " << third_node << endl;

	cout << endl << "Insert at Front : " << " ID : " << 12 << endl;
	insertAtFront(idees, 12);

	cout << "Linked List Head Pointer : " << idees << " | Next: " << idees->next << endl;
	cout << "Name of Node | " << " ID | " << " Address " << endl;
	cout << "First Node   | " <<  first_node->id << " | " << first_node << endl;
	cout << "Second Node  | " << second_node->id << " | " << second_node << endl;
	cout << "Third Node   | " << third_node->id <<  " | " << third_node << endl;

	for (node * ptr = idees; ptr != NULL; ptr = ptr->next) {
		cout << ptr->id << endl;
	}

	return 0;
}