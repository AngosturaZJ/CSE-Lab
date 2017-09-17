#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

template<class T>
class Stack : public LinkedList<T>{
 public:
  Stack();
  ~Stack();
  void push(T value);
  T pop();
  T& top();
};

template<class T>
// constructor
Stack<T>::Stack(){}

template<class T>
// deconstructor
Stack<T>::~Stack(){}

template<class T>
// insert element into Stack
void Stack<T>::push(T value){
  // call inserAtBack() function from LinkedList.cpp
  LinkedList<T>::insertAtBack(value);
}

template<class T>
//print and remove the last element from Stack
T Stack<T>::pop(){
  // store the last element into removedVal
  T removedVal = LinkedList<T>::last->val;
  // remove the last element from Stack
  LinkedList<T>::removeFromBack();
  return removedVal;
}

template<class T>
// print the last element from Stack
T& Stack<T>::top(){
  return LinkedList<T>::last->val;
}

#endif
