#include "linkList.h"



linkList::linkList()
{
	head = nullptr;
	curr = nullptr;
	temp = nullptr;

}


linkList::~linkList()
{
}

void linkList::addNode(int addData)
{
	node* n = new node;
	n->data = addData;
	n->next = nullptr;

	if (head != nullptr) {
		curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = n;
	}else{
		head = n;
	}
}

void linkList::addNodeAt(int position, int addData)
{
	node* n = new node;
	curr = head;
	n->data = addData;
	int curr_postion = 1;
	if (position == 1) {
		n->next = head;
		head = n;
	} else {
		while (curr != nullptr && curr_postion < position) {
			temp = curr;
			curr = curr->next;
			curr_postion++;
		}
		temp->next = n;
		n->next = curr;
	}
}

void linkList::deleteNode(int delData)
{
	node* d = nullptr;
	temp = head;
	curr = head;
	if (head != nullptr) {
		while (curr->data != delData && curr != nullptr) {
			temp = curr;
			curr = curr->next;
		}
		if (curr == nullptr) {
			cout << "\n" << delData << " was not found in this link list.\n";
		} else {
			d = curr;
			curr = curr->next;
			temp->next = curr;
			delete d;
			cout << "\n" << delData << " was deleted from this link list.\n";
		}		
	}	
}

void linkList::deleteNodeAt(int position)
{

}


void linkList::printLinkList()
{
	curr = head;
	while (head != nullptr && curr != nullptr) {
		cout << "|" << curr->data << "|----->";
		curr = curr->next;
	}
}
