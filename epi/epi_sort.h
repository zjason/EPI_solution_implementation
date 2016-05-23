#pragma once
#include <iostream>
#include <array>

using namespace std;

class epi_sort
{
public:
	epi_sort();
	~epi_sort();
	void insertionSort(int arr[10]);
	void selectionSort(int arr[10]);
	void bubbleSort(int arr[10]);
	void shortBubbleSort(int arr[10]);
	void quickSort(int arr[10]);
};

