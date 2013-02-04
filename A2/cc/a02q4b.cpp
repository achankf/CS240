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
	for (int i = 0;; i++){
		if (temp == 0) break;
		indice[i] = temp;
		temp = parent(temp);
		size++;
	}
	indice[size] = 0;
	size++;

	int low, high;
	low = 0;
	high = size -1;
	int pivot = 0;
	int cur = 0;
	int prev = high; 
	while(true){
		pivot = (high+low)/2;
		if (high < low) break;
//cout << "pivot:" << pivot << " prev:"<<prev<< " low:" << low << " high:"<< high<<endl;
		cur = indice[pivot];
		if (array[start] > array[cur]){
			low = pivot + 1;
		} else if (array[start] < array[cur]){
			high = pivot - 1;
		} else {
#if 0
cout << "pa "<< array[parent(indice[pivot])] << " "<<parent(indice[pivot]) 
	<< " "<< pivot << endl;
			if (array[parent(indice[pivot]) < array[start]]){
cout << "aaaaa"<<endl;
				return pivot;
			}
			return pivot +1;
#endif
			break;
		}
		prev = pivot;
	}
	cout << "high:" << high << " low:" << low<<endl;
	cout << " size:" << size << " prev:" << prev << " pivot:"<<pivot<< " idx_prev:" << indice[prev] << " idx_pivot:"<<indice[pivot]<<endl;
cout << array[start] << " " <<array[indice[prev]] << " "<<array[indice[pivot]] << endl;

		if (high > low){
cout << "NORMAL ";
			if (array[parent(indice[pivot])] < array[start]){
				return pivot +1;
			}
			return pivot;
		} else if (high < low){
cout << "ABNORMAL"<<endl;
			if (array[parent(indice[pivot])] < array[start]){
				return pivot +1;
			}
			return pivot;
		} else {
cout << "MARS"<<endl;
			return pivot;
		}
cout <<"STOP"<<endl;
throw 1;

	if (pivot == prev){
cout << "ret_eq:"<<pivot<< endl;
		if (array[start] < array[indice[pivot]]){
			return pivot -1;
		} else if (array[start] > array[indice[pivot]]){
			return pivot +1;
		}
		return pivot;
	} else if (pivot > prev){
		if (array[start] > array[indice[prev]]){
cout << "ret>: PREV"<<pivot<< endl;
			return pivot;
		} else if (array[start] < array[indice[prev]]){
cout << "ret>: PIVOT"<<prev<< endl;
			return prev;
		}
		cout << "RET2 not found\n"; throw 1;
	} else{ // pivot < prev
#if 0
		if (array[start] > array[indice[prev]]){
cout << "ret<: PREV:"<<prev<< endl;
			return prev;
		} else if (array[start] < array[indice[prev]]){
cout << "ret<: PIVOT:"<< pivot<< endl;
			return pivot;
		}
#endif
cout << "ret<:"<<endl;
		if (high > low){
			return prev;
		} else if (high < low){
			return pivot;
		}
		cout << "RET3 not found\n"; throw 1;
	}
	cout << "unreachable\n"; throw 1;
}

void BubbleUp( int *array, int num_values, int start){
	if (num_values <= 0) return;
	int index = binary_branch_less(array, start);
	int it = start;
	int par;

	int acc = 0;
	cout << "count:"<<index <<" parent:";
//	while (it > index){
	it = start;
	for (int i = 0; i < index; i++){
	//while (it >= index){
		par = parent(it);
#if 0
		if (array[start] <= array[par]){
			break;
		}
#endif
	cout << par << ' ';

#if 0
		if (par <= index){
		swap(array, it, par);
cout << "ENN1 ";
cout << "start:" << start;
			cout << " it:"<<it << " par:" << par << " index:"<< index<<endl;
			 break;
		}
#endif
		swap(array, it, par);
		it = par;
acc++;
	}
	cout << endl;
	if (acc != index){
		cout << "COUNT NOT MATCHED!"<<endl;
		throw 2;
	}
	cout << endl;
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

cout << "=--------------= Inserting " << data<<endl;
	array[num_values] = data;
	num_values++;
	BubbleUp(array, num_values, num_values-1);
#if 0
Print();
	if (!integ()){
		cout << "HEAP PROPERTY VIOLATED"<<endl;
		throw 1;
	}
#endif
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
bool MaxHeap::integ(int i){
	int left = left_child(i);
	if (i >= num_values || left >= num_values) return true;
	bool ret =array[i] > array[left] && integ(left);
	if (left + 1 >= num_values) return ret;
	return ret && array[i] > array[left+1] && integ(left+1);
}
#endif
