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

// add data to the linklist
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

// add data at certain position
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

// delete data from list
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

// delete data from certain position
void linkList::deleteNodeAt(int position)
{
	node* d = nullptr;
	temp = head;
	curr = head;
	int curr_pos = 1;
	if (head != nullptr) {
		while (curr_pos < position && curr != nullptr) {
			temp = curr;
			curr = curr->next;
			curr_pos++;
		}
		if (curr == nullptr) {
			cout << "\nposition: " << position << " out of index!\n";
		}else{
			d = curr;
			curr = curr->next;
			temp->next = curr;
			delete d;
			cout << "\nremoved node at " << position << " from link list!\n";
		}
	}

}

// print out the link list
void linkList::printLinkList()
{
	curr = head;
	while (head != nullptr && curr != nullptr) {
		cout << "|" << curr->data << "|----->";
		curr = curr->next;
	}
	cout << endl;
}

// remove duplicates from link list
void linkList::removeDup()
{
	node* curr_node = head;
	node * temp_node = head;
	if (head != nullptr) {
		while (curr_node != nullptr) {
			temp_node = curr_node;
			curr_node = curr_node->next;
			while (curr_node != nullptr && temp_node->data == curr_node->data) {
				node* d = nullptr;
				d = curr_node;
				curr_node = curr_node->next;
				temp_node->next = curr_node;
				cout << "delete duplicates " << d->data << " from link list!\n";
				delete d;
			}

		}
	}
}


