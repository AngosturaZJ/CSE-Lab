#include <iostream>
#include "Queue.h"
using namespace std;

int main(){
  Queue q1;

  cout << "Call front(): ";
  try{
    q1.front();
  }catch (int error){
    if (error == 0){
      cout << "Exception" << endl;
    }else if (error == 1){
      cout << "Error from front()\n";
    }
  }

  cout << "Inserting integer numbers..." << endl;
  //insert numbers 0 to 9
  for (int i = 0; i < 10; i++){
    q1.enqueue(i);
  }

  cout<< "The enqueue containing: ";
  //print the whole queue
  q1.print();
  cout << endl;

  //print out the size of Queue
  cout << "The size of the queue is " << q1.size() << endl;

  //call front()
  cout << "The front value of queue is " << q1.front() << endl;

  //remove a value
  cout << "The value dequeue from queue is " << q1.dequeue() << endl;

  //print out the size of Queue
  cout << "The size of queue is " << q1.size() << endl;

  cout << "Finally, the enqueue containing: ";
  //print the whole queue
  q1.print();
  cout << endl;

  return 0;
}
