#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

// Representation of an element in the linked list
template<class T>
struct Node
{
    T val; // Value of the node
    Node *next; // Pointer to the next node
};

template<class T>
class LinkedList
{
    // Public Functions/Variables
    public:
        /* IMPLEMENT THESE FUNCTIONS FOR EXERCISE1 */
        LinkedList(); // Constructor
        ~LinkedList(); // Destructor
        void insertAtBack(T valueToInsert);
        bool removeFromBack();
        void print();
        bool isEmpty();
        int size();
        void clear();

        /* IMPLEMENT THSES FUNCTIONS FOR EXERCISE2 */
        void insertAtFront(T valueToInsert);
        bool removeFromFront();

        Node<T> *first; // Pointer pointing to the begining of the list
        Node<T> *last; // Pointer pointing to the end of the list
};

// Implement your functions here:
template<class T>
LinkedList<T>::LinkedList(){
  first = NULL;
  last = NULL;
}

template<class T>
LinkedList<T>::~LinkedList(){
  clear();
}

template<class T>
void LinkedList<T>::insertAtBack(T valueToInsert){
  //create a new node
  Node<T>* newNode = new Node<T>();
  newNode->val = valueToInsert;
  newNode->next = NULL; //newNode is the last node
  //if there is no node at all
  if (first == NULL){
    first = newNode;
    last = newNode;
  }else{ //normal case
    last->next = newNode;
    last = newNode;
  }
}

template<class T>
bool LinkedList<T>::removeFromBack(){
  //if there is no node
  if (first == NULL){
    return false;
  }else if (first == last){ //if there is only one node
    delete first;
    first = NULL;
    last = NULL;
    return true;
  }else{ //normal case
    Node<T>* current = first;
    Node<T>* secLast;
    //find second to last node
    while (current != last){
      secLast = current;
      current = current->next;
    }
    delete last;
    last = secLast;
    last->next = NULL;
  }
}

template<class T>
void LinkedList<T>::print(){
  if (isEmpty()){
    return;
  }else{
    Node<T>* current = first;
    while (current != last){
      cout << current->val << ",";
      current = current->next;
    }
    cout << current->val;
  }
}

template<class T>
bool LinkedList<T>::isEmpty(){
  return first == NULL;
}

template<class T>
int LinkedList<T>::size(){
  if (isEmpty()){
    return 0;
  }else{
    int counter = 0;
    Node<T>* current = first;
    while (current != last){
      counter++;
      current = current->next;
    }
    return counter;
  }
}

template<class T>
void LinkedList<T>::clear(){
  if (isEmpty()){
    return;
  }else if (first == last){
    delete first;
    first == NULL;
    last == NULL;
  }else{
    Node<T>* lead = first->next;
    
    while (lead != NULL){
      delete first;
      first = lead;
      lead = lead->next;
    }
    delete first;
    first = NULL;
    last = NULL;
  }
}
    
template<class T>
void LinkedList<T>::insertAtFront(T valueToInsert){
  Node<T>* newNode = new Node<T>();
  newNode->val = valueToInsert;
  newNode->next = first;
  if(isEmpty()){
    first = newNode;
    last = newNode;
    return;
  }
  first = newNode;
}

template<class T>
bool LinkedList<T>::removeFromFront(){
  if (isEmpty()){
    return false;
  }else if (first == last){
      delete first;
      first = NULL;
      last = NULL;
  }else{
    Node<T>*second = first->next;
    delete first;
    first = second;
  }
}

#endif

