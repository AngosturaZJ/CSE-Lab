#ifndef _Queue_H
#define _Queue_H
#include "LinkedList_char.h"

class Queue_char : public LinkedList_char{
 public:
  Queue_char(); //constructor
  ~Queue_char(); //deconstructor
  void enqueue(char value); //insert element First In First Out (FIFO)
  char dequeue(); //print and remove the first element (FIFO)
  char& front(); //print the first element
};

#endif
