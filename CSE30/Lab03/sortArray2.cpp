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
  int i, j, temp, max, swap_counter = 0;
  for (i = 0; i < arr_size - 1; i++) {
   max = i;
   for (j = i + 1; j < arr_size; j++)
    if (arr[max] < arr[j])
     max = j;
     swap_counter ++;
    temp = arr[max];
    arr[max] = arr[i];
    arr[i] = temp;
  }
  cout << "This is the sorted array in descending order: ";
  for (int k = 0; k < arr_size; k++){
   cout << arr[k] << " ";
  }
  delete [] arr;
  cout << "\nThe algorithm selected the maximum for the traverse of the array." << endl;
  cout << "It took " << swap_counter << " swaps to sort the array" << endl;
 }
 else{
  cout << "ERROR: you entered an incorrect value for the array size!" << endl; 
 }
 return 0;
}
