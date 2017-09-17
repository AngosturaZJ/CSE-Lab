#include "Stack_char.h"
#include <iostream>
using namespace std;

// constructor
Stack_char::Stack_char(){}

// deconstructor
Stack_char::~Stack_char(){}

// insert a char into Stack
void Stack_char::push(char value){
	insertAtBack(value);
}

// print and remove the last element from Stack
char Stack_char::pop(){
	char removed_value = last->val;

	removeFromBack();

	return removed_value;
}

// print the last element from Stack
char& Stack_char::top(){
	return last->val;
}
