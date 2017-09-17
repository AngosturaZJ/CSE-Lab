#include <iostream>
using namespace std;

void sortArr(int choice, int *a, int size){
	// ascending order
	if (choice == 0){
		for (int i = 1; i < size; i++){
			int cur = a[i];
			int j = i - 1;
			while (j >= 0 && a[j] > cur){
				a[j + 1] = a[j];
				j = j - 1;
			}
			a[j + 1] = cur;
		}
	}else{
		// descending order
		for (int i = 1; i < size; i++){
			int cur = a[i];
			int j = i - 1;
			while (j >= 0 && a[j] < cur){
				a[j + 1] = a[j];
				j = j - 1;
			}
			a[j + 1] = cur;
		}
	}
}	

int main(){
	int choice, size;
	cout << "Enter the size of the array:";
	cin >> size;
	// use if-else statement to check the size of array
	if (size > 0){
		int *arr = NULL;
		arr = new int[size];
		cout << "Enter the numbers in the array, separated by a space, and press enter:";
		// use for-loop read in user's inputs
		for (int i = 0; i < size; ++i){
			cin >> arr[i];
		}
		cout << "Sort in ascending (0) or descending (1) order? ";
		cin >> choice;
		// call function
		sortArr(choice, arr, size);
		// check user's choice and print out different statement
		if (choice == 0){
			cout << "This is the sorted array in ascending order: ";
		}else{
			cout << "This is the sorted array in descending order: ";
		}
		// print out corresponding sorted array
		for (int k = 0; k < size; k++){
			cout << arr[k] << " ";
		}
		// delete the array
		delete [] arr;
	}else{
		// when the size of array is incorrect
		cout << "ERROR: you entered an incorrect value for the array size!" << endl;
	}
	return 0;
}