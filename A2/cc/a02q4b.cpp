#include "a02q4b.h"

#ifdef NDEBUG
#include <iostream>
#include <cassert>
using namespace std;
#endif

int parent(int i){
	int temp = (i - 1) / 2;
	return temp > 0 ? temp : 0;
}

int left_child(int i){
	return 2*i + 1;
}

void swap(int *array, int i, int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void BubbleUp( int *array, int start){
	int temp = array[start];
	int i = start, j;
	while(true){
		j = parent(i);
		if (temp <= array[j]) break;
		swap(array, i, j);
		if (j <= 0) break;
		i = j;
	}
}
void BubbleDown( int *array, int num_values, int start){
	int temp = array[start];
	int i = start, left, right, compare;
	while(true){
		left = left_child(i);
		right = left + 1;
		if (left >= num_values) break;
		compare = left;
		if (right < num_values && array[left] < array[right]){
			compare = right;
		}
		if (temp > array[compare]) break;
		swap(array, i, compare);
		i = compare;
	}
}

// Insert data into array in max-heap order.
// Assume that the caller never tries to insert too many values.
void MaxHeap::Insert( int data )
{
	// implement me please
	// sure

#ifdef NDEBUG
	assert(num_values < array_sz);
#endif
	array[num_values] = data;
	BubbleUp(array, num_values);
	num_values++;
}


// Delete the max value from the heap and return that value.
// Assume that the caller 
int MaxHeap::DeleteMax()
{
	// implement me please
	// sure

	int ret = array[0];
	num_values--;
	array[0] = array[num_values];
	BubbleDown(array,num_values,0);
	return ret;
}

#ifdef NDEBUG
MaxHeap::~MaxHeap(){
	cout << "Destroying heap" << endl;
	int temp_num = num_values;
	int temp[num_values];
#if 1
	for (int i = 0; i < temp_num; i++){
		temp[i] = DeleteMax();
		Print();
	}
	
	for (int i = 0; i < temp_num; i++){
		cout << temp[i] << ' ';
	}
	cout << endl;
#endif
}

void MaxHeap::Print(){
	for (int i = 0; i < num_values; i++){
		cout << array[i] << ' ';
	}
	cout << endl;
}
#endif
