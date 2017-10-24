//How to cheat a hangman
//some of the mechanisms of the game
//were changed. We're aiming the high
//difficulty of the game

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cstring>
using namespace std;

list<string> readWordFile(char * filename) {
	list<string> wordList;
	ifstream wordFile(filename, ios::in);
	if (wordFile == NULL) {
		cout << "File open failed." << endl;
		return wordList;
	}
	char currentWord[30];
	while (wordFile >> currentWord) { //successful write push words
		if (strchr (currentWord,'\'') == 0) {
			string temp (currentWord);
			wordList.push_back(temp);
		}
	}	
	return wordList;
}

void listDisplay (const list<string> & wordList) {
	list<string>::const_iterator iter;
	iter = wordList.begin();
	while (iter != wordList.end()) {
		cout << iter->c_str() << endl;
		++iter;
	}
}

int countWordsWithoutLetter (const list<string> & wordList, char letter) {
	list<string>::const_iterator iter;
	int count = 0;
	iter = wordList.begin();
	while (iter != wordList.end()) {
		if (iter->find(letter) == string::npos) {
			cout << *iter << " check" << endl;
			++count;
		}
		++iter;
	}
	return count;
}

void removeWordsofWrongLength (list<string> & wordList, int acceptableLength) {
	list<string>::iterator iter;
	iter = wordList.begin();
	while (iter != wordList.end()) {
		if (iter->length() != acceptableLength) {
			iter = wordList.erase(iter);
		} else {
			++iter;
		}
	}
}

void removeWordsWithoutLetter (list<string> & wordList, char requiredLetter) {
	list<string>::iterator iter;
	iter = wordList.begin();
	while (iter != wordList.end()) {
		if (iter->find(requiredLetter) == string::npos) { //npos position not found
			iter = wordList.erase(iter);
		} else {
			++iter;
		}
	}
}

bool numberInPattern (const list<int> & pattern, int number) {
	list<int>::const_iterator iter;
	iter = pattern.begin();
	while (iter != pattern.end()) {
		if (*iter == number) {
			return true;
		}
		++iter;
	}
	return false;
}

bool matchesPattern (string word, char letter, list<int> pattern) {
	for (int i = 0; i < word.length(); ++i) {
		if (word[i] == letter) {
			if (!numberInPattern(pattern, i)) {
				return false;
			}
		} else {
			if (numberInPattern(pattern, i)) {
				return false;
			}
		}
	}
	return true;
}

void mostFreqPatternByLetter (list<string> wordList, char letter, list<int> & maxPattern, int & maxPatternCount) {
	removeWordsWithoutLetter(wordList, letter);
	list<string>::iterator iter;
	maxPatternCount = 0;
	while (wordList.size() > 0) {
		iter = wordList.begin();
		list<int> currentPattern;
		for (int i = 0; i < iter->length(); i++) {
			if ((*iter)[i] == letter) {
				currentPattern.push_back(i);
			}
		}
		int currentPatternCount = 1;
		iter = wordList.erase(iter);
		while (iter != wordList.end()) {
			if (matchesPattern (*iter, letter, currentPattern)) {
				 currentPatternCount++;
				 iter = wordList.erase(iter);
			} else {
				iter++;
			}
		}
		if (currentPatternCount > maxPatternCount) {
			maxPatternCount = currentPatternCount;
			maxPattern = currentPattern;
		}
		currentPattern.clear();
	}
}

void displayGuessedLetters(bool letter[26]) {
	cout << "Letters Guessed: ";
	for (int i = 0; i < 26; ++i) {
		if (letter[i]) cout << (char) ('a'+ i) << " ";
	}
	cout << endl;
}

int main (int argc, char ** argv) {
	const int wordLength = 8;
	const int maxMisses = 9;
	
	int misses = 0;
	int discoveredLetterCount = 0;
	
	char * filename = new char [6];
	filename = "words";
	
	list<string> wordList = readWordFile (filename);
	
	removeWordsofWrongLength(wordList,wordLength);
	
	char revealedWord[wordLength + 1] = "********";
	bool guessedLetters[26];
	
	for (int i = 0; i < 26; ++i) guessedLetters[i] = false;
	
	char nextLetter;
	
	cout << "Word so Far: " << revealedWord << endl;

	//main game loop
	while (discoveredLetterCount < wordLength && misses < maxMisses) {
		cout << "Letter to guess: ";
		cin >> nextLetter;

		guessedLetters[nextLetter - 'a'] = true;

		int missingCount = countWordsWithoutLetter(wordList, nextLetter);

		list<int> nextPattern;
		int nextPatternCount;

		mostFreqPatternByLetter (wordList, nextLetter, nextPattern, nextPatternCount);
		if (missingCount > nextPatternCount) {
			removeWordsWithLetter (wordList, nextLetter);
			misses++;
		} else {
			list<int>::iterator iter  = nextPattern.begin();
			while (iter != nextPattern.end()) {
				discoveredLetterCount++;
				revealedWord[*iter] = nextLetter;
				iter++;
			}
			wordList = reduceByPattern(wordList, nextLetter, nextPattern);
		}
		cout << "Word so far: " << revealedWord << endl;
		displayGuessedLetters(guessedLetters);
	}

	return 0;
}