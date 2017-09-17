#ifndef _STACK_H
#define _STACK_H

#include "LinkedList.h"
class Stack : public LinkedList{
 public:
  Stack();
  ~Stack();
  void push(int value);
  int pop();
  int& top();
};

#endif
