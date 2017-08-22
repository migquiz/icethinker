//sorting functions particularly in the book
#include <iostream>
#include <algorithm>
using namespace std;

//comparator function for qsort
//needs the header algorithm
int compareFunc (const void* voidA, const void * voidB) {
	int* intA = (int *) (voidA);
	int* intB = (int *) (voidB);
	return *intA - *intB;
}

int main (int argc, char ** argv) {

	const int ARRAY_SIZE = 10;
	int intArray[ARRAY_SIZE] = {87, 28, 100, 78, 84, 98, 75, 70, 81, 68};
	qsort (intArray, ARRAY_SIZE, sizeof(int), compareFunc);

	for (int x : intArray) {
		cout << x << endl;
	}

	//implementation of insertion-sort
	//ascending order
	int start = 0;
	int end = ARRAY_SIZE - 1; //less by 1 for the last index is

	for (int i = start + 1; i <= end; ++i) { //to select the next element
		for (int j = i; j > start && intArray[j-1] > intArray[j]; j--) { 
			//compared to current element to next
			int temp = intArray[j-1];//the larger value stored on a temporary
			intArray[j-1] = intArray[j];//the smaller value stored on first
			intArray[j] = temp;//put the current val to next
		}
	}


	return 0;
}