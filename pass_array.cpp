/*************************
* Author : Miguel Quizon *
**************************/

//Code exercise in passing an array
//Either single or multi

#include <iostream>
using namespace std;

//finding : in passing multidimensional include the 
//size in the formal parameter
void output_num_array (int num_param_array [][]) {
	for (int counter = 0; counter < 5; ++counter) {
		cout << num_param_array [counter] << endl;
	}
}

int main (int argc, char ** argv) {
	
	int num_array[2][5] = {{0,0,0,0,0},{1,1,1,1,1}};
	output_num_array(num_array[1]);

	return 0;	
}