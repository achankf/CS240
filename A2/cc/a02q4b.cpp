#include "a02q4b.h"
#include <cmath>

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

#if 1
int binary_branch_less(int *array, int start){
	//int size = log(start)/log(2);
	int indice[start];

	int size = 0;
	int temp = start;
	for (int i = 0;; i++){
		if (temp == 0) break;
		indice[i] = temp;
		temp = parent(temp);
		size++;
	}
	if (size == 0) return 0;

	int low, high;
	low = 0;
	high = size;
	int pivot = 0;
	int islow = 0;
	int cur = 0;
	while(true){
		if (high < low) break;
		pivot = (high+low)/2;
		if (array[start] > array[indice[pivot]]){
			low = pivot + 1;
			islow = 0;
		} else if (array[start] < array[indice[pivot]]){
			high = pivot - 1;
		} else {
			return cur;
		}
	}
	//cout << "start:" << start << " cur:" << cur << endl;
	return cur;
}
#endif

void BubbleUp( int *array, int num_values, int start){
	if (num_values <= 0) return;
	int index = binary_branch_less(array, start);
#if 1
	int it = num_values - 1;
	int par;
	while (it > index){
		par = parent(it);
		swap(array, it, par);
		it = par;
	}
#endif
#if 0
	int temp = array[start];
	int i = start, j;
	while(true){
		j = parent(i);
		if (temp <= array[j]) break;
		swap(array, i, j);
		if (j <= 0) break;
		i = j;
	}
#endif
}

void BubbleDown( int *array, int num_values, int start){
	//if (start >= num_values) return;
	int temp = array[start];
	int i = start, compare;
	while(true){
		compare = left_child(i);
		//right = left + 1;
		if (compare >= num_values) break;
		if (compare + 1 < num_values && array[compare] < array[compare+1]){
			compare++;
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

	array[num_values] = data;
#if 1
	num_values++;
	BubbleUp(array, num_values, num_values-1);
#endif
#if 0
	BubbleUp(array, num_values, num_values);
	num_values++;
#endif
	Print();
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
//	Print();
	int temp_num = num_values;
	int temp[num_values];
	for (int i = 0; i < temp_num; i++){
		temp[i] = DeleteMax();
	}
	
	int prev = temp[0];
{
	int i = 0;
	while (true){
		cout << temp[i] << ' ';
		i++;
		if (i >= temp_num)
			break;
		if (prev < temp[i])
			throw "ERROR";
		prev = temp[i];
	}
}
	cout << endl;
}

void MaxHeap::Print(){
	for (int i = 0; i < num_values; i++){
		cout << array[i] << ' ';
	}
	cout << endl;
}
#endif
