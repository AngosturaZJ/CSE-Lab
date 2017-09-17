#include <iostream>
#include "Stack.h"
using namespace std;

// constructor
Stack::Stack():LinkedList(){}

// deconstructor
Stack::~Stack(){}

// insert element into Stack
void Stack::push(int value){
  // call inserAtBack() function from LinkedList.cpp
  insertAtBack(value);
}

//print and remove the last element from Stack
int Stack::pop(){
  // store the last element into removedVal
  int removedVal = last->val;
  // remove the last element from Stack
  removeFromBack();
  return removedVal;
}

// print the last element from Stack
int& Stack::top(){
  return last->val;
}
