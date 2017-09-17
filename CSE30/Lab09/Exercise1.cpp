#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
	Stack s1;

	// pushing 0 to 4 into the stack
	for (int i = 0; i < 4; ++i){
	  cout << "pushing " << i << "..." << endl;
	  s1.push(i);
	}

	// print the size of stack
	cout << "size: " << s1.size() << endl;

	// print all elements in the stack
	s1.print();
	cout << endl; // change to a new line

	// print the top of stack
	cout << "top: " << s1.top() << endl;

	// pop the last element 
	cout << "pop: " << s1.pop() << endl;
	
	// print all elements in the stack
	s1.print();
	cout << endl; // change to a new line

	// push 4, 4 and 5 into the stack
	cout << "pushing 4..." << endl;
	s1.push(4);
	for (int i = 4; i < 6; i++){
	  cout << "pushing " << i << "..." << endl;
	  s1.push(i);
	}

	cout << "size: " << s1.size() << endl;
	cout << "top: " << s1.top() << endl;
	s1.print();
	cout << endl;
	cout << "pop: " << s1.pop() << endl;
	s1.print();
	cout << endl;

	// push 6, 7, 8 and 8 into the stack
	for (int i = 6; i < 9; i++){
	  cout << "pushing " << i << "..." << endl;
	  s1.push(i);
	}
	cout << "pushing 8..." << endl;
	s1.push(8);

	s1.print();
	cout << endl;

	cout << "top: " << s1.top() << endl;
	cout << "pop: " << s1.pop() << endl;
	cout << "size: " << s1.size() << endl;

	s1.print();
	cout << endl;

	return 0;
}
