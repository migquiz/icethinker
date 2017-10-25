//Implementations of cs50 lecture on
//data structure

#include <iostream>
using namespace std;

typedef struct node {
	int data;
	struct node * next;
} node;

typedef node * list_pointer;

int main (int argc, char ** argv) {

	//array of values or data
	//for the nodes in the linkedlist
	int data[5] = {5,17,18,22,95};

	//insert at the end of the list

	list_pointer head_ptr = NULL;

	node * first_node = new node;
	node * second_node = new node;
	node * third_node = new node;
	node * fourth_node = new node;
	node * fifth_node = new node;

	head_ptr = first_node;
	first_node->next = second_node;
	second_node->next = third_node;
	third_node->next = fourth_node;
	fourth_node->next = fifth_node;
	fifth_node->next = NULL;

	list_pointer llpointer = head_ptr;

	for (int val : data) {
		llpointer->data = val;
		llpointer = llpointer->next;
	}

	llpointer = head_ptr;

	node * sixth_node = new node;
	sixth_node->data = 4;

	while (llpointer != NULL) {
		if (llpointer->next == NULL) {
			llpointer->next = sixth_node;
			sixth_node->next = NULL;
		}
		llpointer = llpointer->next;
	}

	list_pointer iter = head_ptr;

	while (iter != NULL) {
		cout << iter->data << endl;
		iter = iter->next;
	}

	return 0;
}