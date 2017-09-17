#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
 string notReverse;
 // ask user to input a string
 cout << "Enter the string to reverse: " << endl;
 cin >> notReverse;
 // use for-loop to print string from the last letter to the first letter
 for (int i = notReverse.size()-1; i >= 0; i--){
  cout <<  notReverse.at(i);
 }
 return 0;
}
