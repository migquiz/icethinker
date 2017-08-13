//Sample interpretation of pseudocode from
//the cs50 lecture on algorithm

/*************************
* Author : Miguel Quizon *
**************************/

#include <iostream>
using namespace std;

int main (int argc, char ** argv) {

	int num[10] = {2,3,4,1,5,6,8,7,9,0};

	for(int i : num) {
		
		cout << i << endl;
	}

	return 0;
}