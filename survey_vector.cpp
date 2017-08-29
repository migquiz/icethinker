//Vector is a "smarter version" of array in cpp
//This program uses the vector class from 
//the standard library

/*************************
* Author : Miguel Quizon *
**************************/

#include <iostream>
#include <vector>
using namespace std;

int main (int argc, char ** argv) {

	vector<int> surveyData;

	surveyData.reserve(30); //inefficiency in space

	int surveyResponse;

	cout << "Enter next survey response or -1 to end: ";
	cin >> surveyResponse;

	while (surveyResponse != -1) {
		//declare the histogram here
		//then as the user inputs
		//histogram[surveryResponnse - 1]++
		//eval as user inputs
		surveyData.push_back(surveyResponse); 
		cout << "Enter next survey response or -1 to end: ";
		cin >> surveyResponse;
	}

	int vectorSize = surveyData.size();
	const int MAX_RESPONSE = 10;
	int histogram[MAX_RESPONSE] = {0};

	for (int i = 0; i < vectorSize; ++i) {
		histogram[surveyData[i] - 1]++; //storing /increment the box with the his/her name on it.
		//sometime answers first then the condition
		//vector inefficiency in access
	}

	int mostFrequent = 0;

	for (int i = 0; i < MAX_RESPONSE; i++) {
		if (histogram[i] > histogram[mostFrequent]) {
			mostFrequent = i;
		}
	}

	mostFrequent++;

	cout << "Most Frequent: " << mostFrequent << endl;

	return 0;
}
