//A series of numbers express by the function of
//x which x is the sum of the preceding number and
//the other preceding number. Sounds confusing right?

#include <iostream>
using namespace std;

int main (int argc, char ** argv) {

	int num;
	cout << "Enter a initial number for the sequence: ";
	cin >> num;
	cout << "==========================================" << endl;
	
	int count = 0;
	int previous = 0;
	int current_num = num;
	int sum = 0;
	
	while (count < 10) {
		sum = previous + current_num;
		previous = current_num;
		current_num = sum;
		cout << sum << " ";
		++count;
	}

	return 0;
}