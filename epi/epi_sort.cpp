#include "epi_sort.h"



epi_sort::epi_sort()
{
}


epi_sort::~epi_sort()
{
}

void epi_sort::insertionSort(int arr[10])
{
	cout << "insertion Sort: " << endl;
	for (int i = 1; i < 10; i++) {
		int currentVaule = arr[i];
		int position = i;
		while (position > 0 && arr[position - 1] > currentVaule)
		{
			arr[position] = arr[position - 1];
			position -= 1;
		}
		arr[position] = currentVaule;
	}
	// print out the sorted list
	for (int j = 0; j < 10; j++) {
		cout << arr[j] << ", ";
	}
	cout << endl << endl;
}

void epi_sort::selectionSort(int arr[10])
{
	cout << "selection Sort: " << endl;
	int minValue_index = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			//cout << "compare: " << arr[j - 1] << " " << arr[j] << endl;
			if (arr[minValue_index] >= arr[j]) {
				minValue_index = j;
			}
		}	
		swap(arr[minValue_index], arr[i]);
		minValue_index = i + 1;
	}
	// print out the sorted list
	for (int j = 0; j < 10; j++) {
		cout << arr[j] << ", ";
	}
	cout << endl << endl;
}

void epi_sort::bubbleSort(int arr[10])
{
	cout << "bubble Sort: " << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 1; j < 10 - i; j++) {
			if (arr[j - 1] > arr[j]) {
				swap(arr[j - 1], arr[j]);
			}
		}
		cout << "pass count: " << i << endl;
	}

	for (int j = 0; j < 10; j++) {
		cout << arr[j] << ", ";
	}
	cout << endl << endl;

}

void epi_sort::shortBubbleSort(int arr[10])
{
	cout << "short bubble Sort: " << endl;
	int swap_count;
	for (int i = 0; i < 9; i++) {
		swap_count = 0;
		for (int j = 1; j < 10 - i; j++) {
			if (arr[j - 1] > arr[j]) {
				swap(arr[j - 1], arr[j]);
				swap_count++;
			}
		}
		cout << "pass count: " << i << endl;
		if (swap_count == 0) {
			cout << "array sorted" << endl;
			break;
		}		
	}

	for (int j = 0; j < 10; j++) {
		cout << arr[j] << ", ";
	}
	cout << endl << endl;
}



void epi_sort::quickSort(int arr[10])
{
	cout << "quick Sort: " << endl;
	int size = 10;
	int wall = 0;
	for (int i = 0; i < 10; i++) {
		int pivot = arr[size - 1];
		for (int j = 0; j < 10; j++) {
			if (pivot > arr[j]) {
				if (j != wall) {
					swap(arr[j], arr[wall]);
				}
				wall += 1;
			}
		}
		swap(arr[size - 1], arr[wall]);
		for (int j = 0; j < 10; j++) {
			cout << arr[j] << ", ";
		}
	}

	for (int j = 0; j < 10; j++) {
		cout << arr[j] << ", ";
	}
	cout << endl << endl;
}


