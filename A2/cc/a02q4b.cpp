#include "a02q4b.h"
#include "cmath"

int parent(int i){
	return (i - 1) / 2;
}

void swap(int *array, int i, int j){
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

#include <iostream>
using namespace std;
// O(loglog n) comparisons to look for number of ancestors to be swapped
int num_ancestor_to_be_swapped(int *array, int start){
	int indice[start], size = 0, low, high, pivot;
//cout << "---------------\nstart "<< start<<endl;
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

#if 1
	int ret1;
	// O(loglog n) comparisons to look for number of ancestors to be swapped
	while(true){
		pivot = (high+low)/2;
//cout << low << ' '<<high << " "<<pivot<<endl;
		if (high < low) break;
//cout << "pivot:"<< pivot <<" cur:" << indice[pivot] << " a_start:"<<array[start] << " a_cur:"<< array[indice[pivot]] << endl;
		if (array[start] > array[indice[pivot]]){
			low = pivot + 1;
		} else if (array[start] < array[indice[pivot]]){
			high = pivot - 1;
		} else {
			break;
		}
	}

//cout << pivot <<  " " << indice[pivot] << endl;
//cout << "cur:" << indice[pivot] << " a_start:"<<array[start] << " a_cur:"<< array[indice[pivot]] << endl;
	// O(1) for handling boundary case
	if (array[parent(indice[pivot])] < array[start]){
//cout << "RET1"<<endl;
		ret1= pivot + 1;
	} else {
//cout << "RET2"<<endl;
	ret1=pivot;
	}
#if 0
	if (array[parent(indice[pivot])] < array[start]){
		return pivot + 1;
	}
	return pivot;
#endif
#endif

#if 1
	low = pivot = 0;
	if (start == 0) return 0;
	high = (log(start +1)/log(2));
	int cur = start;
	int power;
//cout << high << endl;
	while(true){
#if 0
		pivot = (high+low)/2;
		power = pow(2,pivot);
cout << low << ' '<<high<<endl;
		cur = (start- power +1) / power;
#ifdef NDEBUG
cout << "pivot:" << pivot <<" start:"<<start<< " pow:" << pow(2,pivot)<<" cur:" <<cur << " indice[i]:"<<indice[pivot]<<endl;
assert(cur == indice[pivot]);
//cout << start << " " << pow(2, pivot) << " " <<cur << endl;
#endif
#endif
		pivot = (high+low)/2;
//cout << low << ' '<<high<< " "<<pivot<<endl;
		power = pow(2,pivot);
		cur = (start- power +1) / power;
		if (high < low) break;
//cout << "pivot:"<<pivot<<" cur:" << cur << " a_start:"<<array[start] << " a_cur:"<< array[cur] << endl;
		if (array[start] > array[cur]){
			low = pivot + 1;
		} else if (array[start] < array[cur]){
			high = pivot - 1;
		} else {
			break;
		}
	}
//cout << "par_cur:" <<parent(cur) << " start:" << start << " a_parcur:"<< array[parent(cur)] << " a_start:" << array[start] << endl;
//cout << pivot <<  " " << indice[pivot] << " " << cur<< endl;
//cout << "cur:" << cur << " a_start:"<<array[start] << " a_cur:"<< array[cur] << endl;
int ret;
	if (array[parent(cur)] < array[start]){
		ret = pivot+ 1;
//cout << "1RET "<< ret1 << " NRET:"<<ret << " pivot:"<<pivot<<endl;
if(ret1!=ret){ throw 1;}
		return ret;
	}
//cout << "2RET "<< ret1 << " NRET:"<<pivot<<endl;
if(ret1!=pivot){ throw 1;}
	return pivot;
#endif
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
	//Print();
}
