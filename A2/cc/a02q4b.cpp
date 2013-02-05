#include "a02q4b.h"
#include "cmath"

// O(1) comparison
int parent(int i){
	return (i - 1) / 2;
}

// O(1) comparison
void swap(int *array, int i, int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

// O(loglog n) comparisons to look for number of ancestors to be swapped
int num_ancestor_to_be_swapped(int *array, int start){
	if (start == 0) return 0;

	int high = (log(start +1)/log(2));
	int cur = start;
	int low, pivot;
	low = pivot = 0;

	// binary search on a branch of heap -- O(lglg n) comparisions
	while(true){
		pivot = (high+low)/2;
		int power = pow(2,pivot);
		cur = (start - power + 1) / power;
		if (high < low) break;
		if (array[start] > array[cur]){
			low = pivot + 1;
		} else if (array[start] < array[cur]){
			high = pivot - 1;
		} else {
			break;
		}
	}

	// pivot + boundary case adjustment -- O(1) comparison
	return pivot + (array[parent(cur)] < array[start]);
}

// O(lglg n) due to num_ancestor_to_be_swapped
void BubbleUp( int *array, int start){
	int num = num_ancestor_to_be_swapped(array, start);
	int it = start, par;

	// O(log n) swap -- O(1) comparison
	for (int i = 0; i < num; i++){
		par = parent(it);
		swap(array, it, par);
		it = par;
	}
}

// O(lglg n) due to num_ancestor_to_be_swapped -> BubbleUp
void MaxHeap::Insert( int data ) {
	array[num_values] = data;
	BubbleUp(array, num_values);
	num_values++;
}
