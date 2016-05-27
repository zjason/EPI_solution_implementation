#include "epi_sort.h"
#include "linkList.h"

int main() {
	// test case for sort algorithms
	epi_sort test;
	int arr1[10] = { 54, 26, 93, 17, 77, 31, 44, 55, 20, 7 };
	int arr2[10] = { 54, 26, 93, 17, 77, 31, 44, 55, 20, 7 };
	int arr3[10] = { 1, 2, 33, 4, 5, 6, 7, 8, 9, 10 };
	int arr4[10] = { 1, 2, 33, 4, 5, 6, 7, 8, 9, 10 };
	//test.insertionSort(arr);
	//test.selectionSort(arr);
	test.bubbleSort(arr3);
	test.shortBubbleSort(arr4);
	//test.quickSort(arr);
	
	// test case for linked list
	linkList list;
	int i = 0;
	while (i < 10) {
		list.addNode(i);
		i++;
	}
	list.addNodeAt(4, 20);
	list.printLinkList();
	list.deleteNode(5);
	list.printLinkList();
	list.deleteNodeAt(2);
	list.printLinkList();
	list.addNodeAt(5, 4);
	list.addNodeAt(5, 4);
	list.addNode(9);
	list.printLinkList();
	list.removeDup();
	list.printLinkList();
	return 0;
}