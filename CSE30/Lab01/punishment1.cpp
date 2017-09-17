#include <iostream>
using namespace std;

int main()
{
 int loop_num;
 cout << "Enter the number of lines for the punishment:";
 cin >> loop_num;
 if (loop_num >= 0){
  for (int i = 0; i < loop_num; i++){
   cout << "I will always use object oriented programming.";
  }
 }else{
  cout << "You entered an incorrect value for the number of lines!";
 }
 return 0;
}
