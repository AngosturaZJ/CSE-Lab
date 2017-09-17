#include <iostream>
#include "Queue_char.h"
using namespace std;

//constructor and inherit the LinkedList class
Queue_char::Queue_char():LinkedList_char(){}

//deconstructor
Queue_char::~Queue_char(){}

//insert a new element at the back of the Queue
void Queue_char::enqueue(char value){
  insertAtBack(value); //call function from LinkedList
}

//print and remove the first element of the Queue
char Queue_char::dequeue(){
  //exception; if the Queue is empty return true
  if (isEmpty()){
    throw 0;
  }else{
    char removed_char = first->val;
    removeFromFront();
    return removed_char;
  }
}

char& Queue_char::front(){
  if(isEmpty()){
    throw 1;
  }else{
    return first->val;
  }
}
