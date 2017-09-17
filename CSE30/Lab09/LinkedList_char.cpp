#include "LinkedList_char.h"
#include <iostream>
using namespace std;

LinkedList_char::LinkedList_char(){
	first = NULL;
	last = NULL;
}

LinkedList_char::~LinkedList_char(){
	clear();
}

void LinkedList_char::insertAtBack(char valueToInsert){
	Node* newNode = new Node();
	newNode->val = valueToInsert;
	newNode->next = NULL;

	if (first == NULL && last == NULL){
		first = newNode;
		last = newNode;
	}

	last->next = newNode;
	last = newNode;
}

bool LinkedList_char::removeFromBack(){
	if (first == NULL){
		return false;
	}

	if (first == last){
		delete first;
		first = NULL;
		last = NULL;
		return true;
	} else {
		Node* current = first;
		Node* secToLast;
		while (current->next != NULL){
			if (current->next == last){
				secToLast = current;
				break;
			}
			current = current->next;
		}
		delete last;

		last = secToLast;

		last->next = NULL;
	}
}

void LinkedList_char::print(){
	Node* curr = first;
	if (isEmpty()){
		return;
	}
	while (curr != last){
		cout << curr->val << ",";
		curr = curr->next;
	}
	cout << curr->val;
}

bool LinkedList_char::isEmpty(){
	return first == NULL;
}

int LinkedList_char::size(){
	if(isEmpty()){
		return 0;
	}

	int node_Counter = 1;
	Node* current = first;
	while (current->next != NULL){
		node_Counter++;
		current = current->next;
	}
	return node_Counter;
}

void LinkedList_char::clear(){
	if (first == NULL){
		return;
	}

	if (first == last){
		delete first;
		first = NULL;
		last = NULL;
	} else {
		Node* second = first->next;
		delete first;

		first = second;

		while (second != NULL){
			second = first->next;
			delete first;
			first = second;
		}
	}
}

void LinkedList_char::insertAtFront(char valueToInsert){
	Node* newNode = new Node();
	newNode->val = valueToInsert;
	newNode->next = first;

	if (first == NULL && last == NULL){
		first = newNode;
		last = newNode;
	}

	first = newNode;
}

bool LinkedList_char::removeFromFront(){
	if (first == NULL){
		return false;
	}

	if (first == last){
		delete []first;
		first = NULL;
		last = NULL;
		return true;
	} else {
		Node* temp = first->next;
		delete first;
		first = temp;
	}
}
