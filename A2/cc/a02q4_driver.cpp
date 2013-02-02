#include "a02q4b.h"
#include <iostream>
using namespace std;

int main(){
	int array_sz;
	cin >> array_sz;

	int array[array_sz];
	MaxHeap h(array,array_sz);

	for(int i = 0, temp; i < array_sz; i++){
		cin >> temp;
		h.Insert(temp);
	}
}
