#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
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

int binarySearchR (string* arr, int first, int last, string value){
    if (first>last){
        cout<<"The key " << value << " was not found in the array!"<<endl;
        return-1;
    }
	int mid = (first+last)/2;
    if(arr[mid]==value){
        cout << "Found key " << value << " at index " << mid << "!"<<endl;
    } else if(arr[mid]<value){
        return binarySearchR(arr, mid+1, last, value);
    } else if(arr[mid]>value){
       return binarySearchR(arr, first, mid-1, value);
    }
}

int main(){
	ifstream lab_5;
	lab_5.open("words_in.txt");
	string line; 
	int ind = 0;
	
	if( lab_5.is_open() ) { 
		while( !lab_5.eof() ) {
	 	getline(lab_5, line);
		ind++;
		}

	} lab_5.close();
        string* arr = new string[ind];
        int j=0;
	lab_5.open("words_in.txt");
		if( lab_5.is_open() ) { 
		while( !lab_5.eof() ) {
	 	getline(lab_5, line);
		arr[j++] = line;
		}
	} lab_5.close();
	if (checkArraySort(arr, j) != 0){
		string value;
		int first =0;
		int last =ind-1;
		cout << "Enter input search key"<< endl;
		cin >> value;
		string index;
		index = binarySearchR(arr, first, last, value);
	}else{
		cout << "The array is not sorted!" << endl;
	}
}