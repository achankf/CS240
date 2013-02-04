#include "a02q4b.h"

int parent(int i){
	return (i - 1) / 2;
}

void swap(int *array, int i, int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

// O(loglog n) comparisons to look for number of ancestors to be swapped
int num_ancestor_to_be_swapped(int *array, int start){
	int indice[start], size = 0, low, high, pivot;

	// construct an array of ancestors
	for (int i = 0, temp = start;; i++){
		if (temp == 0) break;
		indice[i] = temp;
		temp = parent(temp);
		size++;
	}
	indice[size] = low = pivot = 0;
	high = size;
	size++;

	// O(loglog n) comparisons to look for number of ancestors to be swapped
	while(true){
		pivot = (high+low)/2;
		if (high < low) break;
		if (array[start] > array[indice[pivot]]){
			low = pivot + 1;
		} else if (array[start] < array[indice[pivot]]){
			high = pivot - 1;
		} else {
			break;
		}
	}

	// O(1) for handling boundary case
	if (array[parent(indice[pivot])] < array[start]){
		return pivot + 1;
	}
	return pivot;
}

void BubbleUp( int *array, int start){
	int num = num_ancestor_to_be_swapped(array, start);
	int it = start, par;

	// O(log n) swap
	for (int i = 0; i < num; i++){
		par = parent(it);
		swap(array, it, par);
		it = par;
	}
}

// Insert data into array in max-heap order.
// Assume that the caller never tries to insert too many values.
void MaxHeap::Insert( int data ) {
	array[num_values] = data;
	BubbleUp(array, num_values);
	num_values++;
}
