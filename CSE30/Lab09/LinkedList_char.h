#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

struct Node
{
	char val;
	Node* next;
	
};

class LinkedList_char{
	public:
		LinkedList_char();
		~LinkedList_char();
		void insertAtBack(char valueToInsert);
		bool removeFromBack();
		void print();
		bool isEmpty();
		int size();
		void clear();
		void insertAtFront(char valueToInsert);
		bool removeFromFront();

	protected:
		Node *first;
		Node *last;
};

#endif
