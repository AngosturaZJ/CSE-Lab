#include <iostream>
#include "LinkedList_char.h"
using namespace std;

LinkedList_char::LinkedList_char()
{
	first = NULL;
	last = NULL;
}

LinkedList_char::~LinkedList_char()
{
	// delete all nodes
	clear();
}

void LinkedList_char::insertAtBack(char newValue)
{
	// create a new node
	Node* newNode = new Node();
	newNode->val = newValue;
	newNode->next = NULL; // this is the last node

	// if the Linked list is empty
	if (first == NULL && last == NULL){
		first = newNode;
		last = newNode;
	}

	// if the Linked list has nodes
	last->next = newNode; // old last-node points to new last-node
	last = newNode; // make newNode become the last node
}

bool LinkedList_char::removeFromBack()
{
	// if there is no node
	if (first == NULL){
		return false;
	}
	// if there is only one node
	if (first == last){
		delete first;
		first = NULL;
		last = NULL;
		return true;
	}
	// if there are more than one node
	else{
		// find second to last node
		Node* current = first;
		Node* secTolast;
		while (current->next != NULL){
			if (current->next == last){
				secTolast = current;
				break;
			}
			current = current->next;
		}
		delete last; // remove the last node
		last = secTolast; // make second to last node becomes last node
		last->next = NULL; // last node always points to NULL
	}
}

void LinkedList_char::print()
{
	// if there is no node
	if (first == NULL){
		return;
	}

	// in normal case
	Node* current = first;
	while (current != last){
		cout << current->val << ",";
		current = current->next;
	}
	cout << last->val;
}

bool LinkedList_char::isEmpty()
{
	return first == NULL;
}

int LinkedList_char::size()
{
	if (isEmpty()){
		// if there is no node
		return 0;
	}else{
		// if there is one or more node
		int counter = 1;
		Node* current = first;
		while (current->next != NULL){
			counter++;
			current = current->next;
		}
		return counter;
	}
}

void LinkedList_char::clear()
{
	// if there is no node
	if (first == NULL){
		return;
	}else if (first == last){ // if there is only one node
		delete first;
		first = NULL;
		last = NULL;
	}else{
		Node* secNode = first->next;
		delete first;
		first = secNode;
		while (secNode != NULL){
			secNode = first->next;
			delete first;
			first = secNode;
		}
	}
}

void LinkedList_char::insertAtFront(char valueToInsert)
{
	Node* newNode = new Node();
	newNode->val = valueToInsert;
	newNode->next = first;

	// if there is no node
	if (first == NULL && last == NULL){
		first = newNode;
		last = newNode;
	}else{ //in normal case
		first = newNode;
	}
}

bool LinkedList_char::removeFromFront()
{
	if (isEmpty()){
		return false;
	}else if (first == last){
		delete first;
		first = NULL;
		last = NULL;
		return true;
	}else{
		Node* oldNode = first;
		first = oldNode->next;
		delete oldNode;
	}
}
