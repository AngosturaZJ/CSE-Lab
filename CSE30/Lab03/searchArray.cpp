#include <iostream>
using namespace std;

int linearSearch (int* arr, int search_num, int arr_size){
 //use linear search to find number
 for (int i = 0; i < arr_size; i++){
  if (arr[i] == search_num){
   //return the index of the number user want
   return i;
  }
 }
 // if the number user want is not in array, return -1
 return -1;
}

int main(){
 int arr_size;
 cout << "Enter the size of the array: ";
 cin >> arr_size;
 //check user's input
 if (arr_size > 0){
  int search_num;
  int* arr = NULL;
  arr = new int[arr_size];
  cout << "Enter the numbers in the array, separated by a space, and press enter: ";
  for (int i = 0; i < arr_size; i++){
   cin >> arr[i];
  }
  cout << "Enter a number to search for in the array: ";
  cin >> search_num;
  if (linearSearch(arr,search_num, arr_size) >= 0){
   cout << "Found value " << search_num << " at index " << linearSearch(arr, search_num, arr_size) << " which took " << int(linearSearch(arr, search_num, arr_size)+1) << " checks." << endl;
  }else{
   cout << "The value " << search_num << " was not found in the array!" << endl;
  }
  delete [] arr;
 } else{
  cout << "ERROR: you entered an incorrect value for the array size!" << endl;
 }
 return 0;
}
