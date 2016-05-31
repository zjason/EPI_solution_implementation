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
// edge case: index = 0, need to point head to new head
void linkList::deleteNodeAt(int position)
{
	node* d = nullptr;
	temp = head;
	curr = head;
	int curr_pos = 0;
	if (head != nullptr) {
		if (position == 0) {
			d = curr;
			curr = curr->next;
			delete d;
			head = curr;
			return;
		}
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

// check if the link list has cycle or not
// walker will move through this link list one by one
// runner will mvoe through this link list two at a time
// if this linked list has cycle, then runner will catch up walker sooner or later
bool linkList::hasCycle(node * head)
{
	node* runner;
	node* walker;
	runner = head;
	walker = head;
	if (head != nullptr) {
		while (runner->next != nullptr && runner->next->next != nullptr) {
			walker = walker->next;
			runner = runner->next->next;
			if (runner == walker) {
				return true;
			}
		}
	}
	return false;
}

// space complexity is O(1), time complexity is O(n)
// create three pointer that odd point to odd node; even point to even node
// evenhead point to the head of even list
// after go through the linked list, odd sublist and even sublist are created
// then link the last node in odd sublist to evenhead
void linkList::oddEvenList(node * head)
{
	if (head != nullptr) {
		node *odd, *even, *evenhead;
		odd = head;
		even = head->next;
		evenhead = head->next;
		while (odd->next != nullptr && even->next != nullptr) {
			odd->next = even->next;
			odd = odd->next;
			even->next = odd->next;
			even = even->next;
		}
		odd->next = evenhead;
	}
}

void linkList::swapPairs(node * head)
{
	node *curr, *temp;
	node *dummy = new node();
	temp = head;
	curr = head;
	bool change = true;
	if (head != nullptr) {
		if (head->next == nullptr) {
			return ;
		}
		if (head->next->next == nullptr) {
			curr = curr->next;
			temp->next = curr->next;
			curr->next = temp;
			head = curr;
			return ;
		}
		head = head->next;
		curr = curr->next;
		while (curr != nullptr) {
			if (change == true) {
				temp->next = curr->next;
				curr->next = temp;
				dummy = temp;
				change = false;
			}
			else {
				if (temp->next != nullptr && temp->next->next != nullptr) {
					temp = temp->next;
					curr = temp->next;
					dummy->next = curr;
					change = true;
				}
				else {
					break;
				}
			}
		}
	}
}

void linkList::addTwoNumbers(node * l1, node * l2)
{

}

// reverse linked list by iterator through the whole list
// edge case: list is empty
// edge case: list only contain one item
void linkList::reverseList()
{
	cout << "befor reverse:" << endl;
	printLinkList();
	node *curr, *temp;
	curr = head;
	temp = head;

	if (head != nullptr) {
		if (curr->next == nullptr) {
			return;
		}

		curr = curr->next;
		temp->next = nullptr;
		while (curr->next != nullptr) {
			temp = curr;
			curr = curr->next;
			temp->next = head;
			head = temp;
		}
		head = curr;
		curr->next = temp;
	}
	cout << "result: " << endl;
	printLinkList();
	return ;
}