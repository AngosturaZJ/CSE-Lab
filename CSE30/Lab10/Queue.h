#ifndef _Queue_H
#define _Queue_H
#include "LinkedList.h"

class Queue : public LinkedList{
 public:
  Queue(); //constructor
  ~Queue(); //deconstructor
  void enqueue(int value); //insert value First In First Out (FIFO)
  int dequeue(); //print and remove the first value (FIFO)
  int& front(); //print the first value
};

#endif
