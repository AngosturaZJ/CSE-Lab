#include <iostream>
using namespace std;

void sortArr(int choice, int *a, int size){
	int max, mini, temp;
	// ascending order
	if (choice == 0){
		for (int i = 0; i < size - 1; i++){
			mini = i;
			for (int j = i + 1; j < size; j++){
				if (a[mini] > a[j]){
					mini = j;
				}
			}
			temp = a[mini];
			a[mini] = a[i];
			a[i] = temp;
		}
	}else{
		// descending order
		for (int i = 0; i < size -1; i++){
			max = i;
			for (int j = i + 1; j < size; j++){
				if (a[max] < a[j]){
					max = j;
				}
			}
			temp = a[max];
			a[max] = a[i];
			a[i] = temp;
		}
	}
}	

int main(){
	int choice, size;
	cout << "Enter the size of the array:";
	cin >> size;
	// check the size of array
	if (size > 0){
		// create an array
		int *arr = NULL;
		arr = new int[size];
		cout << "Enter the numbers in the array, separated by a space, and press enter:";
		// use for-loop read in user's inputs
		for (int i = 0; i < size; ++i){
			cin >> arr[i];
		}
		cout << "Sort in ascending (0) or descending (1) order? ";
		cin >> choice;
		sortArr(choice, arr, size);
		// check user's choice and print out different statement
		if (choice == 0){
			cout << "This is the sorted array in ascending order: ";
		}else{
			cout << "This is the sorted array in descending order: ";
		}
		for (int k = 0; k < size; k++){
			cout << arr[k] << " ";
		}
		// delete the array
		delete [] arr;
	}else{
		cout << "ERROR: you entered an incorrect value for the array size!" << endl;
	}
	return 0;
}