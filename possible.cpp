//isPossible Problem in the Hackerrank
//to do problem

#include <iostream>
using namespace std;

//input is
//1
//4
//5
//9


// string isPossible (int a, int b, int c, int d) {
// 	//reduce the proble by using only the first
// 	//operation.
// 	//determine if the (a,b) can converted into
// 	//(c,d) by using this operation (a, a+b)
// 	//zero or more times.

// 	int a{5}, b{9}, c{5}, d{23};

// }

string string_what (bool _return) {
	if ((_return)) {
		return "TRUE";
	}
	return "FALSE";
}

bool jiggs_possible (int a, int b, int &c, int &d) {
	if ((a == c) && (b == d)) {
		return true;
	} else if ((a > c) || (b > d)) {
		return false;
	} else {
		return jiggs_possible(a, a+b, c, d) || jiggs_possible (a+b, b, c, d);
	}
}

bool first_func (int a, int b, int c, int d) {
	bool tester;
	while (b < d) {
		
		b = a + b;
	}
	cout << b << " ";	
	if (b == d) {
		return true;
	}
	return false;
}

bool second_func (int a, int b, int c, int d) {
	bool tester;

	while (a < c) {
		a = a + b;
	}
	cout << b << " ";
	if (a == c) {
		return true;
	}
	return false;
}


int main (int argc , char ** argv) {

	const int size = 6;
	string results[size] = {"TRUE","TRUE","FALSE","FALSE","FALSE","TRUE"};

	int a[size] = {2,2,2,3,1,3};
	int b[size] = {3,5,2,7,5,4};
	int c[size] = {25,2,8,4,13,11};
	int d[size] = {14,5,4,8,16,15};

	for (int i = 0; i < size; ++i) {
		cout << "(" << a[i] << "," << b[i] << ")" << "->" << "(" << c[i] << "," << d[i] << ")" << endl;
		cout << "Expected result: " << results[i] << " | Actual result: "
		<< string_what(jiggs_possible (a[i],b[i],c[i],d[i])) << endl;
	}
	cout << "------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; ++i) {
		cout << "(" << a[i] << "," << b[i] << ")" << "->" << "(" << c[i] << "," << d[i] << ")" << endl;
		cout << "Expected result: " << results[i] << " | Actual result: "
		<< string_what(first_func (a[i],b[i],c[i],d[i]) || second_func (a[i],b[i],c[i],d[i])) << endl;
	}

	int apple = a[0];
	int ball = b[0];
	int cat = c[0];
	int dog = d[0];

	if (apple > cat || ball > dog) {
		cout << "False";
	}

	apple += 

	return 0;
}