#include <iostream>
using namespace std;

int main(){
 int arr_size;
 cout << "Enter the size of the array: ";
 cin >> arr_size;
 if (arr_size > 0){
 // if the input number is correct, create an array
  int* arr = NULL;
  arr = new int[arr_size];
  cout  << "Enter the numbers in the array, separated by a space, and press enter : ";
  // use for-loop to read in numbers and save into the array
  for (int i = 0; i < arr_size; i++){
   cin >> arr[i];
  }
  // use selection sort
  int i, j, temp, min;
  for (i = 0; i < arr_size - 1; i++) {
   min = i;
   for (j = i + 1; j < arr_size; j++)
    if (arr[min] > arr[j])
     min = j;
    temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
  }
  cout << "This is the sorted array in ascending order: ";
  for (int k = 0; k < arr_size; k++){
   cout << arr[k] << " ";
  }
  delete [] arr;
  cout << "\nThe algorithm selected the minimum for the traverse of the array." << endl;
 }
 else{
  cout << "ERROR: you entered an incorrect value for the array size!" << endl; 
 }
 return 0;
}
