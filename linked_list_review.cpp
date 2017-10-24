//This instructions composed of different structs
//and concepts introduced by c++ is goint to express
//recursion in dynamic data like linked list.

#include <iostream>
using namespace std;


int main (int argc, char ** argv) {
	
	struct listNode {
		int data;
		listNode * next;
	};

	typedef listNode * listPtr;
	
	listNode * first_node = new listNode;
	first_node->data = 9;
	first_node->next = NULL;

	listNode * second_node = new listNode;
	second_node->data = 8;
	second_node->next = NULL;

	listNode * third_node = new listNode;
	third_node->data = 10;
	third_node->next = NULL;

	first_node->next = second_node;
	second_node->next = third_node;

	listPtr head_pointer = first_node;

	do {
		int input_num;
		cout << "Enter a number to be stored in a node: " ;
		cin >> input_num;
		listNode * new_node = new listNode;
		new_node->next = head_pointer;
		new_node->data = input_num;
		head_pointer = new_node;
	} while (cin);

	listPtr list_pointer = head_pointer;

	while (list_pointer != NULL) {
		cout << list_pointer->data << endl;
		list_pointer = list_pointer->next;
	}

	return 0;
}