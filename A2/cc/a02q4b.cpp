#include "a02q4b.h"
#include <cmath>

#ifdef NDEBUG
#include <iostream>
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

int binary_branch_less(int *array, int start){
	int indice[start];
	int size = 0;
	int temp = start;
int a = 0;
	for (int i = 0;; i++){
		if (temp == 0) break;
		indice[i] = temp;
		temp = parent(temp);
		size++;
	}
	indice[size] = 0;
	size++;
for (int i = 0; i < size; i++){
	cout << indice[i] <<' ';
} cout << " | ";
for (int i = 0; i < size; i++){
	cout << array[indice[i]] <<' ';
} cout << endl;
	
	int low, high;
	low = 0;
	high = size -1;
	int pivot = 0;
	int islow = 0;
	int cur = 0;
	while(true){
		if (high < low) break;
		pivot = (high+low)/2;
		cur = indice[pivot];
		if (array[start] > array[cur]){
			low = pivot + 1;
			islow = 0;
a=1;
		} else if (array[start] < array[cur]){
			high = pivot - 1;
			islow = 1;
a=2;
		} else {
if(a == 0){
	cout << "EQ ";
} else if (a==1){
	cout << "GT ";
} else if (a==2){
	cout << "LT ";
}
			return cur;
		}
	}
if(a == 0){
	cout << "EQ ";
} else if (a==1){
	cout << "GT ";
} else if (a==2){
	cout << "LT ";
}
	return indice[pivot - islow];
}

void BubbleUp( int *array, int num_values, int start){
#if 1
	if (num_values <= 0) return;
	int index = binary_branch_less(array, start);
	int it = start;
	int par;
	int temp = array[start];
	while (it >= index){
//	while (true){
#if 0
		par = parent(it);
		swap(array, it, par);
		it = par;
#endif
		par = parent(it);
		if (temp <= array[par]) break;
		swap(array, it, par);
		if (par <= 0) break;
		it = par;
	}
if (it == index){
	cout << "OKAY" << endl;
} else {
cout << it << ' ' << index << endl;
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
	cout << j << endl;
#endif
}

#ifdef NDEBUG
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
#endif

// Insert data into array in max-heap order.
// Assume that the caller never tries to insert too many values.
void MaxHeap::Insert( int data )
{
	// implement me please
	// sure

Print();
cout << "Inserting:"<< data<< endl;
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
cout << " ------------- " << endl;
}

#if NDEBUG
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
#endif
