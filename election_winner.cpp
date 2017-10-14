//to do ellection winner
//I have to design a class i think
//there so much things to learn
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool doesExist (string voted, vector<string>tallybox) {
	vector<string>tallybox;
	// tallybox_with_name [votes.size()] .

	string temp;

	for (int i = 0; i < votes.size(); ++i) {
		if (!(doesExist(votes[i], tallybox))) {
			tallybox.push_back(votes[i]);
		}
		//then increment is no. of votes
		
	}

	for (string candidates: tallybox) {
		cout << candidates << endl;
	}

	//how  to determine a new name 
	//if it already exist in the the tallybox
	bool determiner = false;
	for (string candidate_name : tallybox) {
		if (candidate_name == voted)
		determiner = true;
	}
	return determiner;
}


int main () {
	vector<string> votes = {"Victor","Veronica","Ryan","Maria","Farah","Farah","Ryan","Veronica","Michael","Michael"};
	vector<string>tallybox;
	// tallybox_with_name [votes.size()] .

	string temp;

	for (int i = 0; i < votes.size(); ++i) {
		if (!(doesExist(votes[i], tallybox))) {
			tallybox.push_back(votes[i]);
		}
		//then increment is no. of votes

	}

	for (string candidates: tallybox) {
		cout << candidates << endl;
	}

	//how  to determine a new name 
	//if it already exist in the the tallybox

	return 0;
}