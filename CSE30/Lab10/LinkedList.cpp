#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	first = NULL;
	last = NULL;
}

LinkedList::~LinkedList()
{
	// delete all nodes
	clear();
}

void LinkedList::insertAtBack(int newValue)
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

bool LinkedList::removeFromBack()
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

void LinkedList::print()
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

bool LinkedList::isEmpty()
{
	return first == NULL;
}

int LinkedList::size()
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

void LinkedList::clear()
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

void LinkedList::insertAtFront(int valueToInsert)
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

bool LinkedList::removeFromFront()
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
