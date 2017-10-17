//Product implementatio in the eyes of the 
//BIG Recursive Idea

//dispatcher
//function that is called with a smaller version of
//the problem. What ? meaning the parameters
//is in reduction.

#include <iostream>
using namespace std;

int product_while (int a, int b) {
	int count = 0;
	int sum = 0;
	while (count < b) {
		sum = sum + a;
		++count;
	}
	return sum;
}

int product_recur (int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	return a + product_recur(a , b - 1);
}

int main (int argc, char ** argv) {
	cout << "The Product is: " << product_while(2,3) << endl;
	cout << "The Recurdu is: " << product_recur(2,1) << endl;
	return 0;
}