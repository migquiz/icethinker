//Actually this source code is not on the book
//This program is used to output lines of blank characters
//for renaming the icons on the desktop

/*************************
* Author : Miguel Quizon *
**************************/

#include <iostream>
#include <stdio.h>
using namespace std;

int main (int argc, char ** argv) {

	const char * filename = "shortcut.txt";
	const char * blank = "    ";

	FILE * file_write = fopen(filename,"w"); //create and open the file

	for (int y = 0; y <= 13 ; ++y) {
		for (int x = 0; x <= y; ++x) {
			fputs(" ",file_write); //write something on the file
		}
		fputs("\n", file_write);
	}

	fclose(file_write); //closes the file
	return 0;
}