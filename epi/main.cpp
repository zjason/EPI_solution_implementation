#include "epi_sort.h"

int main() {
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
	return 0;
}