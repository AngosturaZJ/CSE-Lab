#include <iostream>
#include "Queue_char.h"
using namespace std;

int main(){
  Queue_char q2;

  cout << "dequeue():\t\t\t";
  //call dequeue
  try{
    q2.dequeue();
  }catch(int error){
    if (error == 0){
      cout << "Exception" << endl;
    }else if (error == 0){
      cout << "Error from front()" << endl;
    }
  }
  
  //insert D
  q2.enqueue('D');
  cout << "enqueue(D):\t\t\t \t\t\t";
  q2.print();
  cout << endl;

  //insert A
  q2.enqueue('A');
  cout << "enqueue(A):\t\t\t \t\t\t";
  q2.print();
  cout << endl;

  //remove
  cout << "dequeue():\t\t\t \t\t\t";
  q2.print();
  cout << "\n";

  //print the size of Queue
  cout << "size():\t\t\t\t" << q2.size() << "\t\t\t";
  q2.print();
  cout << endl;

  //insert D
  q2.enqueue('D');
  cout << "enqueue(D):\t\t\t \t\t\t";
  q2.print();
  cout << endl;

  //check Queue is empty or not
  cout << "isEmpty():\t\t\t" << q2.isEmpty() << "\t\t\t";
  q2.print();
  cout << endl;

  //print the first element of Queue
  cout << "frone():\t\t\t" << q2.front() << "\t\t\t";
  q2.print();
  cout << endl;

  //insert T
  q2.enqueue('T');
  cout << "enqueue(T):\t\t\t \t\t\t";
  q2.print();
  cout << endl;

  //print the first element of Queue
  cout << "front():\t\t\t" << q2.front() << "\t\t\t";
  q2.print();
  cout << endl;

  return 0;
}
