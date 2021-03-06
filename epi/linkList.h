#pragma once
#include <iostream>
using namespace::std;

class linkList
{
private:
	struct node {
		int data;
		node *next;
	};
	node *head;
	node *curr;
	node *temp;


public:
	linkList();
	~linkList();
	void addNode(int num);
	void addNodeAt(int position, int addData);
	void deleteNode(int num);
	void deleteNodeAt(int position);
	void printLinkList();
	

	// interview question
	// remove duplicates from link list
	void removeDup();
	bool hasCycle(node *head);
	void oddEvenList(node* head);
	void swapPairs(node* head);
	void addTwoNumbers(node* l1, node* l2);
	void reverseList();
};

