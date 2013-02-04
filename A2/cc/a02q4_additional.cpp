#include <iostream>
#include "a02q4b.h"
using namespace std;

void swap(int *array, int i, int j);

int left_child(int i){
	return 2*i + 1;
}

void BubbleDown( int *array, int num_values, int start){
	int temp = array[start];
	int i = start, compare;
	while(true){
		compare = left_child(i);
		if (compare >= num_values) break;
		if (compare + 1 < num_values && array[compare] < array[compare+1]){
			compare++;
		}
		if (temp > array[compare]) break;
		swap(array, i, compare);
		i = compare;
	}
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

MaxHeap::~MaxHeap(){
	cout << "Destroying heap" << endl;
	//Print();
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
		if (prev < temp[i]){
			cout << endl << "ERR "<<temp[i] << endl;
			throw "ERROR";
		}
		prev = temp[i];
	}
}
	cout << endl;
}

void MaxHeap::Tree(int i, int d){
	if (i >= num_values) return;
	Tree(left_child(i), d+1);
	for (int k = 0; k < d; k++){
		cout << "---";
	}
	cout << ' '<<array[i] << endl;
	Tree(left_child(i)+1, d+1);
}

void MaxHeap::Print(){
	if (!num_values) return;
	int prev = array[0];
	cout << "print: ";
	for (int i = 0;;){
		cout << prev << ' ';
		i++;
		if (i >= num_values) break;
		prev = array[i];
	}
	cout << endl;
}
bool MaxHeap::integ(int i){
	int left = left_child(i);
	if (i >= num_values || left >= num_values) return true;
	bool ret =array[i] > array[left] && integ(left);
	if (left + 1 >= num_values) return ret;
	return ret && array[i] > array[left+1] && integ(left+1);
}
