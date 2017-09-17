#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main() { 
	ifstream lab_5;
	lab_5.open("words_in.txt");
	string line; 
	int ind = 0;

	// counting for number of lines
	if( lab_5.is_open() ) { 
		while( !lab_5.eof() ) {
	 	getline(lab_5, line);
		ind++;
		}
	} 
	lab_5.close();

	// create array for storing
    string* arr = new string[ind];
    int j=0;
	lab_5.open("words_in.txt");
	// storing each line to array
	if( lab_5.is_open() ) { 
		while( !lab_5.eof() ) {
	 		getline(lab_5, line);
			arr[j++] = line;
		}
	} 
	lab_5.close();

	// copy to "words_out.txt"
	ofstream lab_5_1;
	lab_5_1.open("words_out.txt");
	for (int i = 0; i < ind; i++){
	lab_5_1 << arr[i] << endl;
	} lab_5_1.close();
}
