//This program contains sample codes for classes
//written on C++

#include <iostream>
using namespace std;

class sample {
public:
	sample(){};
	sample(int num) {intData = num;};
	int doesSomething(double param);
	int getSample() {return intData;};
private:
	int intData;
};
	
int main(int argc, char ** argv) {

	sample foo_sample(9);

	cout << foo_sample.getSample() << endl;

	sample with_def;
	cout << with_def.getSample() << endl;

	return 0;
}