//computing basic statistics using array
#include <iostream>
#include <algorithm>
using namespace std;

int compareFunc (const void* voidA, const void * voidB) {
	int* intA = (int *) (voidA);
	int* intB = (int *) (voidB);
	return *intA - *intB;
}

int main (int argc, char ** argv) {

	const int ARRAY_SIZE = 10;
	int array_of_num [ARRAY_SIZE];

	cout << "Enter ten numbers: ";

	for (int counter = 0; counter < ARRAY_SIZE; ++counter) {
		
		cin >> array_of_num [counter];
	}

	//compute the average
	int sum = 0;
	int average = 0;

	for (int x : array_of_num) {
		sum += x;
	}

	average = sum/ARRAY_SIZE;

	cout << "The Average is: " << average << endl;

	//computing the mode
	//array should be sorted first
	qsort (array_of_num, ARRAY_SIZE, sizeof(int), compareFunc);

	int most_frequent;
	int highest_frequency = 0;
	int current_frequency = 0;

	for (int index =  0; index < ARRAY_SIZE; ++index) {
		++current_frequency;
		if (index == ARRAY_SIZE - 1 || array_of_num[index] != array_of_num[index + 1]) {
			if (current_frequency > highest_frequency) { //tracks the frequency of the 
				//value when changed to a different value
				highest_frequency = current_frequency;
				most_frequent = array_of_num[index];
			}
			current_frequency = 0;
		}
	}

	//histogram for finding the mode
	int array_of_numbers[ARRAY_SIZE] = {12, 5, 5, 12, 5, 8, 8, 9, 10, 10};
	const int MAX_VALUE = 12;
	int counter_array[MAX_VALUE] = {0};

	for (int x : array_of_numbers) { //range based for loop, implementing iterator
		++counter_array[x - 1];
	}

	int mode = 0;
	int mode_position = 0;
	int counter = 1;

	for (int x : counter_array) {
		if (x > mode) {
			mode = x;
			mode_position = counter;
		}
		++counter;
	}

	cout << "The mode is ";
	cout << mode_position <<  " with " << mode << " occurence(s)." << endl;

	return 0;
}