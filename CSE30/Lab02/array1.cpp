#include <iostream>
using namespace std;

// check whether the array is increasing or not
bool isIncrease(int* arr, int arr_size){
 for (int i = 1; i < arr_size; i++){
  if (arr[i - 1] > arr[i]){
   return false;
  }
 }
 return true;
}

int main(){
 int arr_size;
 cout << "Enter the size of the array: ";
 cin >> arr_size;
 // check whether the input number is correct or not
 if (arr_size > 0){
 // if the input number is correct, create an array
  int* arr = NULL;
  arr = new int[arr_size];
  cout  << "Enter the numbers in the array, separated by a space, and press enter : ";
  // use for-loop to read in numbers and save into the array
  for (int i = 0; i < arr_size; i++){
   cin >> arr[i];
  }
  // use isIncreasing function to check the array is increasing or not
  if (isIncrease(arr, arr_size) != false){
   cout << "This IS an increasing array!" << endl;
  }
  else{
   cout << "This is NOT an increasing array!" << endl;
  }
  // print out numbers
  for (int i = 0; i < arr_size; i++){
   cout << arr[i] << " ";
  }
  delete [] arr;
 }
 else{
  cout << "ERROR: you entered an incorrect value for the array size!" << endl;
 }
 return 0;
}
