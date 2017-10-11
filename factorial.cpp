#include <iostream>
using namespace std;

int factorial (int n) {

	if (n == 1) {
		return 1;
	} else if (n == 0) {
		return 0;
	}
	return n * factorial (n-1);
}

int main (int argc, char ** argv) {

	int n;
	cin >> n ;
	cout << endl << factorial (n) << endl;

	return 0;
}