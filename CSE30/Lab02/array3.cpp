#include <iostream>
using namespace std;

int main(){
 int array_size;
 // ask user input a number for the size of array
 cout << "Enter the size of a 2D array:";
 cin >> array_size;
 //check the input number is in range of 1 to 10
 if (array_size >= 1 && array_size <= 10){
  // if the array size is in correct range, create a dynamic 2D array
  int ** array = new int* [array_size];
  // use variable count to count the numbers of negative numbers
  int count = 0;
  for (int i = 0; i < array_size; i++){
   array [i] = new int [array_size];
   cout << "Enter the values in the array for row " << int(i+1) << ", separated by a space, and press enter: ";
   for (int j = 0; j < array_size; j++){
    cin >> array[i][j];
    if (array[i][j] < 0){
     count++;
    }
   }
  }
  if (count > 0){
   cout << "There are " << count << " negative values!";
  }
  else {
   cout << "All values are non-negative!";
  }
  // delete array for preventing leak
  for(int i = 0; i < array_size; i++){
   delete [] array [i];
  }
  delete [] array;
 }
 // if the array size is bigger than 10, print error
 else if (array_size > 10){
  cout << "ERROR: your array is too large! Enter 1 to 10.";
 }
 // if the array size is negative, print error
 else{
  cout << "ERROR: you entered an incorrect value for the array size!";
 }
 return 0;
}
