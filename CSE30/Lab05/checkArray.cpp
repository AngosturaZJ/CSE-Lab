#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// use checkArraySort function to check
int checkArraySort(string *A, int array_size){
	int decreaseNum = 0;
	int increaseNum = 0;
	int result;
	for (int i = 0; i < array_size - 1; i++){
			if (A[i] < A[i+1]){
				increaseNum ++;
			}else{
				decreaseNum ++;
			}
	}
	if (decreaseNum == array_size - 1){
		result = -1;
	}else if (increaseNum == array_size - 1){
		result = 1;
	}else{
		result = 0;
	}
	return result;
}

int main(){
	ifstream lab_5;
	string line;
	int number = -1;
	// counting for number of lines
	lab_5.open("words_in.txt");
	while (!lab_5.eof()){
		getline(lab_5, line);
		number++;
	}
	lab_5.close();
	string *array = new string [number];
	// storing each lines into array
	lab_5.open("words_in.txt");
	for (int i = 0; i < number; i++){
		getline(lab_5, line);
		array[i] = line;
	}
	if (checkArraySort(array, number) == 1){
		cout << "The array is sorted in ascending order!" << endl;
	}else if (checkArraySort(array, number) == -1){
		cout << "The array is sorted in descending order!" << endl;
	}else{
		cout << "The array is not sorted" << endl;
	}
	delete [] array;
	return 0;
}
