#include <iostream>
#include "Queue.h"
using namespace std;

//constructor and inherit the LinkedList class
Queue::Queue():LinkedList(){}

//deconstructor
Queue::~Queue(){}

//insert a new value at the back of the Queue
void Queue::enqueue(int value){
  insertAtBack(value); //call function from LinkedList
}

//print and remove the first element of the Queue
int Queue::dequeue(){
  //exception; if the Queue is empty return true
  if (isEmpty()){
    return 1;
  }else{
    int removed_val = first->val;
    removeFromFront();
    return removed_val;
  }
}

int& Queue::front(){
  if(isEmpty()){
    throw 0;
  }else{
    return first->val;
  }
}
