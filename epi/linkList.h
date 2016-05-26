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
};

