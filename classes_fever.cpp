//This program contains sample codes for classes
//written on C++

//Client code utilizes the interfaces
//Server Code which has the implementation

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

	sample with_def(3);
	cout << with_def.getSample() << endl;

	return 0;
}