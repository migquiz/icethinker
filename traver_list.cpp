//Singly Linked List Traversal
//In-order and Reverse-order

#include <iostream>
using namespace std;

struct listNode {
	int data;
	listNode * next;
};

typedef listNode * listPtr;

void inOrder (listPtr head) {
	if (head != NULL) {
		cout << head->data << endl;
		inOrder(head->next);
	}
}

void reverseOrder (listPtr head) {
	if (head != NULL) {
		reverseOrder(head->next);
		cout << head->data << endl;
	}
}

int main (int argc, char ** argv) {

	listNode * first_node = new listNode;
	listNode * second_node = new listNode;
	listNode * third_node = new listNode;
	listNode * fourth_node = new listNode;
	listNode * fifth_node = new listNode;

	first_node->data = 5;
	second_node->data = 18;
	third_node->data = 95;
	fourth_node->data = 2;
	fifth_node->data = 20;

	first_node->next = second_node;
	second_node->next = third_node;
	third_node->next = fourth_node;
	fourth_node->next = fifth_node;
	fifth_node->next = NULL;

	listPtr head = first_node;

	inOrder (head);
	reverseOrder (head);
	
	return 0;
}