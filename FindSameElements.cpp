//Given an array with 10 elements
//Draw a graph for the every same element
//that can be found.

/*************************
* Author : Miguel Quizon *
**************************/

#include <iostream>
using namespace std;


int main (int argc, char ** argv) {

	//initialize the input array
	int search_box[] = {1,3,3,4,5,0,8,4,3,6};
	int counter_box[10] = {0};

	for (int i = 0; i < 10; ++i) {
		cout << search_box[i] << endl;
		++counter_box[search_box[i]];
	}

	cout << endl << "COUNTER BOX" << endl << endl;

	for (int i = 0; i < 10; ++i) {
		cout << i << " ";
		for (int x = 0; x <= counter_box[i]-1 ; ++x) {
			cout << '#';
		}
		cout << endl;
	}

	return 0;

}