//This instructions composed of different structs
//and concepts introduced by c++ is goint to express
//recursion in dynamic data like linked list.

#include <iostream>
using namespace std;

struct listNode {
	int data{0};
	listNode * next;
};

typedef listNode * listPtr;

int count_negative(listPtr head) {
	if (head == NULL) return 0;
	int listCount = count_negative(head->next);
	if (head->data < 0) listCount++;
	return listCount;
}

//trying to implement it in a while construct
int count_negawhile (listPtr head) {
	int count = 0;
	while (head != NULL) {
		if (head->data < 0) {
			++count;
		}
		head = head->next;
	}
	return count;
}

int main (int argc, char ** argv) {

	listPtr head_pointer = NULL;

	do {
		int input_num;
		cout << "Enter a number to be stored in a node: " ;
		cin >> input_num;
		listNode * new_node = new listNode;
		new_node->next = head_pointer;
		new_node->data = input_num;
		head_pointer = new_node;
	} while (cin);	

	//list pointer as a accessor or iterator in the list
	listPtr list_pointer = head_pointer;

	while (list_pointer != NULL) {
		cout << list_pointer->data << endl;
		list_pointer = list_pointer->next;
	}

	cout << "The No. of Negatives: " << count_negawhile(head_pointer) << endl;
	
	return 0;
}