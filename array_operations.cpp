//Array operations consisting of storing, searching and etc
#include <iostream>
using namespace std;

void num_ordinal (int position) {
	position = position % 10;
	switch (position) {
		
		case 1 :
		cout << "st";
		break;

		case 2 :
		cout << "nd";
		break;

		case 3 :
		cout << "rd";
		break;

		default :
		cout << "th";
	}
}

int main (int argc, char ** argv) {

	//sequential search
	const int ARRAY_SIZE = 10;
	int num_array [ARRAY_SIZE] = {23, 30, 34, 35, 2, 10, 7, 9, 12, 18};

	cout << "Enter the number to search: ";

	int search_num;

	cin >> search_num;

	int index = 0;

	while (index != ARRAY_SIZE) {
		
		if (num_array[index] == search_num) {
			cout << "FOUND IT AT " << index + 1;
			num_ordinal (index + 1);
			cout << endl;
			break;
		}

		if (index == ARRAY_SIZE - 1) {
			cout << "NOT FOUND" << endl;
		}

		++index;
	}

	//criterion-based search

	int highest_value = 0;
	int highest_value_position = 0;

	for (int index = 0; index < ARRAY_SIZE; ++index) {
		if (highest_value < num_array[index]) {
			highest_value = num_array[index];
			highest_value_position = index + 1;
		}
	}

	cout << "The highest_value is " << highest_value 
		 << " at " << highest_value_position;
	
	num_ordinal(highest_value_position); 

	return 0;
}